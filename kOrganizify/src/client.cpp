#include "client.h"
#include <QEventLoop>

Client::Client(QObject* parent)
    : QObject(parent)
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

    m_socket->write(m_username.toStdString().c_str());

    return m_socket->waitForConnected();
}

void Client::disconnected() {
    delete m_socket;
}

void Client::readFromServer() {
    QString message = m_socket->readAll();
    // ...
}

void Client::sendMessage(QString x){
    QByteArray toSend = QByteArray::fromStdString(x.toStdString());

    m_socket->write(toSend);
}
