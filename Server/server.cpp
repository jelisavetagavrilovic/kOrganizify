#include "server.h"
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include "../kOrganizify/src/calendar.h"
#include "../kOrganizify/src/event.h"

Server::Server(QObject* parent)
    : QObject(parent) {
    m_server = new QTcpServer(this);

    connect(m_server, &QTcpServer::newConnection, this, &Server::newConnection);
    m_server->listen(QHostAddress::LocalHost, 12345);
}


void Server::newConnection() {
    QTcpSocket* newClient = m_server->nextPendingConnection();

    if(newClient) {
        qDebug() << "New client connect";
        connect(newClient, &QTcpSocket::readyRead, this, &Server::readFromClient);
        connect(newClient, &QTcpSocket::disconnected, this, &Server::disconnection);
    }
}

/// Server can receive one of the following messages:
/// 1. new connection
/// 2. syncRequest
/// 3. acceptSync
/// 4. rejectSync
/// 5. eventResponse
void Server::readFromClient() {
    QTcpSocket* senderClient = dynamic_cast<QTcpSocket*>(sender());

    QString dataRead = QString(senderClient->readAll());
    QJsonObject doc = QJsonDocument::fromJson(dataRead.toUtf8()).object();
    QString title = doc.value("title").toString();
    if(title == "new connection"){
        for (auto i = m_clients.cbegin(), end = m_clients.cend(); i != end; ++i){
            QJsonObject newClientMessage;
            newClientMessage.insert("title", "new connection");
            newClientMessage.insert("username", i.key());
            QString msg(QJsonDocument(newClientMessage).toJson());
            senderClient->write(msg.toStdString().c_str());
            senderClient->flush();
            QTime dieTime = QTime::currentTime().addMSecs( 100 );
            while( QTime::currentTime() < dieTime );
        }
        m_clients.insert(doc.value("username").toString(), senderClient);
        multiCast(doc.value("username").toString());
    }
    else if (title == "syncRequest") { // when a new sync request is being made
        // receives userCalendar, event to sync, with who
        QJsonObject newClientMessage;
        newClientMessage.insert("title", "syncRequest");
        newClientMessage.insert("fromUsername", doc.value("fromUsername").toString());
        newClientMessage.insert("toUsername", doc.value("toUsername").toString());
        newClientMessage.insert("titleEvent", doc.value("titleEvent").toString());
        m_syncEventTitle = doc.value("titleEvent").toString();
        newClientMessage.insert("duration", doc.value("duration").toString());

        m_syncEventDuration = doc.value("duration").toString().toInt();

        QJsonArray jsonArray = doc.value("events").toArray();
        newClientMessage.insert("events", jsonArray);

        Calendar *cal = new Calendar();
        for (const QJsonValue &jv : jsonArray) {
            Event event;
            event.setTitle(jv["title"].toString());
            event.setStartTime(QDateTime::fromString(jv["startTime"].toString(), Qt::ISODate));
            event.setEndTime(QDateTime::fromString(jv["endTime"].toString(), Qt::ISODate));
            event.setDescription(jv["description"].toString());
            event.setLocation(jv["location"].toString());

            cal->addEvent(event);
        }
        m_calendar.insert(doc.value("fromUsername").toString(),cal);

        QString msg(QJsonDocument(newClientMessage).toJson());
        sendToClient(doc.value("toUsername").toString(), msg);
    }
    else if (title == "acceptSync") { // accepting initial sync request
        // receives their calendar, event title, total time for event
        QJsonArray jsonArray = doc.value("events").toArray();

        Calendar *cal = new Calendar();
        for (const QJsonValue &jv : jsonArray) {
            Event event;
            event.setTitle(jv["title"].toString());
            event.setStartTime(QDateTime::fromString(jv["startTime"].toString(), Qt::ISODate));
            event.setEndTime(QDateTime::fromString(jv["endTime"].toString(), Qt::ISODate));
            event.setDescription(jv["description"].toString());
            event.setLocation(jv["location"].toString());
            cal->addEvent(event);
        }

        m_calendar.insert(doc.value("fromUsername").toString(),cal);

        m_user1 = doc.value("fromUsername").toString();
        m_user2 = doc.value("toUsername").toString();
        Calendar* cal1 = m_calendar[m_user1];
        Calendar* cal2 = m_calendar[m_user2];

        m_currentSyncEvents = findFreeTime(cal1,cal2,m_syncEventDuration);
        m_numResponses = 0;

        sendEvent(0);
    }
    else if(title == "rejectSync") {
        QString from = doc.value("fromUsername").toString();
        QString to = doc.value("toUsername").toString();

        QJsonObject newClientMessage;
        newClientMessage.insert("title", "rejectSync");
        newClientMessage.insert("fromUsername", from);
        newClientMessage.insert("toUsername", to);
        QString msg(QJsonDocument(newClientMessage).toJson());
        sendToClient(to, msg);
    }
    else if(title == "eventResponse") {
        ++m_numResponses;
        QString response = doc.value("answer").toString();

        if(m_numResponses % 2 == 0) {
            if (m_lastResponse == "no" || response == "no") {
                sendEvent(m_numResponses / 2);
            }
            else {
                sendFinalEvent(m_numResponses / 2);
            }
        }
        else {
            m_lastResponse = response;
        }
    }
}

