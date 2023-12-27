#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
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
    QList<Event> findFreeTime(Calendar* cal1, Calendar* cal2, int maxTime) const;
    QString getUsername(QTcpSocket* socket);
    QTcpServer* m_server;
    QHash<QString, QTcpSocket*> m_clients;
    QHash<QString, Calendar*> m_calendar;
    void multiCast(const QString &username) const;
    QList<Event> m_currentSyncEvents;
    QString m_user1, m_user2;
    QString m_lastResponse; //yes or no
    QString m_syncEventTitle;
    int m_syncEventDuration;
    int m_numResponses;
    void sendEvent(int ind) const;
    void sendFinalEvent(int ind) const;
    void sendNoMore() const;
};

#endif // SERVER_H
