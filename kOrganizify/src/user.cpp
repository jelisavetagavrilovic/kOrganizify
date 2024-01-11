#include "user.h"

User::User(const QString &username, const QString &password)
    : m_username(username)
    , m_client(new Client(username))
{}

auto User::userExists(const QString &username) -> bool {
    return QFile(getFilePath(username)).exists();
}

void User::loadData(const QString &username) {
    SaveLoad::loadData(username);
    fromJson(m_jsonObject);
}

void User::fromJson(const QJsonObject &jsonObject) {
    m_password = jsonObject["password"].toString();
}

auto User::toJson() const -> QJsonValue {
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

auto User::login(const QString &password) -> bool {
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

auto User::registerUser(const QString &password) -> bool {
    if (userExists(m_username)) {
        return false;
    } else {
        m_password = password;
        login(m_password);
        return true;
    }
    return true;
}

void User::logout() {
    saveData(m_username);
    delete m_client;
}

auto User::getCalendar() -> Calendar& {
    return m_calendar;
}

auto User::getUsername() const -> QString {
    return m_username;
}

auto User::getToDoList() -> ToDoList& {
    return m_toDoList;
}

auto User::getSettings() -> Settings& {
    return m_settings;
}

void User::setCalendar(const Calendar& calendar) {
    m_calendar = calendar;
}
