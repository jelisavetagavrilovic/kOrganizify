#include "client.h"
#include "event.h"
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>

Client::Client(QString username, QObject* parent)
    : QObject(parent),
      m_username(username)
{
    m_socket = new QTcpSocket(this);
    makeConnection(QHostAddress::LocalHost);
}

bool Client::makeConnection(QHostAddress::SpecialAddress address) {
    connect(m_socket, &QTcpSocket::readyRead, this, &Client::readFromServer);
    connect(m_socket, &QTcpSocket::disconnected, this, &Client::disconnected);

    m_socket->connectToHost(QHostAddress(address), 12345);
    if (m_socket->waitForConnected(5000)) {
        qDebug() << "Connected to the server.";
    } else {
        qDebug() << "Connection failed. Error:" << m_socket->error();
        return false;
    }
    QJsonObject newClientMessage;
    newClientMessage.insert("title", "new connection");
    newClientMessage.insert("username", m_username);
    QString msg(QJsonDocument(newClientMessage).toJson());
    m_socket->write(msg.toStdString().c_str());
    return m_socket->waitForConnected();
}

void Client::disconnected() {
    delete m_socket;
    QCoreApplication::quit();
}

/// Server can receive one of the following messages:
/// 1. new connection
/// 2. disconnected
/// 3. syncRequest
/// 4. rejectSync
/// 5. new sync event
/// 6. agreed sync
void Client::readFromServer() {
    QString message = m_socket->readAll();
    QJsonObject doc = QJsonDocument::fromJson(message.toUtf8()).object();
    QString title = doc.value("title").toString();
    qDebug()<< "client received " << title;
    if(title == "new connection") {
        m_friends.append(doc.value("username").toString());
        emit newUserLoggedIn(doc.value("username").toString());
    }
    else if(title == "disconnected") {
        m_friends.removeOne(doc.value("username").toString());
        emit disconnectedUser(doc.value("username").toString());
    }
    else if(title == "syncRequest") {
        QString from = doc.value("fromUsername").toString();
        QString eventTitle = doc.value("titleEvent").toString();
        int duration = doc.value("duration").toInt();

        // emit signal to open syncronizationwindow I guess
        emit showSyncWindow(from ,eventTitle, duration);
        // and do something with the response

        // that response will emit a signal which will be received in a slot in this class
        // slot implemented
    }
    else if(title == "rejectSync") {
        // emit signal that our request was declined
        emit syncRequestDenied();
        // probably just a pop-up
        // that's it
    }
    else if(title == "new sync event") {
        // emit signal to pop-up a new window or something
        Event event;
        event.setTitle(doc.value("eventTitle").toString());
        event.setStartTime(QDateTime::fromString(doc.value("startTime").toString(), Qt::ISODate));

        // show event in some window somehow

        // record response, probably singal-slot? slot implemented
    }
    else if(title == "agreed sync") {
        QDateTime startTime = QDateTime::fromString(doc.value("startTime").toString(), Qt::ISODate);
        QDateTime endTime = QDateTime::fromString(doc.value("endTime").toString(), Qt::ISODate);
        QString title = doc.value("eventTitle").toString();

        emit syncSuccess(startTime, endTime, title);
        // should be caught somewhere!
    }
}

void Client::sendMessage(QString x) {
    QByteArray toSend = QByteArray::fromStdString(x.toStdString());

    m_socket->write(toSend);
}

void Client::syncResponse(bool response, Calendar cal) const {
    if(!response) {
        QJsonObject newClientMessage;
        newClientMessage.insert("title", "rejectSync");
        newClientMessage.insert("username", m_username);
        QString msg(QJsonDocument(newClientMessage).toJson());
        m_socket->write(msg.toStdString().c_str());
    }
    else {
        QJsonArray jsonArray;
        for (const Event &event : cal.getEvents()) {
            QJsonObject jsonObject;
            jsonObject["title"] = event.getTitle();
            jsonObject["startTime"] = event.getStartTime().toString(Qt::ISODate);
            jsonObject["endTime"] = event.getEndTime().toString(Qt::ISODate);
            jsonObject["description"] = event.getDescription();
            jsonObject["location"] = event.getLocation();

            jsonArray.append(jsonObject);
        }

        QJsonDocument doc;
        doc.setArray(jsonArray);
        QString dataToString(doc.toJson());

        QJsonObject newClientMessage;
        newClientMessage.insert("title", "acceptSync");
        newClientMessage.insert("username", m_username);
        newClientMessage.insert("events", dataToString);
        QString msg(QJsonDocument(newClientMessage).toJson());
        m_socket->write(msg.toStdString().c_str());
    }
}

void Client::eventResponse(bool response) {
    QJsonObject responseMsg;
    responseMsg.insert("title", "eventResponse");
    responseMsg.insert("answer", response? "yes" : "no");
    QString msg(QJsonDocument(responseMsg).toJson());

    m_socket->write(msg.toStdString().c_str());
}

void Client::syncRequest(QString from, QString to, QString titleEvent, int duration) {
    QJsonObject responseMsg;
    responseMsg.insert("title", "syncRequest");
    responseMsg.insert("fromUsername", from);
    responseMsg.insert("toUsername", to);
    responseMsg.insert("titleEvent", titleEvent);
    responseMsg.insert("duration", QString::number(duration));
    QString msg(QJsonDocument(responseMsg).toJson());

    m_socket->write(msg.toStdString().c_str());
}

// not tested :)
