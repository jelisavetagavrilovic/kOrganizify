#include "server.h"
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>

Server::Server(QObject* parent)
    : QObject(parent) {
    m_server = new QTcpServer(this);

    connect(m_server, &QTcpServer::newConnection, this, &Server::newConnection);
    m_server->listen(QHostAddress::LocalHost, 12345);
}


void Server::newConnection() {
    QTcpSocket* newClient = m_server->nextPendingConnection();

    if(newClient) {
        // QString clientName = newClient->readAll();
        // m_clients.insert(clientName, newClient);


        // multiCast(clientName);
        qDebug() << "New client connect";
        connect(newClient, &QTcpSocket::readyRead, this, &Server::readFromClient);
        connect(newClient, &QTcpSocket::disconnected, this, &Server::disconnection);
    }
}

void Server::readFromClient() {
    QTcpSocket* senderClient = dynamic_cast<QTcpSocket*>(sender());

    QString dataRead = QString(senderClient->readAll());
    QJsonObject doc = QJsonDocument::fromJson(dataRead.toUtf8()).object();
    QString title = doc.value("title").toString();
    qDebug() << title;
    if(title == "new connection"){
        for (auto i = m_clients.cbegin(), end = m_clients.cend(); i != end; ++i){
            QJsonObject newClientMessage;
            newClientMessage.insert("title", "new connection");
            newClientMessage.insert("username", i.key());

            QJsonDocument x(newClientMessage);

            QString msg(QJsonDocument(newClientMessage).toJson());
            senderClient->write(msg.toStdString().c_str());

        }
        m_clients.insert(doc.value("username").toString(), senderClient);
        multiCast(doc.value("username").toString());
    }


    // parse dataRead and send to who it is supposed to go to
}

void Server::sendToClient(const QString &username, const QString &message) const {
    if(m_clients.contains(username)) {
        m_clients[username]->write(message.toStdString().c_str());
    }
    else {
        qDebug() << "No such user exists!";
    }
}

QString Server::getUsername(QTcpSocket* socket) {
    for (auto i = m_clients.cbegin(), end = m_clients.cend(); i != end; ++i){
        if (i.value() == socket){
            return i.key();
        }
    }
    return nullptr;
}

void Server::disconnection() {
    QTcpSocket* disconnectedClient = dynamic_cast<QTcpSocket*>(sender());
    QString username = getUsername(disconnectedClient);
    m_clients.remove(username);
    for (auto i = m_clients.cbegin(), end = m_clients.cend(); i != end; ++i){
        if (i.value() != disconnectedClient) {
            QJsonObject newClientMessage;
            newClientMessage.insert("title", "disconnected");
            newClientMessage.insert("username", username);

            QString msg(QJsonDocument(newClientMessage).toJson());
            qDebug() << msg << " is sent to " << i.key();
            i.value()->write(msg.toStdString().c_str());
        }
    }
}

void Server::multiCast(const QString &username) const {
    for (auto i = m_clients.cbegin(), end = m_clients.cend(); i != end; ++i){
        if (i.key() != username){
            qDebug() << " hey " << i.key() <<" new user: " << username;
            QJsonObject newClientMessage;
            newClientMessage.insert("title", "new connection");
            newClientMessage.insert("username", username);

            QString msg(QJsonDocument(newClientMessage).toJson());
            i.value()->write(msg.toStdString().c_str());
        }
    }
}

QList<Event> Server::findFreeTime(Calendar cal1, Calendar cal2, int maxTime) const {
    QList<Event> freeTimeSlots;

    QList<Event> allEvents;
    allEvents.append(cal1.getEvents());
    allEvents.append(cal2.getEvents());

    QSet<Event> uniqueEvents;
    for (const auto &event : allEvents) {
        uniqueEvents.insert(event);
    }

    // converting the QSet back to a QList and sorting
    allEvents = QList<Event>(uniqueEvents.begin(), uniqueEvents.end());
    std::sort(allEvents.begin(), allEvents.end(), [](const Event &a, const Event &b) {
        return a.getStartTime() < b.getStartTime();
    });

    QDate currentDay = QDateTime::currentDateTime().date();
    QTime currentHour = QDateTime::currentDateTime().time();
    QDate lastDayOfWeek = currentDay.addDays(7 - currentDay.dayOfWeek());

    for (QDate currentDate = currentDay; currentDate <= lastDayOfWeek; currentDate = currentDate.addDays(1)) {

        QTime startHour = (currentDate == currentDay) ? currentHour : QTime(8, 0);
        QTime endHour = QTime(23, 59, 59);

        for (QTime currentHour = startHour; currentHour < endHour; currentHour = currentHour.addSecs(3600)) {
            QTime endTime = endHour.addSecs(-maxTime * 3600);

            if (currentHour <= endTime) {
                Event* newEvent = new Event();
                newEvent->setStartTime(QDateTime(currentDate, currentHour));
                newEvent->setEndTime(QDateTime(currentDate, currentHour.addSecs(maxTime * 3600)));
                newEvent->setTitle("Free time");

                freeTimeSlots.append(*newEvent);
            }

            if (currentHour.hour() == 23)
                break;
        }
    }

    // removing free time slots that overlap with existing events
    auto it = std::remove_if(freeTimeSlots.begin(), freeTimeSlots.end(), [&](const Event &freeTimeSlot) {
        for (const auto &existingEvent : allEvents) {
            if (freeTimeSlot.getStartTime() < existingEvent.getEndTime() &&
                freeTimeSlot.getEndTime() > existingEvent.getStartTime()) {
                return true;  // ovelapping, remove this free time slot
            }
        }
        return false;
    });

    freeTimeSlots.erase(it, freeTimeSlots.end());

    return freeTimeSlots;
}
