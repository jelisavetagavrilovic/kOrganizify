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
    void setColor(QString color);
    void setBackgroundPath(QString backgroundPath);
    QString getColor();
    QString getBackgroundPath();
    QString textToColor(const QString text);
    QString textToPath(const QString text);
    QString colorToPath(const QString color);
    Ui::SettingsWindow *ui;

public slots:
    void changeColor(QString color);
//    void setColorSlot(const QString color);
//    QString getColorSlot() const;
    void setNotifications(const bool notifications);
    bool getNotifications() const;

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
