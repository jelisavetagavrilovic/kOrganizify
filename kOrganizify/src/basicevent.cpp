#include "basicevent.h"

BasicEvent::BasicEvent() = default;

auto BasicEvent::getTitle() const -> QString {
    return m_title;
}
void BasicEvent::setTitle(const QString &title) {
    m_title = title;
}

auto BasicEvent::getDuration() const -> int {
    return m_duration;
}
void BasicEvent::setDuration(const int duration) {
    m_duration = duration;
}

void BasicEvent::deleteString() {
    m_title.clear();
}

auto BasicEvent::isValidate() const -> bool {
    return (m_title != "" && m_duration > 0);
}

auto BasicEvent::operator==(const BasicEvent &other) const -> bool {
    return (m_title == other.m_title && m_duration == other.m_duration);
}
