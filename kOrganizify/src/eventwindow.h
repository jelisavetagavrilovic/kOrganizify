#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include <QWidget>
#include "calendar.h"

namespace Ui {
class EventWindow;
}

class EventWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EventWindow(Calendar* calendar, QWidget *parent = nullptr);
    ~EventWindow();
    void setDateAndTime(const QDateTime &dateTime);
    void changeColor(QString color);

private:
    Ui::EventWindow *ui;
    Calendar* m_calendar;

signals:
    void saveButtonClicked();

private slots:
    // void on_btnGenerate_clicked();
    void onSaveButtonClicked();
};

#endif // EVENTWINDOW_H
