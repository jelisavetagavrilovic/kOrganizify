#include "settings.h"

Settings::Settings(QString color, bool notifications, bool nightMode) {
    this->m_color = color;
    this->m_notifications = notifications;
    this->m_nightMode = nightMode;
}

Settings::Settings() {
    this->m_color = "#A5A9A0";
    this->m_notifications = false;
    this->m_nightMode = false;
}

void Settings::loadData(const QString &username) {
    SaveLoad::loadData(username);
    fromJson(m_jsonObject);
}

void Settings::fromJson(const QJsonObject &jsonObject) {
    m_jsonObject = jsonObject;

    QJsonObject jsonObjectSettings = m_jsonObject["settings"].toObject();
    m_color = jsonObjectSettings["color"].toString();
    m_notifications = jsonObjectSettings["notificatios"].toBool(false);
    m_nightMode = jsonObjectSettings["nightMode"].toBool(false);
}

QJsonValue Settings::toJson() const {
    QJsonObject jsonObject;
    jsonObject["color"] = m_color;
    jsonObject["notifications"] = m_notifications;
    jsonObject["nightMode"] = m_nightMode;

    return QJsonValue(jsonObject);
}

void Settings::saveData(const QString &username) {
    m_jsonObject = toJson().toObject();
    SaveLoad::saveData(username);
}


QString Settings::color() {
    return this->m_color;
}

void Settings::setColor(QString color) {
    this->m_color = color;
}

QString Settings::backgroundPath()
{
    return this->m_backgroundPath;
}

void Settings::setBackgroundPath(QString backgroundPath)
{
    this->m_backgroundPath = backgroundPath;
}

bool Settings::notifications() {
    return this->m_notifications;
}

void Settings::setNotifications(bool notifications) {
    this->m_notifications = notifications;
}

bool Settings::nightMode() {
    return this->m_nightMode;
}

void Settings::setNightMode(bool nightMode) {
    this->m_nightMode = nightMode;
}


