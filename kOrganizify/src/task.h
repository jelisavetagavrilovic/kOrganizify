#ifndef TASK_H
#define TASK_H
#include <QString>

class Task{
private:
    QString m_name;
    bool m_isChecked;


public:
    Task();
    Task(QString name);
    void setName(const QString newName);
    QString getName() const;
    bool operator==(const Task &other) const;

    bool getIsChecked() const;
    void setIsChecked(const bool isChecked);
};

#endif // TASK_H
