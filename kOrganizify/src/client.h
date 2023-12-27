#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "calendar.h"

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
    void syncResponse(bool response, QString username, QString friendName, int duration, Calendar cal = {}) const;
    void eventResponse(bool response);
    void syncRequest(QString from, QString to, QString titleEvent, int duration, Calendar calendar);
private:
    void sendMessage(QString message);
    QTcpSocket* m_socket;
    bool makeConnection(QHostAddress::SpecialAddress address);
signals:
    void newUserLoggedIn(const QString& username);
    void disconnectedUser(const QString& username);
    void showSyncWindow(QString from, QString eventTitle, int duration);
    void syncRequestDenied();
    void syncSuccess(QDateTime startTime,QDateTime endTime, QString eventTitle);
    void newEventSync(QString eventTitle, QString startTime);
};

#endif // CLIENT_H
