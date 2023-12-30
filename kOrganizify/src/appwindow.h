#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QCheckBox>
#include <QString>
#include <QDir>
#include <QVector>
#include <QScrollBar>

#include "mainwindow.h"
#include "eventwindow.h"
#include "qlistwidget.h"
#include "responsewindow.h"
#include "settingswindow.h"
#include "syncwindow.h"
#include "basiceventwindow.h"
#include "user.h"
#include "toDoList.h"
#include "notifications.h"
#include "syncdeniedwindow.h"
#include "settingswindow.h"
#include "syncresponsewindow.h"
#include "ui_settingswindow.h"


namespace Ui {
class AppWindow;
}

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    AppWindow(User *user, QWidget *parent = nullptr);
    ~AppWindow();
    
    void initialize();

public slots:
    void handleNewUserLoggedIn(const QString& username);
    void handleUserDisconnected(const QString& username);
    void addTaskToListWidget(const Task &task);
    void showWeeklyEvents(const QDate& selectedDate);

private slots:
    void changeButtonColor(const QString &newColor);
    void openEventWindowForCell(int row, int column);
    QColor getColorFromPriority(CustomEventPriority priority);
    void enabledNotifications(const bool enabled);
    void addTask();
    void onCheckBoxStateChanged(int state);
    QString crossTask(const QString &taskName);
    void openSettings();
    void logoutUser();
    void openSyncWindow(QListWidgetItem *item);
    void populateFriends(const QList<QString>& friends);
    void smartPlan();
    void updateTableForSelectedDate();
    void updateTableForSelectedDateCalendar(Calendar* calendar);
    void clearFinishedTasks();
    void showSyncWindow(QString username, QString title, int duration);
    void syncDenied(QString friendName);
    void sendYesResponse(QString friendName, int duration);
    void sendNoResponse(QString friendName);
    void showResponseWindow(QString eventTitle, QString startTime);
    void agreedSync(QDateTime startTime, QDateTime endTime, QString title);
    void updatedEvents();

signals:
    void exit();

private:
    Ui::AppWindow *ui;
    User *m_user;
    SettingsWindow *m_settingsWindow;
    SyncWindow *m_syncWindow;
    EventWindow *m_eventWindow;
    ToDoList *m_toDoList;
    Calendar *m_calendar;
    QDate m_startDate;
    QDate m_endDate;
    Notifications* m_notifications;
};

#endif // APPWINDOW_H
