#include "scheduler.h"

Scheduler::Scheduler(Calendar *calendar, Calendar* m_basicCalendar)
    : m_calendar(calendar)
    , m_basicCalendar(m_basicCalendar)
    , m_scheduledCalendar(nullptr)
{
    //refactor - update calendar with sort?
    QList<BasicEvent> m_AllEvents;
    for (int i = 0; i < m_basicCalendar->sizeBasic(); i++)
        m_AllEvents.append(m_basicCalendar->getBasicEvent(i));

    std::sort(m_AllEvents.begin(), m_AllEvents.end(), [](const BasicEvent &a, const BasicEvent &b) {
        return a.getDuration() > b.getDuration();
    });
}

void Scheduler::generateSchedule(const QTime &startOfWorkday, const QTime &endOfWorkday) {

    auto it = std::remove_if(m_freeTimeList.begin(), m_freeTimeList.end(),
                        [startOfWorkday, endOfWorkday](const Event& event) {
                            QDateTime startTime = event.getStartTime();
                            QDateTime endTime = event.getEndTime();
                            return startTime.time() <= startOfWorkday || endTime.time() >= endOfWorkday;});
    m_freeTimeList.erase(it, m_freeTimeList.end());

    Calendar* tmp;
    for(BasicEvent& event : m_AllEvents) {
        //check for minutes
        m_freeTimeList = findFreeTime(m_calendar, event.getDuration());
        tmp = generateSchedules(m_freeTimeList);

        Event e;
        e.setStartTime(tmp->getEvents()[0].getStartTime());
        e.setEndTime(tmp->getEvents()[0].getEndTime());
        e.setTitle(event.getTitle());

        qDebug() << e.getTitle() << e.getStartTime() << e.getEndTime();

        m_calendar->addEvent(e);
    }

//    for(Event& event : m_calendar->getEvents())
//        qDebug() << event.getTitle() << event.getStartTime() << event.getEndTime();
}

Calendar* Scheduler::generateSchedules(QList<Event> freeTime) {
    QList<QList<Event>> allPermutations;
    generatePermutations(freeTime, 0, freeTime.size() - 1, 0, allPermutations);

    Calendar* cal;
    QList<Event> permutation = allPermutations[0];
    for (int j = 0; j < permutation.size(); ++j) {
        Event event = permutation[j];
        cal->addEvent(event);
    }

    return cal;
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

QList<Event> Scheduler::findFreeTime(Calendar *cal1, int maxTime) {
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

    QDate currentDay = QDateTime::currentDateTime().date();
    QTime currentHour = QDateTime::currentDateTime().time();
    QDate lastDayOfWeek = currentDay.addDays(7 - currentDay.dayOfWeek());

    for (QDate currentDate = currentDay; currentDate <= lastDayOfWeek; currentDate = currentDate.addDays(1)) {
        QTime startHour = (currentDate == currentDay) ? roundUpToNextHour(currentHour) : QTime(8, 0);
        QTime endHour = QTime(23, 59, 59);

        if(isBetween12pmAnd8am(startHour))
            startHour = QTime(8, 0);

        for (QTime currentHour = startHour; currentHour < endHour; currentHour = currentHour.addSecs(3600)) {
            QTime endTime = endHour.addSecs(-maxTime * 3600);

            if (currentHour <= endTime) {
                Event* newEvent = new Event();
                newEvent->setStartTime(QDateTime(currentDate, currentHour));
                newEvent->setEndTime(QDateTime(currentDate, currentHour.addSecs(maxTime * 3600)));

                freeTimeSlots.append(*newEvent);
            }

            if (currentHour.hour() == 23)
                break;
        }
    }

    // removing free time slots that overlap with existing events
    auto it = std::remove_if(freeTimeSlots.begin(), freeTimeSlots.end(), [&](const Event &freeTimeSlot) {
        for (const auto &existingEvent : allEvents) {
            if (freeTimeSlot.getStartTime() < existingEvent.getEndTime() &&
                freeTimeSlot.getEndTime() > existingEvent.getStartTime()) {
                return true;  // ovelapping, remove this free time slot
            }
        }
        return false;
    });

    freeTimeSlots.erase(it, freeTimeSlots.end());
    return freeTimeSlots;
}


Scheduler::~Scheduler() {
    // Implementacija destruktora po potrebi
}
