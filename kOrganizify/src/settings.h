// settings.h
#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>

enum Theme {
    Light,
    Dark,
    Custom
};

class Settings {
private:
    Theme m_theme;
    bool m_notifications;
    bool m_nightMode;

public:
    Settings();

    // getters
    Theme getTheme() const;
    bool getNotifications() const;
    bool getNightMode() const;

    // setters
    void setTheme(Theme newTheme);
    void toggleNotifications();
    void toggleNightMode();
};

#endif // SETTINGS_H
