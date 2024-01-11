#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include "calendar.h"
#include <QWidget>

namespace Ui {
class EventWindow;
}

class EventWindow : public QWidget {
  Q_OBJECT

public:
  explicit EventWindow(Calendar *calendar, QWidget *parent = nullptr);
  ~EventWindow();
  void setStartDate(const QDateTime &dateTime);
  void setEndDate(const QDateTime &dateTime);
  void setTitle(const QString &title);
  void setDescription(const QString &description);
  void setLocation(const QString &location);
  void setPriority(const CustomEventPriority &priority);
  void setCurrentEvent(const Event &event);
  Event getCurrentEvent() const;
  bool isEventNull() const;
  void changeColor(QString color);
  bool checkEventOverlap(const Event &newEvent);

signals:
  void saveButtonClicked();
  void deleteButtonClicked();

protected:
  void keyPressEvent(QKeyEvent *event) override;

private slots:
  void onSaveButtonClicked();
  void onDeleteButtonClicked();

private:
  Ui::EventWindow *ui;
  Calendar *m_calendar;
  Event m_currentEvent;
};

#endif // EVENTWINDOW_H
