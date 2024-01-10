#include "task.h"

#include <QDebug>

// check
Task::Task() {}

Task::Task(QString name) : m_name(name), m_isChecked(false) {}

void Task::setName(const QString newName) { m_name = newName; }

QString Task::getName() const { return m_name; }

bool Task::getIsChecked() const { return m_isChecked; }

void Task::setIsChecked(const bool isChecked) { m_isChecked = isChecked; }
