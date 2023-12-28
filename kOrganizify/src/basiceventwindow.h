#ifndef BASICEVENTWINDOW_H
#define BASICEVENTWINDOW_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QDate>
#include "basicevent.h"
#include "calendar.h"
#include "scheduler.h"

namespace Ui {
class BasicEventWindow;
}

class BasicEventWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BasicEventWindow(Calendar *calendar, QDate *startTime, QDate *endTime, QWidget *parent = nullptr);
    ~BasicEventWindow();

private slots:
    bool addEvent(const char op);
    void removeEvent();
    void generate();
    void nextEvent();
    void previousEvent();
    void updateUi();

    void print();


private:
    Ui::BasicEventWindow *ui;
    BasicEvent *m_basicEvent;
    Calendar *m_calendar;
    Calendar *m_basicCalendar;
    Scheduler *m_scheduler;
    QDate *m_startDate;
    QDate *m_endDate;
    int m_currentIndex;
};

#endif // BASICEVENTWINDOW_H
