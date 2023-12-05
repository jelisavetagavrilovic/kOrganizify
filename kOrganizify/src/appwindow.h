#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include "toDoList.h"

namespace Ui {
class AppWindow;
}

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

public slots:
    void addTask();
    void onCheckBoxStateChanged(int state);

private:
    Ui::AppWindow *ui;
    ToDoList m_toDoList;
};

#endif // APPWINDOW_H
