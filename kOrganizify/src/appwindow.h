#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "settingswindow.h"
#include "settingswindow.h"

namespace Ui {
class AppWindow;
}

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

    void changeButtonColor(const QString &newColor);
private slots:
    void on_btnSettings_clicked();

private:
    Ui::AppWindow *ui;
    SettingsWindow *settingsWindow;
};

#endif // APPWINDOW_H
