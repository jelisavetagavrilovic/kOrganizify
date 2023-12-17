#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "toDoList.h"
#include "settingswindow.h"

namespace Ui {
class AppWindow;
}

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

    void changeButtonColor(const QString &newColor);
private slots:
    void on_btnSettings_clicked();
    void addTask();
    void onCheckBoxStateChanged(int state);

private:
    Ui::AppWindow *ui;
    SettingsWindow *settingsWindow;
    ToDoList m_toDoList;
};

#endif // APPWINDOW_H
