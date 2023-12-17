#include "settings.h"

Settings::Settings()
{
    this->m_color = "#A5A9A0";
    this->m_notifications = false;
    this->m_nightmode = false;
}

Settings::Settings(QString color, bool notifications, bool nightmode)
{
    this->m_color = color;
    this->m_notifications = notifications;
    this->m_nightmode = nightmode;
}


QString Settings::color()
{
    return this->m_color;
}

void Settings::setColor(QString color)
{
    this->m_color = color;
}

bool Settings::notifications()
{
    return this->m_notifications;
}

void Settings::setNotifications(bool notifications)
{
    this->m_notifications = notifications;
}

bool Settings::nightmode()
{
    return this->m_nightmode;
}

void Settings::setNightmode(bool nightmode)
{
    this->m_nightmode = nightmode;
}


