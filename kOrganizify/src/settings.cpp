#include "settings.h"

Settings::Settings() : m_theme(Light), m_notifications(true), m_nightMode(false) {}

Theme Settings::getTheme() const {
    return m_theme;
}

//getters
bool Settings::getNotifications() const {
    return m_notifications;
}

bool Settings::getNightMode() const {
    return m_nightMode;
}

//setters
void Settings::setTheme(Theme newTheme) {
    m_theme = newTheme;
}

void Settings::toggleNotifications() {
    m_notifications = !m_notifications;
}

void Settings::toggleNightMode() {
    m_nightMode = !m_nightMode;
}
