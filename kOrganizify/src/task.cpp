#include "task.h"

Task::Task(QString name = "Add Task") {
    this->m_name = name;
}
void Task::setName(const QString newName){
    this->m_name = newName;
}
const QString Task::getName(){
    return this->m_name;
}
bool Task::operator==(const Task &other) const {
    return this->m_name == other.m_name;
}