void Server::sendEvent(int ind) const {
    if(m_currentSyncEvents.size() == ind) {
        sendNoMore();
    }

    QJsonObject newSyncEventMsg;
    newSyncEventMsg.insert("title", "new sync event");
    newSyncEventMsg.insert("from", m_user2);
    newSyncEventMsg.insert("startTime", m_currentSyncEvents[ind].getStartTime().toString());
    newSyncEventMsg.insert("eventTitle", m_currentSyncEvents[ind].getTitle());
    QString msg(QJsonDocument(newSyncEventMsg).toJson());

    m_clients[m_user1]->write(msg.toStdString().c_str());
    m_clients[m_user1]->flush();
    newSyncEventMsg.insert("from", m_user2);
    QString msg1(QJsonDocument(newSyncEventMsg).toJson());
    m_clients[m_user2]->write(msg1.toStdString().c_str());
    m_clients[m_user2]->flush();
}

void Server::sendFinalEvent(int ind) const {
    QJsonObject newSyncEventMsg;
    newSyncEventMsg.insert("title", "agreed sync");
    newSyncEventMsg.insert("from", m_user2);
    newSyncEventMsg.insert("startTime", m_currentSyncEvents[ind].getStartTime().toString());
    newSyncEventMsg.insert("endTime", m_currentSyncEvents[ind].getEndTime().toString());
    newSyncEventMsg.insert("eventTitle", m_currentSyncEvents[ind].getTitle());

    QString msg(QJsonDocument(newSyncEventMsg).toJson());

    m_clients[m_user1]->write(msg.toStdString().c_str());
    m_clients[m_user1]->flush();

    newSyncEventMsg.insert("from", m_user2);
    QString msg1(QJsonDocument(newSyncEventMsg).toJson());
    m_clients[m_user2]->write(msg1.toStdString().c_str());
    m_clients[m_user2]->flush();
}

void Server::sendToClient(const QString &username, const QString &message) const {
    if(m_clients.contains(username)) {
        m_clients[username]->write(message.toStdString().c_str());
        m_clients[username]->flush();
    }
    else {
        qDebug() << "No such user exists!";
    }
}

QString Server::getUsername(QTcpSocket* socket) {
    for (auto i = m_clients.cbegin(), end = m_clients.cend(); i != end; ++i){
        if (i.value() == socket) {
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
            i.value()->write(msg.toStdString().c_str());
            i.value()->flush();
        }
    }
}

void Server::multiCast(const QString &username) const {
    for (auto i = m_clients.cbegin(), end = m_clients.cend(); i != end; ++i){
        if (i.key() != username) {
            QJsonObject newClientMessage;
            newClientMessage.insert("title", "new connection");
            newClientMessage.insert("username", username);
            QString msg(QJsonDocument(newClientMessage).toJson());
            i.value()->write(msg.toStdString().c_str());
            i.value()->flush();
        }
    }
}

void Server::sendNoMore() const {
    QJsonObject noMoreEventsMsg;
    noMoreEventsMsg.insert("title", "no more events");
    noMoreEventsMsg.insert("from", m_user2);
    QString msg(QJsonDocument(noMoreEventsMsg).toJson());

    m_clients[m_user1]->write(msg.toStdString().c_str());
    m_clients[m_user1]->flush();

    noMoreEventsMsg.insert("from", m_user2);
    QString msg1(QJsonDocument(noMoreEventsMsg).toJson());
    m_clients[m_user2]->write(msg1.toStdString().c_str());
    m_clients[m_user2]->flush();
}

QList<Event> Server::findFreeTime(Calendar *cal1, Calendar *cal2, int maxTime) const {
    QList<Event> freeTimeSlots;
    QList<Event> allEvents;

    allEvents.append(cal1->getEvents());
    allEvents.append(cal2->getEvents());

    QSet<Event> uniqueEvents;
    for (const auto &event : allEvents) {
        uniqueEvents.insert(event);
    }

    // converting the QSet back to a QList and sorting
    allEvents = QList<Event>(uniqueEvents.begin(), uniqueEvents.end());
    std::sort(allEvents.begin(), allEvents.end(), [](const Event &a, const Event &b) {
        return a.getStartTime() < b.getStartTime();
    });

    auto roundUpToNextHour = [](const QTime &time) {
        return (time.minute() > 0 || time.second() > 0 || time.msec() > 0) ? QTime(time.hour() + 1, 0) : time;
    };

    auto isBetween12pmAnd8am = [](const QTime& currentHour) {
        return (currentHour >= QTime(0, 0) && currentHour < QTime(12, 0)) || (currentHour >= QTime(12, 0) && currentHour <= QTime(8, 0));
    };

    QDate currentDay = QDateTime::currentDateTime().date();
    QTime currentHour = QDateTime::currentDateTime().time();
    QDate lastDayOfWeek = currentDay.addDays(7 - currentDay.dayOfWeek());

    for (QDate currentDate = currentDay; currentDate <= lastDayOfWeek; currentDate = currentDate.addDays(1)) {
        QTime startHour = (currentDate == currentDay) ? roundUpToNextHour(currentHour) : QTime(8, 0);
        QTime endHour = QTime(23, 59, 59);

        if(isBetween12pmAnd8am(startHour))
            startHour = QTime(8, 0);

        for (QTime currentHour = startHour; currentHour < endHour; currentHour = currentHour.addSecs(3600)) {
            QTime endTime = endHour.addSecs(-maxTime * 3600);

            if (currentHour <= endTime) {
                Event* newEvent = new Event();
                newEvent->setStartTime(QDateTime(currentDate, currentHour));
                newEvent->setEndTime(QDateTime(currentDate, currentHour.addSecs(maxTime * 3600)));
                newEvent->setTitle(m_syncEventTitle);

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
