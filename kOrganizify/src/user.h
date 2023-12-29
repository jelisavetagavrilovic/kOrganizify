#ifndef USER_H
#define USER_H

#include "saveload.h"
#include "calendar.h"
#include "toDoList.h"
#include "settings.h"
#include "client.h"

#include <QString>
#include <QFile>
#include <QJsonValue>

class User : public SaveLoad
{
public:
    explicit User(const QString &username, const QString &password);
    bool userExists(const QString &username);

    void loadData(const QString &username);
    void saveData(const QString &username);
    QJsonValue toJson() const override;
    void fromJson(const QJsonObject &jsonValue) override;

    bool login(const QString &password);
    bool registerUser(const QString &password);
    void logout();
    Client *m_client;

    Calendar& getCalendar();
    ToDoList& getToDoList();
    Settings& getSettings();
    QString getUsername() const;

    void setCalendar(const Calendar& calendar);

private:
    QString m_username;
    QString m_password;
    Calendar m_calendar;
    ToDoList m_toDoList;
    Settings m_settings;
};

#endif // USER_H
