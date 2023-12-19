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
    void addTask();
    void changeButtonColor(const QString &newColor);
    void onCheckBoxStateChanged(int state);
    void openSettings();
    void logoutUser();
    void openSyncWindow();
    void populateFriends(const QList<QString>& friends);

private:
    Ui::AppWindow *ui;
    User *m_user;
    SettingsWindow *settingsWindow;
//    ToDoList m_toDoList;
    SyncWindow *syncWindow;
};

#endif // APPWINDOW_H
