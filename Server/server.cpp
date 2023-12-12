#include "server.h"

Server::Server(QObject* parent)
    : QObject(parent) {
    m_server = new QTcpServer(this);

    connect(m_server, &QTcpServer::newConnection, this, &Server::newConnection);
    m_server->listen(QHostAddress::LocalHost, 12345);
}

void Server::newConnection() {
    QTcpSocket* newClient = m_server->nextPendingConnection();

    if(newClient) {
        m_clients.append(newClient);

        QString x = "Client " + QString::number(m_clients.size());
        newClient->write(x.toStdString().c_str());

        connect(newClient, &QTcpSocket::readyRead, this, &Server::readFromClient);
        connect(newClient, &QTcpSocket::disconnected, this, &Server::disconnection);
    }
}

void Server::readFromClient() const {
    QTcpSocket* senderClient = dynamic_cast<QTcpSocket*>(sender());

    QByteArray dataRead = senderClient->readAll();
    for (auto *client : m_clients){
        client->write(dataRead);
    }
}

void Server::disconnection() {
    QTcpSocket* disconnectedClient = dynamic_cast<QTcpSocket*>(sender());
    m_clients.removeOne(disconnectedClient);
}





