#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject
{
public:
    Server(QObject* parent = nullptr);
public slots:
    void newConnection();
    void readFromClient() const;
    void disconnection();
private:
    QTcpServer* m_server;
    QList<QTcpSocket*> m_clients;
};

#endif // SERVER_H
