#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings
{
public:
    Settings();
    Settings(QString color, bool notifications, bool nightmode);

    QString color();

    void setColor(QString color);
    void setNightmode(bool nightmode);
    void setNotifications(bool notifications);

    bool nightmode();
    bool notifications();

private:
    QString m_color;

    bool m_notifications;
    bool m_nightmode;
};

#endif // SETTINGS_H
