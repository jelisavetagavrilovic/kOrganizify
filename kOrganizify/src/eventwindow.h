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
    void setStartDate(const QDateTime &dateTime);
    void setEndDate(const QDateTime &dateTime);
    void setTitle(const QString &title);
    void setDescription(const QString &description);
    void setLocation(const QString &location);
    void setPriority(const CustomEventPriority &priority);
    void setCurrentEvent(const Event& event);
    Event getCurrentEvent() const;
    bool isEventNull() const;
    void changeColor(QString color);
    bool checkEventOverlap(const Event& newEvent);

private:
    Ui::EventWindow *ui;
    Calendar* m_calendar;
    Event m_currentEvent;

signals:
    void saveButtonClicked();
    void deleteButtonClicked();

private slots:
    // void on_btnGenerate_clicked();
    void onSaveButtonClicked();
    void onDeleteButtonClicked();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // EVENTWINDOW_H
