// #include "scheduler.h"
// #include <QDebug>


// Scheduler::Scheduler(Calendar *calendar, Calendar *basicCalendar)
//     : m_calendar(calendar)
//     , m_basicCalendar(basicCalendar)
//     , m_scheduledCalendar(nullptr)
// {}


// void Scheduler::generateSchedule(const QDate &startDate, const QDate &endDate, int workMinutesPerDay,
//                                  const QTime &startOfWorkday, const QTime &endOfWorkday, int maxSchedules) {
//     m_generatedSchedules.clear();

//     z3::solver solver(m_context);

//     for (int i = 0; i < maxSchedules; ++i) {
//         qDebug() << "Generisanje rasporeda - Iteracija:" << i;
//         m_scheduledCalendar = new Calendar;
//         solver.reset();

//         // Dodajemo ograničenja za fiksirane događaje
//         for (const Event &fixedEvent : m_calendar->getEvents()) {
//             qDebug() << fixedEvent.getStartTime().date();
//             QDate eventDate = fixedEvent.getStartTime().date();
//             if (eventDate >= startDate && eventDate <= endDate) {
//                 int eventStartMinutes = fixedEvent.getStartTime().time().msecsSinceStartOfDay() / (1000 * 60);
//                 int eventEndMinutes = fixedEvent.getEndTime().time().msecsSinceStartOfDay() / (1000 * 60);
//                 m_scheduledCalendar->addEvent(fixedEvent);

//                 qDebug() << "size:" << m_scheduledCalendar->size();

//                 qDebug() << "Fiksirani događaj dodat:" << fixedEvent.getTitle();
//                 qDebug() << "Vreme početka:" << m_scheduledCalendar->getEvent(0).getStartTime().toString();
//                 qDebug() << "Vreme završetka:" << m_scheduledCalendar->getEvent(0).getEndTime().toString();

//                 // Ograničenje za fiksirani događaj
//                 qDebug() << m_scheduledCalendar->size();
//                 if (m_scheduledCalendar->size() > 0) {
//                     qDebug() << "if";
//                     z3::expr fixedEventConstraint = (m_context.int_val(eventStartMinutes) <= m_scheduledCalendar->getEvent(0).getStartTime().time().msecsSinceStartOfDay() / (1000 * 60))
//                                                     && (m_scheduledCalendar->getEvent(0).getEndTime().time().msecsSinceStartOfDay() / (1000 * 60) <= m_context.int_val(eventEndMinutes));
//                     solver.add(fixedEventConstraint);
//                     qDebug() << "solver.add";
//                 }
//             }
//         }

//         // Dodajemo ograničenja za osnovne događaje
//         for (int k = 0; k < m_basicCalendar->sizeBasic(); k++) {
//             const BasicEvent basicEvent = m_basicCalendar->getBasicEvent(k);
//             z3::expr_vector basicEventVars(m_context);
//             for (int l = 0; l < workMinutesPerDay; l += 10) {  // Promenjeno iteriranje na svakih 10 minuta
//                 // Binarna promenljiva za svaki minut u danu
//                 std::string varName = "basicEvent_" + std::to_string(k) + "_" + std::to_string(l);
//                 z3::expr var = m_context.bool_const(varName.c_str());
//                 basicEventVars.push_back(var);

//                 // Ograničenje trajanja događaja
//                 z3::expr eventDurationConstraint = (z3::sum(basicEventVars) == m_context.int_val(basicEvent.getDuration()));
//                 solver.add(eventDurationConstraint);

//                 // Ograničenje da se događaj može odvijati samo jednom tokom celog intervala
//                 z3::expr oneEventPerIntervalConstraint = (z3::sum(basicEventVars) <= 1);
//                 solver.add(oneEventPerIntervalConstraint);

//                 // Ograničenje radnog vremena samo za osnovne događaje
//                 z3::expr workHoursConstraint = (l >= startOfWorkday.msecsSinceStartOfDay() / (1000 * 60)
//                                                 && l <= endOfWorkday.msecsSinceStartOfDay() / (1000 * 60)) ? m_context.bool_val(true) : m_context.bool_val(false);
//                 solver.add(workHoursConstraint);
//             }
//         }

//         // Rešavamo problem raspoređivanja
//         z3::check_result result = solver.check();

//         if (result == z3::check_result::sat) {
//             z3::model model = solver.get_model();
//             QList<Event> scheduledEventsList;

