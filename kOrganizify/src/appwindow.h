#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "settingswindow.h"
#include "eventwindow.h"

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
    void colorCell();
private slots:
    void on_btnSettings_clicked();
    void openEventWindow(int row, int column);


private:
    Ui::AppWindow *ui;
    SettingsWindow *settingsWindow;
    EventWindow *eventWindow;
};

#endif // APPWINDOW_H
