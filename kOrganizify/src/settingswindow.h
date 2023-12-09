// settingswindow.h
#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QDialog>

namespace Ui {
class SettingsWindow;
}

enum Theme {
    Light,
    Dark,
    Custom
};

class SettingsWindow : public QMainWindow {
    Q_OBJECT

private:
    Theme m_theme;
    bool m_notifications;
    bool m_nightMode;

    Ui::SettingsWindow *ui;
    QDialog *popupDialog;

private slots:
    void onThemeChanged(int index);
    void onNotificationsToggled(bool checked);
    void onNightModeToggled(bool checked);
    void onOpenPopupClicked();

public:
    SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();  // Provide the correct type specifier for the destructor

    SettingsWindow();  // It seems like you might want to declare a constructor here
};

#endif // SETTINGSWINDOW_H
