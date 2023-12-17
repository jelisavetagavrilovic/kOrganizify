#include "toDoList.h"
#include "task.h"

ToDoList::ToDoList(QObject *parent) {
    QVector<Task> myVector;
    myVector.clear();
    this->m_tasks = myVector;
}


void ToDoList::loadData(const QString &username) {
    SaveLoad::loadData(username);

    QJsonArray jsonArray = m_jsonObject["tasks"].toArray();
    for (const QJsonValue &jsonValue : jsonArray) {
        Task task(jsonValue["task"].toString());

        addTask(task);
    }
}

void ToDoList::saveData(const QString &username) {
    QJsonArray jsonArray;
    for (const Task &task : m_tasks) {
        QJsonObject jsonObject;
        jsonObject["task"] = task.getName();

        jsonArray.append(jsonObject);
    }

    m_jsonObject["tasks"] = jsonArray;
    SaveLoad::saveData(username);
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
    for (Task task : this->getTasks())
        taskNames.append(task.getName());

    QString string = taskNames.join("\n");
    return string;
}
