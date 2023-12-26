#ifndef BASICEVENTWINDOW_H
#define BASICEVENTWINDOW_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "basicevent.h"
#include "calendar.h"

namespace Ui {
class BasicEventWindow;
}

class BasicEventWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BasicEventWindow(Calendar *calendar, QWidget *parent = nullptr);
    ~BasicEventWindow();

private slots:
    bool addEvent();
    void removeEvent();
    void generate();
    void nextEvent();
    void previousEvent();
    void updateUi();


private:
    Ui::BasicEventWindow *ui;
    BasicEvent *m_basicEvent;
    Calendar *m_calendar;
    Calendar *m_basicCalendar;
    int m_currentIndex;


};

#endif // BASICEVENTWINDOW_H
