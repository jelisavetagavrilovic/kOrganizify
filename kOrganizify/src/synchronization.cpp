#include "synchronization.h"

QList<Event> Synchronization::findFreeTime(const Calendar &cal1, const Calendar &cal2, int maxTime) {
    QList<Event> freeTimeSlots;

    QList<Event> allEvents;
    allEvents.append(cal1.getEvents());
    allEvents.append(cal2.getEvents());

    QSet<Event> uniqueEvents;
    for (const auto &event : allEvents) {
        uniqueEvents.insert(event);
    }

    // converting the QSet back to a QList and sorting
    allEvents = QList<Event>(uniqueEvents.begin(), uniqueEvents.end());
    std::sort(allEvents.begin(), allEvents.end(), [](const Event &a, const Event &b) {
        return a.getStartTime() < b.getStartTime();
    });

    QDate currentDay = QDateTime::currentDateTime().date();
    QTime currentHour = QDateTime::currentDateTime().time();
    QDate lastDayOfWeek = currentDay.addDays(7 - currentDay.dayOfWeek());

    for (QDate currentDate = currentDay; currentDate <= lastDayOfWeek; currentDate = currentDate.addDays(1)) {

        QTime startHour = (currentDate == currentDay) ? currentHour : QTime(8, 0);
        QTime endHour = QTime(23, 59, 59);

        for (QTime currentHour = startHour; currentHour < endHour; currentHour = currentHour.addSecs(3600)) {
            QTime endTime = endHour.addSecs(-maxTime * 3600);

            if (currentHour <= endTime) {
                Event* newEvent = new Event();
                newEvent->setStartTime(QDateTime(currentDate, currentHour));
                newEvent->setEndTime(QDateTime(currentDate, currentHour.addSecs(maxTime * 3600)));
                newEvent->setTitle("Free time");

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

