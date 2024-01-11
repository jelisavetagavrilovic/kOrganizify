#ifndef SYNCWINDOW_H
#define SYNCWINDOW_H
#include "calendar.h"

#include <QWidget>

namespace Ui {
class SyncWindow;
}

class SyncWindow : public QWidget {
    Q_OBJECT

  public:
    explicit SyncWindow(QString username, QString friendName, Calendar calendar, QWidget *parent = nullptr);
    ~SyncWindow();

    QString getEnteredText() const;
    int getSelectedNumber() const;
    void changeColor(QString color);

  signals:
    void sendSyncRequest(QString username, QString friendName, QString eventTitle, int duration, Calendar calendar);

  private slots:
    void onTextEntered(const QString &m_text);
    void onNumberSelected(int m_index);
    void onSyncButtonClicked();

  private:
    Ui::SyncWindow *ui;

    QString m_friendName;
    QString m_username;
    QString m_enteredText;
    Calendar m_calendar;
    int m_selectedNumber;
};

#endif // SYNCWINDOW_H
