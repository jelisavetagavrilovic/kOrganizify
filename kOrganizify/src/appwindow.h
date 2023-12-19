// appwindow.h
#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QCheckBox>
#include <QDir>
#include <QVector>

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

    void addTaskToListWidget(const Task &task);
    void initialize();

private slots:
    void addTask();
    // void addEvent();
    void changeButtonColor(const QString &newColor);
    void onCheckBoxStateChanged(int state);
    void openSettings();
    void logoutUser();

private:
    Ui::AppWindow *ui;
    User *m_user;
    SettingsWindow *settingsWindow;
};
// private:
//     Ui::AppWindow *ui;
//
//     ToDoList m_toDoList;
//     User *m_user;


#endif // APPWINDOW_H
