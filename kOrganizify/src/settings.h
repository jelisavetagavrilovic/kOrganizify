#ifndef SETTINGS_H
#define SETTINGS_H

#include "saveload.h"
#include <QJsonObject>
#include <QJsonValue>

class Settings : public SaveLoad
{
    Q_OBJECT

public:
    explicit Settings(QString color = "#A5A9A0", bool notifications = false);

    bool getNotifications() const;
    void loadData(const QString &username);
    void saveData(const QString &username);
    void fromJson(const QJsonObject &jsonObject) override;
    void setColor(QString color);
    void setBackgroundPath(QString backgroundPath);
    void setNotifications(bool notifications);
    QJsonValue toJson() const override;
    QString getColor() const;
    QString backgroundPath();

private:
    QString m_color;
    QString m_backgroundPath;
    bool m_notifications;
};

#endif // SETTINGS_H
