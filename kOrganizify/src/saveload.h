#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <QJsonObject>
#include <QObject>

class SaveLoad : public QObject {
  Q_OBJECT

public:
  explicit SaveLoad(QObject *parent = nullptr);
  QString getFilePath(const QString &username);
  QJsonObject m_jsonObject;
  void saveData(const QString &username);
  void loadData(const QString &username);
  virtual QJsonValue toJson() const = 0;
  virtual void fromJson(const QJsonObject &jsonObject) = 0;
};

#endif // SAVELOAD_H
