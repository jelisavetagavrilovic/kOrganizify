#include "user.h"

User::User(const QString &username, const QString &password)
    : m_username(username)
{}

bool User::userExists(const QString &username) {
    return QFile(getFilePath(username)).exists();
}

void User::loadData(const QString &username) {
    SaveLoad::loadData(username);

    m_password = m_jsonObject["password"].toString();
    qDebug() << m_jsonObject;
}

void User::saveData(const QString &username) {
    m_jsonObject["username"] = m_username;
    m_jsonObject["password"] = m_password;

    SaveLoad::saveData(username);
}

bool User::login(const QString &password)
{
    if (userExists(m_username)) {
        loadData(m_username);
        if (m_password == password) {
            qDebug() << "User" << m_username << "successfully logged in.";

            m_calendar.loadData(m_username);
            for (const Event &event : m_calendar.getEvents()) {
                qDebug() << event.getTitle() << event.getStartTime() << event.getEndTime() <<
                     event.getDescription() << event.getLocation();
            }
            m_calendar.saveData(m_username);

            m_toDoList.loadData(m_username);
            m_settings.loadData(m_username);

            return true;
        } else {
            qDebug() << "Login failed. Check the password.";
            return false;
        }
    } else {
        qDebug() << "Login failed. User does not exist.";
        return false;
    }
}

bool User::registerUser(const QString &password)
{
    if (userExists(m_username)) {
        qDebug() << "Registration failed. User already exists.";
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

void User::logout()
{
    saveData(m_username);
    m_calendar.saveData(m_username);
    // m_toDoList.saveData(m_username);
    // m_settings.saveData(m_username);

    qDebug() << "User" << m_username << "logged out.";

    // Dodatne akcije koje želite izvršiti prilikom odjavljivanja
    // Na primer, postaviti prazne liste, brisati podatke iz memorije, itd.
    // m_calendar.clear();
    // m_toDoList.clear();
}

