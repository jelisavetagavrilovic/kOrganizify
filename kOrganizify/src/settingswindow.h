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

public slots:
    void changeColor(QString color);

private slots:
    void on_btnSave_clicked();

signals:
    void colorChanged(const QString& color);

private:
    Ui::SettingsWindow *ui;
    Settings *m_settings;
};

#endif // SETTINGSWINDOW_H
