// appwindow.h
#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QCheckBox>
#include <QDir>

#include "mainwindow.h"
#include "settingswindow.h"

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

private slots:
    // void addTask();
    // void addEvent();
    void changeButtonColor(const QString &newColor);
    // void onCheckBoxStateChanged(int state);
    void logoutUser();

private:
    void populateFriends(const QList<QString>& friends);
    Ui::AppWindow *ui;
    User *m_user;

    // Ui::AppWindow *ui;
    SettingsWindow *settingsWindow;
//     ToDoList m_toDoList;
    // User *m_user;
};

#endif // APPWINDOW_H
