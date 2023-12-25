#include "basicevent.h"

BasicEvent::BasicEvent() {}

QString BasicEvent::getTitle() const {
    return m_title;
}
void BasicEvent::setTitle(const QString &title) {
    m_title = title;
}

// Getter and Setter for m_duration
int BasicEvent::getDuration() const {
    return m_duration;
}
void BasicEvent::setDuration(const int duration) {
    m_duration = duration;
}

void BasicEvent::deleteString() {
    m_title.clear();
}