//             // Izračunavamo raspored na osnovu modela
//             for (int l = 0; l < workMinutesPerDay; l += 10) {  // Promenjeno iteriranje na svakih 10 minuta
//                 for (int m = 0; m < m_basicCalendar->sizeBasic(); m++) {
//                     const BasicEvent &basicEvent = m_basicCalendar->getBasicEvent(m);
//                     z3::expr var = model.eval(m_context.bool_const(("basicEvent_" + std::to_string(m) + "_" + std::to_string(l)).c_str()));
//                     if (var.is_true()) {
//                         QDateTime startTime = QDateTime(startDate, QTime(0, 0)).addMSecs(l * 60 * 1000);
//                         QDateTime endTime = startTime.addSecs(basicEvent.getDuration() * 60);
//                         Event scheduledEvent;
//                         scheduledEvent.setTitle(basicEvent.getTitle());
//                         scheduledEvent.setStartTime(startTime);
//                         scheduledEvent.setEndTime(endTime);
//                         scheduledEventsList.append(scheduledEvent);
//                         break;
//                     }
//                 }
//             }

//             // Dodajemo raspored u listu generisanih rasporeda
//             m_generatedSchedules.append(new Calendar);
//             for (const Event &event : scheduledEventsList) {
//                 m_generatedSchedules.last()->addEvent(event);
//             }
//         }
//     }
// }



// QList<Calendar*> Scheduler::getGeneratedSchedules() const {
//     return m_generatedSchedules;
// }


// void Scheduler::addGeneratedSchedule(Calendar *schedule) {
//     // Dodaj novi raspored u listu generisanih rasporeda
//     m_generatedSchedules.append(schedule);
// }



// Scheduler::~Scheduler() {
//     // Implementacija destruktora po potrebi
// }





























// scheduler.cpp

#include "scheduler.h"

Scheduler::Scheduler(Calendar *calendar, Calendar *basicCalendar)
    : m_calendar(calendar)
    , m_basicCalendar(basicCalendar)
    , m_scheduledCalendar(nullptr)
{}

// void Scheduler::generateSchedule(const QDate &startDate, const QDate &endDate, int workMinutesPerDay,
//                                  const QTime &startOfWorkday, const QTime &endOfWorkday, int maxSchedules) {
//     m_generatedSchedules.clear();

//     z3::solver solver(m_context);

//     for (int i = 0; i < 1; i++) {
//         qDebug() << "Generisanje rasporeda - Iteracija:" << i;
//         m_scheduledCalendar = new Calendar;
//         solver.reset();

//         // Dodajemo ograničenja za fiksirane događaje
//         for (const Event &fixedEvent : m_calendar->getEvents()) {
//             QDate eventDate = fixedEvent.getStartTime().date();
//             if (eventDate >= startDate && eventDate <= endDate) {
//                 int eventStartMinutes = fixedEvent.getStartTime().time().msecsSinceStartOfDay() / (1000 * 60);
//                 int eventEndMinutes = fixedEvent.getEndTime().time().msecsSinceStartOfDay() / (1000 * 60);
//                 m_scheduledCalendar->addEvent(fixedEvent);

//                 if (m_scheduledCalendar->size() > 0) {
//                     z3::expr fixedEventConstraint = (m_context.int_val(eventStartMinutes) <= m_scheduledCalendar->getEvent(0).getStartTime().time().msecsSinceStartOfDay() / (1000 * 60))
//                                                     && (m_scheduledCalendar->getEvent(0).getEndTime().time().msecsSinceStartOfDay() / (1000 * 60) <= m_context.int_val(eventEndMinutes));
//                     solver.add(fixedEventConstraint);
//                 }
//             }
//         }

//         // Dodajemo ograničenja za osnovne događaje
//         for (int k = 0; k < m_basicCalendar->sizeBasic(); k++) {
//             const BasicEvent basicEvent = m_basicCalendar->getBasicEvent(k);
//             z3::expr_vector basicEventVars(m_context);
//             for (int l = 0; l < workMinutesPerDay; l += 1) {
//                 std::string varName = "basicEvent_" + std::to_string(k) + "_" + std::to_string(l);
//                 z3::expr var = m_context.bool_const(varName.c_str());
//                 basicEventVars.push_back(var);

//                 addEventDurationConstraints(solver, basicEventVars, basicEvent.getDuration());
//                 //qDebug() << basicEventVars.to_string();


//                 z3::expr oneEventPerIntervalConstraint = (z3::sum(basicEventVars) <= 1);
//                 solver.add(oneEventPerIntervalConstraint);

