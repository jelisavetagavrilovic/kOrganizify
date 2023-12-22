#ifndef CALENDAR_H
#define CALENDAR_H

#include <QList>
#include "event.h"

class Calendar
{
public:
    Calendar();
    Calendar(const Calendar &other);

    void addEvent(const Event &event);
    void removeEvent(const Event &event);
    void updateEvent(const Event &event);
    QList<Event> getEvents() const;

private:
    QList<Event> m_events;
};

#endif // CALENDAR_H
