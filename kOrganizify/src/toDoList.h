#ifndef TODOLIST_H
#define TODOLIST_H

#include <QObject>
#include "task.h"
#include <QVector>
#include <QString>

// ovo je singleton object

class ToDoList : public QObject{
    Q_OBJECT
private:
    QVector<Task> m_tasks;
public:
    explicit ToDoList(QObject *parent = nullptr);
    QVector<Task> getTasks();
    void setTasks(const QVector<Task> tasks);
    void addTask(const Task task);
    void removeTask(const Task task);
    QString toString();

signals:
};

#endif // TODOLIST_H
