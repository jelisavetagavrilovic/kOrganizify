#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QString username, QObject* parent = nullptr);
    QString m_username;
    QList<QString> m_friends;
public slots:
    void readFromServer();
    void disconnected();
    void sendMessage(QString message);
private:
    QTcpSocket* m_socket;
    bool makeConnection(QHostAddress::SpecialAddress address);
signals:
    void newUserLoggedIn(const QString& username);
    void disconnectedUser(const QString& username);
};

#endif // CLIENT_H
