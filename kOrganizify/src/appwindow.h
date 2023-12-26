// appwindow.h
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
#include "settingswindow.h"
#include "syncwindow.h"
#include "user.h"
#include "toDoList.h"
#include "notifications.h"


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

private slots:
    void changeButtonColor(const QString &newColor);
    void enabledNotifications(const bool enabled);
    void colorCell();
    void openEventWindow(int row, int column);
    void addTask();
    void onCheckBoxStateChanged(int state);
    // Qstring crossTask(int index);
    void openSettings();
    void logoutUser();
    void openSyncWindow();
    void populateFriends(const QList<QString>& friends);
    void clearFinishedTasks();
    // void reorderCheckedTasks();

private:
    Ui::AppWindow *ui;
    User *m_user;
    SettingsWindow *settingsWindow;
    SyncWindow *syncWindow;
    EventWindow *eventWindow;
    // ToDoList m_toDoList;
    Calendar* m_calendar;
    Notifications* m_notifications;
};

#endif // APPWINDOW_H
