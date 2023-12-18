#include "client.h"
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>

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
    qDebug()<<"saljem..." << msg;
    m_socket->write(msg.toStdString().c_str());
    return m_socket->waitForConnected();
    // qDebug() << msg;

}

void Client::disconnected() {
    delete m_socket;
}

// void Client::readFromServer() {
//     QString message = m_socket->readAll();

//     if (message.startsWith("NewUserLoggedIn:")) {
//         QString newUsername = message.mid(17); // "NewUserLoggedIn:" je tacan prefix
//         emit newUserLoggedIn(newUsername);
//     }
// }

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
    if(title == "new connection"){
        m_friends.append(doc.value("username").toString());
        emit newUserLoggedIn(doc.value("username").toString());
    }
}

void Client::sendMessage(QString x){
    QByteArray toSend = QByteArray::fromStdString(x.toStdString());

    m_socket->write(toSend);
}
