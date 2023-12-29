#include "user.h"

User::User(const QString &username, const QString &password)
    : m_username(username)
    , m_client(new Client(username))
{}

bool User::userExists(const QString &username) {
    return QFile(getFilePath(username)).exists();
}

void User::loadData(const QString &username) {
    SaveLoad::loadData(username);
    fromJson(m_jsonObject);
}

void User::fromJson(const QJsonObject &jsonObject) {
    m_password = jsonObject["password"].toString();
}

QJsonValue User::toJson() const {
    QJsonObject jsonObject;
    jsonObject["username"] = m_username;
    jsonObject["password"] = m_password;
    jsonObject["events"] = m_calendar.toJson();
    jsonObject["tasks"] = m_toDoList.toJson();
    jsonObject["settings"] = m_settings.toJson();

    return QJsonValue(jsonObject);
}

void User::saveData(const QString &username) {
    m_jsonObject = toJson().toObject();
    // QJsonObject a = toJson().toObject();
    SaveLoad::saveData(username);
}

bool User::login(const QString &password) {
    if (userExists(m_username)) {
        loadData(m_username);
        if (m_password == password) {

            m_calendar.fromJson(m_jsonObject);
            m_toDoList.fromJson(m_jsonObject);
            m_settings.fromJson(m_jsonObject);

            return true;
        }
    }
    return false;
}

bool User::registerUser(const QString &password) {
    if (userExists(m_username)) {
        return false;
    } else {
        // Implement registration logic
        m_password = password;
        qDebug() << "User" << m_username << "successfully registered and logged in.";
        login(m_password); // Automatically log in after registration
        return true;
    }
    return true;
}

void User::logout() {
    saveData(m_username);
}

Calendar& User::getCalendar() {
    return m_calendar;
}

QString User::getUsername() const {
    return m_username;
}

ToDoList& User::getToDoList() {
    return m_toDoList;
}

Settings& User::getSettings() {
    return m_settings;
}

void User::setCalendar(const Calendar& calendar) {
    m_calendar = calendar;
}
