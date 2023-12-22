#include "calendar.h"

Calendar::Calendar(){}

Calendar::Calendar(const Calendar &other){
    m_events = other.m_events;
}

void Calendar::addEvent(const Event &event){
    m_events.append(event);
}

void Calendar::removeEvent(const Event &event){
    m_events.removeOne(event);
}

void Calendar::updateEvent(const Event &event){
    int index = m_events.indexOf(event);
    if (index != -1){
        m_events[index] = event;
    }
}

QList<Event> Calendar::getEvents() const {
    return m_events;
}
