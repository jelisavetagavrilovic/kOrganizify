#include "toDoList.h"
#include "task.h"
#include <QVector>
#include <QStringList>

ToDoList::ToDoList(QObject *parent)
    : QObject{parent}{
    QVector<Task> myVector;
    myVector.clear();
    this->m_tasks = myVector;
}

QVector<Task> ToDoList::getTasks(){
    return this->m_tasks;
}

void ToDoList::setTasks(QVector<Task> tasks){
    this->m_tasks = tasks;
}

void ToDoList::addTask(const Task task){
    this->m_tasks.append(task);
}

void ToDoList::removeTask(const Task task){
    this->m_tasks.removeOne(task);
}

QString ToDoList::toString()
{
    QStringList taskNames;
    for(Task task : this->getTasks())
        taskNames.append(task.getName());

    QString string = taskNames.join("\n");
    return string;
}
