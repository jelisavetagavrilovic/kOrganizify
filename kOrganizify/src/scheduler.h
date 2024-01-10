#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "basicevent.h"
#include "calendar.h"
#include "event.h"

#include <QDate>
#include <QList>
#include <QSet>
#include <QTime>

#include <cstdlib>

class Scheduler {

public:
  Scheduler(Calendar *calendar, Calendar *basicCalendar, QDate *startDate);
  ~Scheduler();

  void generateSchedule(const QTime &startOfWorkday, const QTime &endOfWorkday);

private slots:
  void generateSchedules(QList<Event> freeTime);
  bool nextPermutation(QList<Event> &events, int size);
  void generatePermutations(QList<Event> &events, int start, int end, int depth,
                            QList<QList<Event>> &allPermutations);
  QList<Event> findFreeTime(Calendar *cal1, int maxTime);

private:
  Calendar *m_calendar;
  Calendar *m_basicCalendar;
  Calendar *m_scheduledCalendar;
  QList<Calendar *> m_generatedSchedules;
  QList<Event> m_freeTimeList;
  QList<BasicEvent> m_allEvents;
  QDate *m_startDate;
};

#endif // SCHEDULER_H
