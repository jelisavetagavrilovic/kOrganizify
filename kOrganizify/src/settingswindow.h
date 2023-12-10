// settingswindow.h
#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "ui_settingswindow.h"

#include <iostream>
#include <QMainWindow>
#include <QDialog>

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>


namespace Ui {
class SettingsWindow;
}

enum Theme {
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

public:
    SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
};

#endif // SETTINGSWINDOW_H
