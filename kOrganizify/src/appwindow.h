// appwindow.h
#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QCheckBox>
#include <QDir>
#include <QVector>
#include <QScrollBar>

#include "mainwindow.h"
#include "eventwindow.h"
#include "qlistwidget.h"
#include "responsewindow.h"
#include "settingswindow.h"
#include "syncwindow.h"
#include "user.h"
#include "toDoList.h"


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
    void colorCell();
    void openEventWindow(int row, int column);
    void addTask();
    void onCheckBoxStateChanged(int state);
    void openSettings();
    void logoutUser();
    void openSyncWindow(QListWidgetItem *item);
    void populateFriends(const QList<QString>& friends);
    void showSyncWindow(QString username, QString title, int duration);
    void syncDenied();
    void sendYesResponse(QString friendName);
    void sendNoResponse(QString friendName);
    void showResponseWindow(QString eventTitle, QString startTime);
    void agreedSync(QDateTime startTime, QDateTime endTime, QString title);

private:
    Ui::AppWindow *ui;
    User *m_user;
    SettingsWindow *settingsWindow;
    SyncWindow *syncWindow;
    EventWindow *eventWindow;
//    ToDoList m_toDoList;
    Calendar* m_calendar;
};

#endif // APPWINDOW_H
