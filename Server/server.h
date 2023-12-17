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
    void sendToClient(const QString &username, const QString &message) const;
private:
    QTcpServer* m_server;
    QHash<QString, QTcpSocket*> m_clients;
};

#endif // SERVER_H
