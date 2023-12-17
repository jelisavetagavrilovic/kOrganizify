#ifndef TODOLIST_H
#define TODOLIST_H

#include "task.h"
#include "saveload.h"
#include <QObject>
#include <QVector>
#include <QString>
#include <QJsonArray>

// ovo je singleton object

class ToDoList : public SaveLoad
{
    Q_OBJECT

private:
    QVector<Task> m_tasks;

public:
    explicit ToDoList(QObject *parent = nullptr);
    void loadData(const QString &username);
    void saveData(const QString &username);

    QVector<Task> getTasks();
    void setTasks(const QVector<Task> tasks);
    void addTask(const Task task);
    void removeTask(const Task task);
    QString toString();

signals:
};

#endif // TODOLIST_H
