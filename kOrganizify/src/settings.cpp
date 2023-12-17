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

    const QJsonValue jsonValue = m_jsonObject["settings"];
    m_color = jsonValue["color"].toString();
    m_notifications = jsonValue["notificatios"].toBool(false);
    m_nightMode = jsonValue["nightMode"].toBool(false);

    qDebug() << m_color << m_notifications << m_nightMode;
}

void Settings::saveData(const QString &username) {
    QJsonObject jsonObject;
    jsonObject["color"] = m_color;
    jsonObject["notifications"] = m_notifications;
    jsonObject["nightMode"] = m_nightMode;

    m_jsonObject["settings"] = jsonObject;
    SaveLoad::saveData(username);
}


QString Settings::color() {
    return this->m_color;
}

void Settings::setColor(QString color) {
    this->m_color = color;
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


