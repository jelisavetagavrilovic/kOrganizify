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
    // QJsonObject jsonObjectUsername;
    // jsonObjectUsername["username"] = m_username;

    // QJsonObject jsonObjectPassword;
    // jsonObjectPassword["password"] = m_password;

    // m_jsonObject["username"] = jsonObjectUsername;
    // m_jsonObject["password"] = jsonObjectPassword;

    SaveLoad::saveData(username);
}

bool User::login(const QString &password)
{
    if (userExists(m_username)) {
        loadData(m_username);
        if (m_password == password) {
            qDebug() << "User" << m_username << "successfully logged in.";

            // QJsonObject userData = loadData(m_username);
            // if (!userData.isEmpty()) {
            //     updateUserData(userData);
            // }

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
    // if (userExists(m_username)) {
    //     qDebug() << "Registration failed. User already exists.";
    //     return false;
    // } else {
    //     // Implement registration logic
    //     saveData(m_username, QJsonObject()); // Save an empty object for now
    //     qDebug() << "User" << m_username << "successfully registered and logged in.";
    //     login(m_password); // Automatically log in after registration
    //     return true;
    // }
    return true;
}

void User::logout()
{
    // QJsonObject userData;
    // // Fill userData with user-related data

    // saveData(m_username, userData);
    // qDebug() << "User" << m_username << "logged out.";
}

void User::updateUserData(const QJsonObject &userData)
{
    // Update user data in the application
    // For example: m_calendar = userData["calendar"].toObject();
    //              m_todoList = userData["todoList"].toObject();
    //              m_settings = userData["settings"].toObject();
}

// SaveLoad* User::getSaveLoad() const
// {
//     return m_saveLoad;
// }



