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
    QString m_backgroundPath;

    bool m_notifications;

public:
    explicit Settings(QString color = "#A5A9A0", bool notifications = false);

    void loadData(const QString &username);
    void saveData(const QString &username);
    QJsonValue toJson() const override;
    void fromJson(const QJsonObject &jsonObject) override;

    QString getColor() const;
    void setColor(QString color);
    QString backgroundPath();
    void setBackgroundPath(QString backgroundPath);
    bool getNotifications() const;
    void setNotifications(bool notifications);
};

#endif // SETTINGS_H
