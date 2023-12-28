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
    Scheduler(Calendar *calendar, Calendar *basicCalendar);
    ~Scheduler();

    void generateSchedule(const QDate &startDate, const QDate &endDate, int workMinutesPerDay,
                          const QTime &startOfWorkday, const QTime &endOfWorkday, int maxSchedules);
    // void generateSchedule(const QDate &startDate, const QDate &endDate, int workMinutesPerDay,
    //                       const QTime &startOfWorkday, const QTime &endOfWorkday);




    // void addEventToSchedule(const Event &event);

    QList<Calendar*> getGeneratedSchedules() const;

private:
    z3::context m_context;
    Calendar *m_calendar;
    Calendar *m_basicCalendar;
    QList<Calendar*> m_generatedSchedules;
    QSet<int> scheduledEvents;
    Calendar* m_scheduledCalendar;

    bool isTimeSlotAvailable(const QDateTime &dateTime, int duration, int workMinutesPerDay,
                             const QTime &startOfWorkday, const QTime &endOfWorkday) const;

    void addGeneratedSchedule(Calendar *schedule);
};


#endif // SCHEDULER_H
