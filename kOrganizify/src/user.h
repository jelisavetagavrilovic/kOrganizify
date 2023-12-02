#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include "saveload.h"

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(const QString &username, const QString &password, SaveLoad *saveLoad, QObject *parent = nullptr);
    SaveLoad* getSaveLoad() const;

public slots:
    bool login(const QString &password);
    void logout();
    bool registerUser();

private:
    QString m_username;
    QString m_password;
    SaveLoad *m_saveLoad;

    void updateUserData(const QJsonObject &userData);
};

#endif // USER_H
