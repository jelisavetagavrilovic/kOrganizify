#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "../kOrganizify/src/event.h"
#include "../kOrganizify/src/calendar.h"


class Server : public QObject
{
public:
    Server(QObject* parent = nullptr);
public slots:
    void newConnection();
    void readFromClient();
    void disconnection();
    void sendToClient(const QString &username, const QString &message) const;
private:
    QString getUsername(QTcpSocket* socket);
    QTcpServer* m_server;
    QHash<QString, QTcpSocket*> m_clients;
    void multiCast(const QString &username) const;
    QList<Event> findFreeTime(Calendar cal1, Calendar cal2, int maxTime) const;
};

#endif // SERVER_H
