#include "task.h"

//check
Task::Task(QString name /*= "Add Task"*/)
    : m_name(name) {
}

void Task::setName(const QString newName){
    this->m_name = newName;
}

QString Task::getName() const{
    return this->m_name;
}

bool Task::operator==(const Task &other) const {
    return this->m_name == other.m_name;
}
