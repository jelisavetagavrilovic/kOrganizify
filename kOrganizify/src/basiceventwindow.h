#ifndef BASICEVENTWINDOW_H
#define BASICEVENTWINDOW_H

#include "basicevent.h"
#include "calendar.h"
#include "scheduler.h"
#include <QDate>
#include <QDialog>
#include <QMessageBox>
#include <QString>

namespace Ui {
class BasicEventWindow;
}

class BasicEventWindow : public QDialog {
    Q_OBJECT

  public:
    explicit BasicEventWindow(Calendar *calendar, QDate *startTime, QWidget *parent = nullptr);
    ~BasicEventWindow();
    int m_currentIndex;
    int m_currentCalendarIndex;
    QList<Calendar *> m_listOfCalendars;
    void changeColor(QString color);

  signals:
    void previousCalendarSignal(Calendar *m_calendar);
    void nextCalendarSignal(Calendar *m_calendar);
    void saveCalendar(Calendar *m_calendar);

  private slots:
    bool addEvent(const char op);
    void removeEvent();
    void generate();
    void nextEvent();
    void previousEvent();
    void updateUi();
    void previousCalendar();
    void nextCalendar();

  private:
    Ui::BasicEventWindow *ui;
    BasicEvent *m_basicEvent;
    Calendar *m_calendar;
    Calendar *m_basicCalendar;
    Scheduler *m_scheduler;
    QDate *m_startDate;
    QList<Event> m_cal;
    QList<Event> m_basicCal;
};

#endif // BASICEVENTWINDOW_H
