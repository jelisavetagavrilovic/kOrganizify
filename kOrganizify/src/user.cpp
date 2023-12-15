#include "user.h"

User::User(const QString &username, const QString &password, SaveLoad *saveLoad, QObject *parent)
    : QObject(parent)
    , m_username(username)
    , m_password(password)
    , m_saveLoad(saveLoad)
{}

bool User::login(const QString &password)
{
    if (m_saveLoad->userExists(m_username)) {
        if (m_password == password) {
            qDebug() << "User" << m_username << "successfully logged in.";

            QJsonObject userData = m_saveLoad->loadData(m_username);
            if (!userData.isEmpty()) {
                updateUserData(userData);
            }

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

bool User::registerUser()
{
    if (m_saveLoad->userExists(m_username)) {
        qDebug() << "Registration failed. User already exists.";
        return false;
    } else {
        // Implement registration logic
        m_saveLoad->saveData(m_username, QJsonObject()); // Save an empty object for now
        qDebug() << "User" << m_username << "successfully registered and logged in.";
        login(m_password); // Automatically log in after registration
        return true;
    }
}

void User::logout()
{
    QJsonObject userData;
    // Fill userData with user-related data

    m_saveLoad->saveData(m_username, userData);
    qDebug() << "User" << m_username << "logged out.";
}

void User::updateUserData(const QJsonObject &userData)
{
    // Update user data in the application
    // For example: m_calendar = userData["calendar"].toObject();
    //              m_todoList = userData["todoList"].toObject();
    //              m_settings = userData["settings"].toObject();
}

SaveLoad* User::getSaveLoad() const
{
    return m_saveLoad;
}