//                 // z3::expr workHoursConstraint = (l >= startOfWorkday.msecsSinceStartOfDay() / (1000 * 60)
//                 //                                 && l <= endOfWorkday.msecsSinceStartOfDay() / (1000 * 60)) ? m_context.bool_val(true) : m_context.bool_val(false);
//                 // Dodajemo ograničenje za radne sate
//                 z3::expr workHoursConstraint = (z3::sum(basicEventVars) > 0)
//                                                        && (l >= startOfWorkday.msecsSinceStartOfDay() / (1000 * 60)
//                                                            && l <= endOfWorkday.msecsSinceStartOfDay() / (1000 * 60)) ? m_context.bool_val(true) : m_context.bool_val(false);
//                 solver.add(workHoursConstraint);
//                 solver.add(workHoursConstraint);
//             }
//         }


//         // qDebug() << "Ograničenja pre rešavanja:";
//         // for (const auto &c : solver.assertions()) {
//         //     qDebug() << c.to_string().c_str();
//         // }

//         // Rešavamo problem raspoređivanja
//         z3::check_result result = solver.check();

//         if (result == z3::check_result::sat) {
//             z3::model model = solver.get_model();
//             Calendar scheduledEventsList;

//             // Dodajte sledeći ispis kako biste videli šta je u modelu
//             qDebug() << "Model:" << model;

//             // Izračunavamo raspored na osnovu modela
//             for (int l = 0; l < workMinutesPerDay; l += 1) {
//                 for (int m = 0; m < m_basicCalendar->sizeBasic(); m++) {
//                     const BasicEvent &basicEvent = m_basicCalendar->getBasicEvent(m);
//                     z3::expr var = model.eval(m_context.bool_const(("basicEvent_" + std::to_string(m) + "_" + std::to_string(l)).c_str()));
//                     qDebug() << "Variable:" << var.to_string().c_str();
//                     if (var.is_true()) {
//                         QDateTime startTime = QDateTime(startDate, QTime(0, 0)).addMSecs(l * 60 * 1000);
//                         QDateTime endTime = startTime.addSecs(basicEvent.getDuration() * 60);
//                         Event scheduledEvent;
//                         scheduledEvent.setTitle(basicEvent.getTitle());
//                         scheduledEvent.setStartTime(startTime);
//                         scheduledEvent.setEndTime(endTime);

//                         qDebug() << scheduledEvent.getTitle() << scheduledEvent.getStartTime() << scheduledEvent.getEndTime() << scheduledEvent.getDuration();
//                         scheduledEventsList.addEvent(scheduledEvent);

//                         break;
//                     }
//                 }
//             }

//             // Dodajemo raspored u listu generisanih rasporeda
//             m_generatedSchedules.append(&scheduledEventsList);
//             // for (const Event &event : scheduledEventsList) {
//             //     m_generatedSchedules.last()->addEvent(event);
//             // }
//         }
//     }
// }


