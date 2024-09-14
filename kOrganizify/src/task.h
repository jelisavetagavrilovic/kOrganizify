#ifndef TASK_H
#define TASK_H
#include <QString>

class Task {
private:
  QString m_name;
  bool m_isChecked;

public:
  Task();
  Task(QString name);
  QString getName() const;

  void setName(const QString newName);
  bool getIsChecked() const;
  void setIsChecked(const bool isChecked);
};

#endif // TASK_H
