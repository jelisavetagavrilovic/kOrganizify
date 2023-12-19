#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include "calendar.h"
#include "event.h"

#include <QSet>

class Synchronization
{
public:
    static QList<Event> findFreeTime(const Calendar& cal1, const Calendar& cal2, int maxTime);

};

#endif // SYNCHRONIZATION_H
