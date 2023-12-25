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
    QString getColor();
    Ui::SettingsWindow *ui;

private slots:
    QString getColorNameFromValue(const QMap<QString, QString> &colorMap, const QString &value);
    void on_btnSave_clicked();

signals:
    void colorChanged(const QString& color);

private:
    Settings *m_settings;
};

#endif // SETTINGSWINDOW_H
