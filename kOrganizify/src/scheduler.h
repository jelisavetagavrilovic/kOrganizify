// scheduler.h

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QDate>
#include <QTime>
#include <QSet>
#include <z3++.h>
#include "calendar.h"


class Scheduler {

public:
    Scheduler(Calendar *calendar, Calendar *m_basicCalendar);
    ~Scheduler();

    void generateSchedule(const QTime &startOfWorkday, const QTime &endOfWorkday);
    void generateSchedules(QList<Event> freeTime, QList<Event> basicEvents);

private:
    z3::context m_context;
    Calendar *m_calendar;
    Calendar *m_basicCalendar;
    QList<Calendar*> m_generatedSchedules;
    QSet<Event> scheduledEvents;
    Calendar* m_scheduledCalendar;
    QList<Event> m_freeTimeList;
    QList<Event> findFreeTime(Calendar *cal1, int maxTime);

    bool nextPermutation(QList<Event>& events, int size);
    void processSchedule(const QList<Event>& freeTime);
    void generatePermutations(QList<Event>& events, int start, int end, int depth,
                              QList<QList<Event>>& allPermutations);
};

#endif // SCHEDULER_H
