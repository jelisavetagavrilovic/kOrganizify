#include "notifications.h"

Notifications::Notifications(Calendar* calendar) : calendar(calendar), QObject(nullptr) {
    //provera svaki minut
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Notifications::checkEvents);
    timer->start(60000);
}

void Notifications::checkEvents() {
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // provera dal je tu nesto u pola sata
    for (const Event& event : calendar->getEvents()) {
        int secs = currentDateTime.secsTo(event.getStartTime()) - 30*60;

        QTimer::singleShot(secs*1000, this, [event]() {
            showEvent(event);
        });

//        qDebug() << "markic";
    }
}

void Notifications::showEvent(const Event& event) {
    NotificationsWindow* notif = new NotificationsWindow(nullptr);
    notif->updateWindow(event.getTitle(), event.getStartTime().toString("yyyy-MM-dd hh:mm:ss"));
}
