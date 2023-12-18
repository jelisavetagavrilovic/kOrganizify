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

        // qDebug() <<"povezan user " << clientName;

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





