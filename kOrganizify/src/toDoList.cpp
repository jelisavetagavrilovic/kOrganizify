#include "toDoList.h"
#include "task.h"

ToDoList::ToDoList(QObject *parent)
    : m_tasks{}
{}


void ToDoList::loadData(const QString &username) {
    SaveLoad::loadData(username);
}

void ToDoList::fromJson(const QJsonObject &jsonObject) {
    m_jsonObject = jsonObject;

    QJsonArray jsonArray = m_jsonObject["tasks"].toArray();
    for (const QJsonValue &jv : jsonArray) {
        Task task(jv["task"].toString());

        addTask(task);
    }
}

QJsonValue ToDoList::toJson() const {
    QJsonArray jsonArray;
    for (const Task &task : m_tasks) {
        QJsonObject jsonObject;
        jsonObject["task"] = task.getName();

        jsonArray.append(jsonObject);
    }

    return QJsonValue(jsonArray);
}

void ToDoList::saveData(const QString &username) {
    SaveLoad::saveData(username);
}

QVector<Task> ToDoList::getTasks() {
    return this->m_tasks;
}

void ToDoList::setTasks(const QVector<Task> &tasks){
    this->m_tasks = tasks;
}

void ToDoList::addTask(const Task task){
    this->m_tasks.append(task);
}

void ToDoList::removeTask(const Task task){
    this->m_tasks.removeOne(task);
}

QString ToDoList::toString() {
    QStringList taskNames;
    for (Task task : this->getTasks())
        taskNames.append(task.getName());

    QString string = taskNames.join("\n");
    return string;
}
