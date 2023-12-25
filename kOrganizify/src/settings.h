#ifndef SETTINGS_H
#define SETTINGS_H

#include "saveload.h"
#include <QJsonObject>
#include <QJsonValue>

class Settings : public SaveLoad
{
private:
    QString m_color;

    bool m_notifications;
    bool m_nightMode;

public:
    explicit Settings(QString color, bool notifications, bool nightMode);
    explicit Settings();

    void loadData(const QString &username);
    void saveData(const QString &username);
    QJsonValue toJson() const override;
    void fromJson(const QJsonObject &jsonObject) override;

    QString color();
    void setColor(QString color);
    bool notifications();
    void setNotifications(bool notifications);
    bool nightMode();
    void setNightMode(bool nightMode);
};

#endif // SETTINGS_H
