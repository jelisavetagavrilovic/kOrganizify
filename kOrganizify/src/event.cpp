#include "event.h"

Event::Event() : priority(CustomEventPriority::NoPriority){

}

QString Event::getTitle() const {
    return m_title;
}

void Event::setTitle(const QString &title) {
    this->m_title = title;
}

QDateTime Event::getStartTime() const {
    return m_startTime;
}

void Event::setStartTime(const QDateTime &startTime) {
    this->m_startTime = startTime;
}

QDateTime Event::getEndTime() const {
    return m_endTime;
}

void Event::setEndTime(const QDateTime &endTime) {
    this->m_endTime = endTime;
}

QString Event::getDescription() const {
    return m_description;
}

void Event::setDescription(const QString &description) {
    this->m_description = description;
}

QString Event::getLocation() const {
    return m_location;
}

void Event::setLocation(const QString &location) {
    this->m_location = location;
}

CustomEventPriority Event::getPriority() const {
    return priority;
}

void Event::setPriority(CustomEventPriority priority){
    this->priority = priority;
}

bool Event::operator==(const Event &other) const {
    return (
        m_title == other.m_title &&
        m_startTime == other.m_startTime &&
        m_endTime == other.m_endTime &&
        m_description == other.m_description &&
        m_location == other.m_location
        );
}
