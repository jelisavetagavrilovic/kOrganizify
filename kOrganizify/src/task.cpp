#include "task.h"

#include <QDebug>
#include <utility>

//check
Task::Task() = default;

Task::Task(QString name)
    : m_name(std::move(name))
    , m_isChecked(false)
{}

void Task::setName(const QString newName){
    m_name = newName;
}

auto Task::getName() const -> QString{
    return m_name;
}

auto Task::getIsChecked() const -> bool{
    return m_isChecked;
}

void Task::setIsChecked(const bool isChecked) {
    m_isChecked = isChecked;
}
