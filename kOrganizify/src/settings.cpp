#include "settings.h"

Settings::Settings(QString color, bool notifications, bool nightMode) {
    m_color = color;
    m_notifications = notifications;
    m_nightMode = nightMode;
}

Settings::Settings() {
    m_color = "#A5A9A0";
    m_notifications = false;
    m_nightMode = false;
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

QJsonValue Settings::toJson() const {
    QJsonObject jsonObject;
    jsonObject["color"] = m_color;
    jsonObject["notifications"] = m_notifications;

    return QJsonValue(jsonObject);
}

void Settings::saveData(const QString &username) {
    m_jsonObject = toJson().toObject();
    SaveLoad::saveData(username);
}


QString Settings::getColor() {
    return m_color;
}

void Settings::setColor(QString color) {
    m_color = color;
}

bool Settings::getNotifications() {
    return m_notifications;
}

void Settings::setNotifications(bool notifications) {
    m_notifications = notifications;
}

bool Settings::getNightMode() {
    return m_nightMode;
}

void Settings::setNightMode(bool nightMode) {
    m_nightMode = nightMode;
}


