#ifndef TASK_H
#define TASK_H
#include <QString>

class Task{
private:
    QString m_name;
public:
    Task(QString name);
    void setName(const QString newName);
    const QString getName();
    bool operator==(const Task &other) const;
};

#endif // TASK_H
