#include "client.h"
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
    return m_socket->waitForConnected();}

void Client::disconnected() {
    delete m_socket;
    QCoreApplication::quit();
}

void Client::readFromServer() {
    QString message = m_socket->readAll();
    QJsonObject doc = QJsonDocument::fromJson(message.toUtf8()).object();
    // foreach(const QString& key, doc.keys()) {
    //     QJsonValue value = doc.value(key);
    //     qDebug() << "Key = " << key << ", Value = " << value.toString();
    // }
    // ...
    QString title = doc.value("title").toString();
    qDebug() << title;
    if(title == "new connection") {
        m_friends.append(doc.value("username").toString());
        emit newUserLoggedIn(doc.value("username").toString());
    }
    else if(title == "disconnected") {
        m_friends.removeOne(doc.value("username").toString());
        emit disconnectedUser(doc.value("username").toString());
    }
}

void Client::sendMessage(QString x) {
    QByteArray toSend = QByteArray::fromStdString(x.toStdString());

    m_socket->write(toSend);
}
