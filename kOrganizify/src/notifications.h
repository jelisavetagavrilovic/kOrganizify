// notifications.h
#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <QObject>
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>

#include "calendar.h"
#include "notificationswindow.h"

class Notifications : public QObject {
    Q_OBJECT
public:
    Notifications(Calendar* calendar);
    void checkEvents();

private slots:
    static void showEvent(const Event& event);

private:
    Calendar* calendar;
    QTimer* timer;

};

#endif // NOTIFICATIONS_H
