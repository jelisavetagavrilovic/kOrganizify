#include "scheduler.h"

Scheduler::Scheduler(Calendar *calendar, Calendar* basicCalendar, QDate *startDate)
    : m_calendar(calendar)
    , m_basicCalendar(basicCalendar)
    , m_scheduledCalendar(new Calendar())
    , m_startDate(startDate)
{
}

void Scheduler::generateSchedule(const QTime &startOfWorkday, const QTime &endOfWorkday) {

    QList<BasicEvent> m_allEvents;
    for (int i = 0; i < m_basicCalendar->sizeBasic(); i++)
        m_allEvents.append(m_basicCalendar->getBasicEvent(i));

    std::sort(m_allEvents.begin(), m_allEvents.end(), [](const BasicEvent &a, const BasicEvent &b) {
        return a.getDuration() > b.getDuration();
    });

    for(BasicEvent& event : m_allEvents) {
        m_freeTimeList = findFreeTime(m_calendar, event.getDuration());

        auto it = std::remove_if(m_freeTimeList.begin(), m_freeTimeList.end(),
                                 [startOfWorkday, endOfWorkday](const Event& event) {
                                     QDateTime startTime = event.getStartTime();
                                     QDateTime endTime = event.getEndTime();
                                     return startTime.time() <= startOfWorkday || endTime.time() >= endOfWorkday;});
        m_freeTimeList.erase(it, m_freeTimeList.end());

        generateSchedules(m_freeTimeList);
        QList<Event> scheduledEvents = m_scheduledCalendar->getEvents();
        Event e;
        if (!scheduledEvents.isEmpty()) {
            int randomIndex = rand() % scheduledEvents.size();

            e.setStartTime(scheduledEvents[randomIndex].getStartTime());
            e.setEndTime(scheduledEvents[randomIndex].getEndTime());
            e.setTitle(event.getTitle());
        }

        m_calendar->addEvent(e);
    }
}

void Scheduler::generateSchedules(QList<Event> freeTime) {
    QList<QList<Event>> allPermutations;
    generatePermutations(freeTime, 0, freeTime.size() - 1, 0, allPermutations);

    int randomIndex = rand() % allPermutations.size();
    QList<Event> permutation = allPermutations[randomIndex];

    for (int j = 0; j < permutation.size(); ++j) {
        Event event = permutation[j];
        m_scheduledCalendar->addEvent(event);
    }
}

void Scheduler::generatePermutations(QList<Event>& events, int start, int end, int depth,
                                     QList<QList<Event>>& allPermutations) {
    if (depth >= 1) {
       allPermutations.append(events);
       return;
    }

    for (int i = start; i <= end; ++i) {
       std::swap(events[start], events[i]);
       generatePermutations(events, start + 1, end, depth + 1, allPermutations);
       std::swap(events[start], events[i]);  // backtrack
    }
}

QList<Event> Scheduler::findFreeTime(Calendar *cal1, int maxTimeInMinutes) {
    QList<Event> freeTimeSlots;
    QList<Event> allEvents;

    allEvents.append(cal1->getEvents());
    std::sort(allEvents.begin(), allEvents.end(), [](const Event &a, const Event &b) {
        return a.getStartTime() < b.getStartTime();
    });

    auto roundUpToNextHour = [](const QTime &time) {
        return (time.minute() > 0 || time.second() > 0 || time.msec() > 0) ? QTime(time.hour() + 1, 0) : time;
    };

    auto isBetween12pmAnd8am = [](const QTime& currentHour) {
        return (currentHour >= QTime(0, 0) && currentHour < QTime(12, 0)) || (currentHour >= QTime(12, 0) && currentHour <= QTime(8, 0));
    };

    QDate currentDay = *m_startDate;
    QTime currentHour = QDateTime::currentDateTime().time();
    QDate lastDayOfWeek = currentDay.addDays(7 - currentDay.dayOfWeek());

    for (QDate currentDate = currentDay; currentDate <= lastDayOfWeek; currentDate = currentDate.addDays(1)) {
       QTime startHour = (currentDate == currentDay) ? roundUpToNextHour(currentHour) : QTime(8, 0);
       QTime endHour = QTime(23, 59, 59);

       if(isBetween12pmAnd8am(startHour))
           startHour = QTime(8, 0);

       for (QTime currentHour = startHour; currentHour < endHour; currentHour = currentHour.addSecs(60 * maxTimeInMinutes)) {
           QTime endTime = endHour.addSecs(-60 * maxTimeInMinutes);

           if (currentHour <= endTime) {
               Event* newEvent = new Event();
               newEvent->setStartTime(QDateTime(currentDate, currentHour));
               newEvent->setEndTime(QDateTime(currentDate, currentHour.addSecs(60 * maxTimeInMinutes)));

               freeTimeSlots.append(*newEvent);
           }

           if (currentHour.addSecs(60 * maxTimeInMinutes).hour() == 23)
               break;
       }
    }

    // removing free time slots that overlap with existing events
    auto it = std::remove_if(freeTimeSlots.begin(), freeTimeSlots.end(), [&](const Event &freeTimeSlot) {
        for (const auto &existingEvent : allEvents) {
            if (freeTimeSlot.getStartTime() < existingEvent.getEndTime() &&
                freeTimeSlot.getEndTime() > existingEvent.getStartTime()) {
                return true;  // overlapping, remove this free time slot
            }
        }
        return false;
    });

    freeTimeSlots.erase(it, freeTimeSlots.end());
    return freeTimeSlots;
}


Scheduler::~Scheduler() {
    delete m_basicCalendar;
    delete m_scheduledCalendar;
}
