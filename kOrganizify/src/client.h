#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QObject* parent = nullptr);
public slots:
    void readFromServer();
    void disconnected();
    void sendMessage(QString message);
private:
    QTcpSocket* m_socket;
    QString m_username;
    bool makeConnection(QHostAddress::SpecialAddress adresa);
};

#endif // CLIENT_H
