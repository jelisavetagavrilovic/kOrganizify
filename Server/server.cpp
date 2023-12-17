#include "server.h"
#include <QString>

Server::Server(QObject* parent)
    : QObject(parent) {
    m_server = new QTcpServer(this);

    connect(m_server, &QTcpServer::newConnection, this, &Server::newConnection);
    m_server->listen(QHostAddress::LocalHost, 12345);
}


void Server::newConnection() {
    QTcpSocket* newClient = m_server->nextPendingConnection();

    if(newClient) {
        if(!newClient->waitForReadyRead()){
            qDebug() << "New client couldn't connect";
            delete newClient;
            return;
        }

        QString clientName = newClient->readAll();
        m_clients.insert(clientName, newClient);

        connect(newClient, &QTcpSocket::readyRead, this, &Server::readFromClient);
        connect(newClient, &QTcpSocket::disconnected, this, &Server::disconnection);
    }
}

void Server::readFromClient() const {
    QTcpSocket* senderClient = dynamic_cast<QTcpSocket*>(sender());

    QString dataRead = QString(senderClient->readAll());

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

void Server::disconnection() {
    QTcpSocket* disconnectedClient = dynamic_cast<QTcpSocket*>(sender());
    for (auto i = m_clients.cbegin(), end = m_clients.cend(); i != end; ++i){
        if (i.value() == disconnectedClient){
            m_clients.remove(i.key());
            break;
        }
    }
}





