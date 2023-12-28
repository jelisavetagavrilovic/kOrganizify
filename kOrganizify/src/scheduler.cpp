#include "scheduler.h"
#include <QDebug>

Scheduler::Scheduler(Calendar *calendar, Calendar *basicCalendar)
    : m_calendar(calendar),
    m_basicCalendar(basicCalendar),
    m_context()
{}


// void Scheduler::generateSchedule(const QDate &startDate, const QDate &endDate, int workMinutesPerDay,
//                                  const QTime &startOfWorkday, const QTime &endOfWorkday, int num) {

//     qDebug() << "Veličina Osnovnog Kalendara:" << m_basicCalendar->sizeBasic();

//                                                   z3::solver solver(m_context);

//     for (int i = 0; i < m_basicCalendar->sizeBasic(); i++) {
//         z3::expr_vector times(m_context);
//         z3::expr_vector events(m_context);

//         bool eventScheduled = false;

//         for (int j = 0; j < 7; j++) {
//             int index = i * 7 + j;
//             events.push_back(m_context.bool_const(std::to_string(index).c_str()));
//             times.push_back(m_context.int_const(std::to_string(index).c_str()));

//             // qDebug() << "Adding constraint for times[" << j << "]: " << times[j].to_string() << " >= 0 && " << times[j].to_string() << " <= " << workMinutesPerDay;
//             solver.add(times[j] >= m_context.int_val(0) && times[j] <= m_context.int_val(workMinutesPerDay));
//         }

//         QDate currentDate = startDate;

//         int maxAttempts = 100;  // Postavite željeni maksimalni broj pokušaja
//         int currentAttempt = 0;

//         while (!eventScheduled && currentAttempt < maxAttempts) {
//             if (solver.check() == z3::sat) {
//                 currentAttempt++;

//                 z3::model model = solver.get_model();

//                 Calendar* scheduledCalendar = new Calendar;  // Kreiramo novi kalendar
//                 for (int j = 0; j < 7; j++) {
//                     int minuteIndex = std::stoi(model.eval(times[j], true).to_string());
//                     //qDebug() << "generate:" << minuteIndex;

//                     // Pravilno izračunajte vreme na osnovu minuteIndex, startDate, i vremena početka radnog dana
//                     QDateTime scheduledDateTime = QDateTime(startDate.addDays(j), startOfWorkday).addSecs(minuteIndex * 60);

//                     if (isTimeSlotAvailable(scheduledDateTime,
//                                             m_basicCalendar->getBasicEvent(i).getDuration(),
//                                             workMinutesPerDay, startOfWorkday, endOfWorkday)) {
//                         qDebug() << "Event" << i << "scheduled at" << scheduledDateTime.toString();

//                         // Postavljamo trenutni događaj u raspored
//                         Event* scheduledEvent = new Event;
//                         scheduledEvent->setTitle(m_basicCalendar->getBasicEvent(i).getTitle());
//                         scheduledEvent->setDuration(m_basicCalendar->getBasicEvent(i).getDuration());
//                         scheduledEvent->setStartTime(scheduledDateTime);
//                         scheduledEvent->setEndTime(scheduledDateTime.addSecs(m_basicCalendar->getBasicEvent(i).getDuration() * 60));
//                         // Dodajemo događaj u kalendar
//                         scheduledCalendar->addEvent(*scheduledEvent);
//                         delete scheduledEvent;

//                         eventScheduled = true;
//                         break;
//                     }
//                 }

//                 // Dodajemo kalendar u listu
//                 addGeneratedSchedule(scheduledCalendar);
//             } else {
//                 break;
//             }

//             // Pomeramo se na sledeći dan
//             currentDate = currentDate.addDays(1);
//         }
//     }

//     qDebug() << "nije pronadjen raspored";
// }




// bool Scheduler::isTimeSlotAvailable(const QDateTime &dateTime, int duration, int workMinutesPerDay,
//                                     const QTime &startOfWorkday, const QTime &endOfWorkday) const {

//     //int minuteIndex = dateTime.time().msecsSinceStartOfDay() / (1000 * 60) - startOfWorkday.msecsSinceStartOfDay() / (1000 * 60);
//     int minuteIndex = dateTime.time().msecsSinceStartOfDay() / (1000 * 60) - startOfWorkday.msecsSinceStartOfDay() / (1000 * 60);
//     // qDebug() << "DateTime:" << dateTime.toString() << "Minute Index:" << minuteIndex;

//     if (minuteIndex < 0 || minuteIndex + duration > workMinutesPerDay) {
//         qDebug() << "Invalid minute index or duration exceeds work minutes per day.";
//         return false;
//     }

//     if (dateTime.time() < startOfWorkday || dateTime.time() > endOfWorkday) {
//         qDebug() << "Time is outside of working hours.";
//         return false;
//     }

//     // Proveri fiksirane događaje iz m_calendar
//     for (const Event &fixedEvent : m_calendar->getEvents()) {
//         QDateTime fixedEventStart = fixedEvent.getStartTime();
//         QDateTime fixedEventEnd = fixedEvent.getEndTime();

//         if (dateTime < fixedEventEnd && dateTime.addSecs(duration * 60) > fixedEventStart) {
//             // Preskoci trenutni termin jer se preklapa sa fiksiranim događajem
//             return false;
//         }
//     }

//     // Proveri već postavljene događaje iz svih kalendara u m_generatedSchedules
//     for (const Calendar *calendar : m_generatedSchedules) {
//         for (const Event &scheduledEvent : calendar->getEvents()) {
//             QDateTime scheduledEventStart = scheduledEvent.getStartTime();
//             QDateTime scheduledEventEnd = scheduledEvent.getEndTime();

//             if (dateTime < scheduledEventEnd && dateTime.addSecs(duration * 60) > scheduledEventStart) {
//                 // Preskoci trenutni termin jer se preklapa sa već postavljenim događajem
//                 return false;
//             }
//         }
//     }

//     // Dodaj dodatne provere prema potrebama

//     return true;
// }


void Scheduler::addGeneratedSchedule(Calendar *schedule) {
    m_generatedSchedules.append(schedule);
}



Scheduler::~Scheduler() {
    // Oslobodi resurse (npr., izbriši generisane rasporede)
    qDeleteAll(m_generatedSchedules);
    m_generatedSchedules.clear();
}




QList<Calendar*> Scheduler::getGeneratedSchedules() const {
    return m_generatedSchedules;
}