void Scheduler::generateSchedule(const QDate &startDate, const QDate &endDate, int workMinutesPerDay,
                                 const QTime &startOfWorkday, const QTime &endOfWorkday, int maxSchedules) {
    m_generatedSchedules.clear();

    for (int i = 0; i < 1; i++) {
        qDebug() << "Generisanje rasporeda - Iteracija:" << i;
        m_scheduledCalendar = new Calendar;
        z3::solver solver(m_context);

        // Dodajemo ograničenja za fiksirane događaje
        for (const Event &fixedEvent : m_calendar->getEvents()) {
            QDate eventDate = fixedEvent.getStartTime().date();
            if (eventDate >= startDate && eventDate <= endDate) {
                int eventStartMinutes = fixedEvent.getStartTime().time().msecsSinceStartOfDay() / (1000 * 60);
                int eventEndMinutes = fixedEvent.getEndTime().time().msecsSinceStartOfDay() / (1000 * 60);
                m_scheduledCalendar->addEvent(fixedEvent);

                if (m_scheduledCalendar->size() > 0) {
                    z3::expr fixedEventConstraint = (m_context.int_val(eventStartMinutes) <= m_scheduledCalendar->getEvent(0).getStartTime().time().msecsSinceStartOfDay() / (1000 * 60))
                                                    && (m_scheduledCalendar->getEvent(0).getEndTime().time().msecsSinceStartOfDay() / (1000 * 60) <= m_context.int_val(eventEndMinutes));
                    solver.add(fixedEventConstraint);
                }
            }
        }

        // Dodajemo ograničenja za osnovne događaje
        for (int k = 0; k < m_basicCalendar->sizeBasic(); k++) {
            const BasicEvent basicEvent = m_basicCalendar->getBasicEvent(k);
            z3::expr_vector basicEventVars(m_context);

            // Iteriramo kroz sve datume u opsegu
            for (QDate currentDate = startDate; currentDate <= endDate; currentDate = currentDate.addDays(1)) {
                // Iteriramo kroz sve minute u danu
                for (int l = 0; l < workMinutesPerDay; l += 1) {
                    std::string varName = "basicEvent_" + std::to_string(k) + "_" + currentDate.toString("yyyyMMdd").toStdString() + "_" + std::to_string(l);
                    z3::expr var = m_context.bool_const(varName.c_str());
                    basicEventVars.push_back(var);

                    // Dodajemo ograničenje za trajanje osnovnog događaja
                    addEventDurationConstraints(solver, basicEventVars, basicEvent.getDuration());

                    // Dodajemo ograničenje da se može održati najviše jedan događaj u datom intervalu
                    z3::expr oneEventPerIntervalConstraint = (z3::sum(basicEventVars) <= 1);
                    solver.add(oneEventPerIntervalConstraint);

                    // Dodajemo ograničenje da se događaj može održati samo ako je unutar radnog vremena
                    z3::expr workHoursConstraint = (z3::sum(basicEventVars) > 0)
                                                           && (l >= startOfWorkday.msecsSinceStartOfDay() / (1000 * 60)
                                                               && l <= endOfWorkday.msecsSinceStartOfDay() / (1000 * 60)) ? m_context.bool_val(true) : m_context.bool_val(false);
                    solver.add(workHoursConstraint);
                }
            }
        }

        // Rešavamo problem raspoređivanja
        z3::check_result result = solver.check();

        if (result == z3::check_result::sat) {
            qDebug() << "Raspored je pronađen";
                z3::model model = solver.get_model();

            // Čuvanje rasporeda po danima i fiksiranih događaja u glavnu listu
            QList<QVariantMap> schedulesByDay;

            for (QDate currentDate = startDate; currentDate <= endDate; currentDate = currentDate.addDays(1)) {
                QVariantMap dailyScheduleInfo;
                QList<Event> dailyEvents;
                QList<Event> fixedEvents;

                for (int l = 0; l < workMinutesPerDay; l += 1) {
                    for (int m = 0; m < m_basicCalendar->sizeBasic(); m++) {
                        const BasicEvent &basicEvent = m_basicCalendar->getBasicEvent(m);
                        z3::expr var = model.eval(m_context.bool_const(("basicEvent_" + std::to_string(m) + "_" + currentDate.toString("yyyyMMdd").toStdString() + "_" + std::to_string(l)).c_str()));

                        if (var.is_true()) {
                            QDateTime startTime = QDateTime(currentDate, QTime(0, 0)).addMSecs(l * 60 * 1000);
                            QDateTime endTime = startTime.addSecs(basicEvent.getDuration() * 60);
                            Event scheduledEvent;
                            scheduledEvent.setTitle(basicEvent.getTitle());
                            scheduledEvent.setStartTime(startTime);
                            scheduledEvent.setEndTime(endTime);

                            dailyEvents.append(scheduledEvent);

                            break;
                        }
                    }
                }

                // Dodajemo fiksirane događaje za trenutni dan
                for (const Event &fixedEvent : m_calendar->getEvents()) {
                    QDate eventDate = fixedEvent.getStartTime().date();
                    if (eventDate == currentDate) {
                        fixedEvents.append(fixedEvent);
                    }
                }

                dailyScheduleInfo["date"] = currentDate.toString("yyyy-MM-dd");
                dailyScheduleInfo["scheduledEvents"] = QVariant::fromValue(dailyEvents);
                dailyScheduleInfo["fixedEvents"] = QVariant::fromValue(fixedEvents);

                schedulesByDay.append(dailyScheduleInfo);
            }

            m_generatedSchedules.append(schedulesByDay);
        } else {
            qDebug() << "Raspored nije pronađen";
        }

        // Oslobađanje memorije
        delete m_scheduledCalendar;
    }
}







// QList<Calendar*> Scheduler::getGeneratedSchedules() const {
// //     return m_generatedSchedules;
// }

// void Scheduler::addGeneratedSchedule(Calendar *schedule) {
// //     // Dodaj novi raspored u listu generisanih rasporeda
// //     m_generatedSchedules.append(schedule);
// }

void Scheduler::addEventDurationConstraints(z3::solver& solver, const z3::expr_vector& basicEventVars, int duration) {
    // Ograničenje trajanja događaja
    z3::expr eventDurationConstraint = (z3::sum(basicEventVars) == m_context.int_val(duration));
    solver.add(eventDurationConstraint);
}

Scheduler::~Scheduler() {
    // Implementacija destruktora po potrebi
}
