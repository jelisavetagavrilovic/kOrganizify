#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings
{
private:
    QString m_color;
    bool m_notifications;
    bool m_nightmode;

public:
    Settings(QString color, bool notifications, bool nightmode);
    Settings();
    QString color();
    void setColor(QString color);
    bool notifications();
    void setNotifications(bool notifications);
    bool nightmode();
    void setNightmode(bool nightmode);
};

#endif // SETTINGS_H
