#include "notifications.h"

Notifications::Notifications(Calendar* calendar) :
    m_calendar(calendar)
    , QObject(nullptr)
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Notifications::checkEvents);
    m_timer->start(60000);
}

void Notifications::checkEvents() {
    QDateTime currentDateTime = QDateTime::currentDateTime();

    for (const Event& event : m_calendar->getEvents()) {
        int secs = currentDateTime.secsTo(event.getStartTime());
        if(secs >= 29*60 && secs <= 30*60 && m_enabled)
            showEvent(event);
    }
}

void Notifications::showEvent(const Event& event) {
    NotificationsWindow* notif = new NotificationsWindow(nullptr);
    notif->updateWindow(event.getTitle(), event.getStartTime().toString("yyyy-MM-dd hh:mm:ss"));
}

void Notifications::enabledNotifications(const bool enabled) {
    m_enabled = enabled;
}
