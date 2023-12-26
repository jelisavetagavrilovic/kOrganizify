#include "task.h"

#include <QDebug>

//check
Task::Task() {}

Task::Task(QString name)
    : m_name(name)
    , m_isChecked(false)
{}

void Task::setName(const QString newName){
    this->m_name = newName;
}

QString Task::getName() const{
    return this->m_name;
}

bool Task::getIsChecked() const{
    return this->m_isChecked;
}

void Task::setIsChecked(const bool isChecked) {
    this->m_isChecked = isChecked;
}

bool Task::operator==(const Task &other) const {
    return this->m_name == other.m_name;
}
