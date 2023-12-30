#include "toDoList.h"
#include "task.h"

ToDoList::ToDoList(QObject *parent)
    : m_tasks{}
{}


void ToDoList::loadData(const QString &username) {
    SaveLoad::loadData(username);
    fromJson(m_jsonObject);
}

void ToDoList::fromJson(const QJsonObject &jsonObject) {
    m_jsonObject = jsonObject;

    QJsonArray jsonArray = m_jsonObject["tasks"].toArray();
    for (const QJsonValue &jv : jsonArray) {
        Task task;
        task.setName(jv["task"].toString());
        task.setIsChecked(jv["isChecked"].toBool());

        addTask(task);
    }
}

QJsonValue ToDoList::toJson() const {
    QJsonArray jsonArray;
    for (const Task &task : m_tasks) {
        QJsonObject jsonObject;
        jsonObject["task"] = task.getName();
        jsonObject["isChecked"] = task.getIsChecked();
        jsonArray.append(jsonObject);
    }


    return QJsonValue(jsonArray);
}

void ToDoList::saveData(const QString &username) {
    m_jsonObject = toJson().toObject();
    SaveLoad::saveData(username);
}

QVector<Task> ToDoList::getTasks() {
    return m_tasks;
}

void ToDoList::setTasks(const QVector<Task> &tasks){
    m_tasks = tasks;
}

void ToDoList::addTask(const Task task){
    m_tasks.append(task);
}

void ToDoList::removeTask(const int index){
    m_tasks.remove(index);
}

Task* ToDoList::getTask(int index) const {
    return const_cast<Task*>(&m_tasks[index]);
}

QString ToDoList::toString() {
    QStringList taskNames;
    for (Task& task : getTasks())
        taskNames.append(task.getName());

    QString string = taskNames.join("\n");
    return string;
}
