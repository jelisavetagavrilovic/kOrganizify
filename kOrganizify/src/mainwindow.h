#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "toDoList.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addTask();
    void onCheckBoxStateChanged(int state);

private:
    Ui::MainWindow *ui;
    ToDoList m_toDoList;

};
#endif // MAINWINDOW_H
