#include "calendar.h"

void Calendar::addEvent(const Eventgit &event){
    m_events.append(event);
}

void Calendar::removeEvenet(const Event &event){
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
