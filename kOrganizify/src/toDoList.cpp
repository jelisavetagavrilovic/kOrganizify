#include "toDoList.h"
#include "task.h"

ToDoList::ToDoList(QObject *parent) : m_tasks{} {}

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

auto ToDoList::toJson() const -> QJsonValue {
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

auto ToDoList::getTasks() -> QVector<Task> { return m_tasks; }

void ToDoList::setTasks(const QVector<Task> &tasks) { m_tasks = tasks; }

void ToDoList::addTask(const Task task) { m_tasks.append(task); }

void ToDoList::removeTask(const int index) { m_tasks.remove(index); }

auto ToDoList::getTask(int index) const -> Task * {
  return const_cast<Task *>(&m_tasks[index]);
}

auto ToDoList::toString() -> QString {
  QStringList taskNames;
  for (Task &task : getTasks())
    taskNames.append(task.getName());

  QString string = taskNames.join("\n");
  return string;
}
