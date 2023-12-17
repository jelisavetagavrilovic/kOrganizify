#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "toDoList.h"
#include "settingswindow.h"
#include "user.h"

namespace Ui {
class AppWindow;
}

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppWindow(User *user, QWidget *parent = nullptr);
    ~AppWindow();

    void changeButtonColor(const QString &newColor);

private slots:
    void on_btnSettings_clicked();
    void addTask();
    void onCheckBoxStateChanged(int state);
    void on_btnLogout_clicked();

private:
    Ui::AppWindow *ui;
    SettingsWindow *settingsWindow;
    ToDoList m_toDoList;
    User *m_user;
};

#endif // APPWINDOW_H
