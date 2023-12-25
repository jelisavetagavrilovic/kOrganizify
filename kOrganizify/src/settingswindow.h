#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPalette>
#include <QMap>

#include "settings.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingsWindow(Settings *settings, QWidget *parent);
    ~SettingsWindow();
    void setColor(const QString color);
    QString getColor() const;
    void setNotifications(const bool notifications);
    bool getNotifications() const;
    Ui::SettingsWindow *ui;

private slots:
    QString getColorNameFromValue(const QMap<QString, QString> &colorMap, const QString &value);
    void save();

signals:
    void colorChanged(const QString& color);
    void enabledNotifications(const bool enabled);

private:
    Settings *m_settings;
};

#endif // SETTINGSWINDOW_H
