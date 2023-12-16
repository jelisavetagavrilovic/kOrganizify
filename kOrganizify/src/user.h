#ifndef USER_H
#define USER_H

#include "saveload.h"
#include <QString>
#include <QFile>

class User : public SaveLoad
{

public:
    explicit User(const QString &username, const QString &password);
    bool userExists(const QString &username);
    void loadData(const QString &username);
    void saveData(const QString &username, const QJsonObject &data);

    bool login(const QString &password);
    void logout();
    bool registerUser();


private:
    QString m_username;
    QString m_password;

    void updateUserData(const QJsonObject &userData);

};

#endif // USER_H
