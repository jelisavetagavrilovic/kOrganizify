#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "eventwindow.h"
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
    void colorCell();
private slots:
    void on_btnSettings_clicked();
    void openEventWindow(int row, int column);
    void addTask();
    void onCheckBoxStateChanged(int state);

private:
    Ui::AppWindow *ui;
    SettingsWindow *settingsWindow;
    EventWindow *eventWindow;
    ToDoList m_toDoList;
};

#endif // APPWINDOW_H
