#include "settings.h"

Settings::Settings(QString color, bool notifications) {
  m_color = color;
  m_notifications = notifications;
}

void Settings::loadData(const QString &username) {
  SaveLoad::loadData(username);
  fromJson(m_jsonObject);
}

void Settings::fromJson(const QJsonObject &jsonObject) {
  m_jsonObject = jsonObject;

  QJsonObject jsonObjectSettings = m_jsonObject["settings"].toObject();
  m_color = jsonObjectSettings["color"].toString();
  m_notifications = jsonObjectSettings["notifications"].toBool();
}

auto Settings::toJson() const -> QJsonValue {
  QJsonObject jsonObject;
  jsonObject["color"] = m_color;
  jsonObject["notifications"] = m_notifications;

  return QJsonValue(jsonObject);
}

void Settings::saveData(const QString &username) {
  m_jsonObject = toJson().toObject();
  SaveLoad::saveData(username);
}

auto Settings::getColor() const -> QString { return m_color; }

void Settings::setColor(QString color) { m_color = color; }

auto Settings::backgroundPath() -> QString { return m_backgroundPath; }

void Settings::setBackgroundPath(QString backgroundPath) {
  m_backgroundPath = backgroundPath;
}

auto Settings::getNotifications() const -> bool { return m_notifications; }

void Settings::setNotifications(bool notifications) {
  m_notifications = notifications;
}
