#include "basicevent.h"

BasicEvent::BasicEvent() {}

QString BasicEvent::getTitle() const {
    return m_title;
}
void BasicEvent::setTitle(const QString &title) {
    m_title = title;
}

// Getter and Setter for m_duration
double BasicEvent::getDuration() const {
    return m_duration;
}
void BasicEvent::setDuration(const double duration) {
    m_duration = duration;
}
