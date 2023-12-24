#ifndef SETTINGS_H
#define SETTINGS_H

#include "saveload.h"
#include <QJsonObject>
#include <QJsonValue>

class Settings : public SaveLoad
{
    Q_OBJECT
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

    QString getColor();
    void setColor(QString color);
    bool getNotifications();
    void setNotifications(bool notifications);
    bool getNightMode();
    void setNightMode(bool nightMode);
};

#endif // SETTINGS_H
