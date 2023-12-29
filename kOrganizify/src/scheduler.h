#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "calendar.h"
#include "basicevent.h"
#include "event.h"

//#include <algorithm>
//#include <vector>

#include <QList>
#include <QDate>
#include <QTime>
#include <QSet>

class Scheduler {

public:
    Scheduler(Calendar *calendar, Calendar *m_basicCalendar);
    ~Scheduler();

    void generateSchedule(const QTime &startOfWorkday, const QTime &endOfWorkday);

private slots:
    Calendar* generateSchedules(QList<Event> freeTime);
    bool nextPermutation(QList<Event>& events, int size);
    void generatePermutations(QList<Event>& events, int start, int end, int depth,
                              QList<QList<Event>>& allPermutations);

private:
    Calendar *m_calendar;
    Calendar *m_basicCalendar;
    QList<Calendar*> m_generatedSchedules;
//    QSet<Event> scheduledEvents;
    Calendar* m_scheduledCalendar;
    QList<Event> m_freeTimeList;
    QList<Event> findFreeTime(Calendar *cal1, int maxTime);
    QList<BasicEvent> m_AllEvents;
};

#endif // SCHEDULER_H
