// appwindow.h
#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QCheckBox>
#include <QDir>
#include <QVector>

//#include "mainwindow.h"
#include "qlistwidget.h"
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

public slots:
    void handleNewUserLoggedIn(const QString& username);
    void handleUserDisconnected(const QString& username);
    void addTaskToListWidget(const Task &task);
    void on_btnSettings_clicked();
    void initialize();

private slots:
    void addTask();
    void changeButtonColor(const QString &newColor);
    void onCheckBoxStateChanged(int state);
    void logoutUser();
    void openSyncWindow();

private:
    void populateFriends(const QList<QString>& friends);
    Ui::AppWindow *ui;
    User *m_user;
    SettingsWindow *settingsWindow;
    ToDoList m_toDoList;
    SyncWindow *syncWindow;
};

#endif // APPWINDOW_H
