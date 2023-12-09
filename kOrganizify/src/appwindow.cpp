#include "appwindow.h"
#include "ui_appwindow.h"
#include "settingswindow.h"

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppWindow)
{
    ui->setupUi(this);

    connect(ui->btnSettings, &QPushButton::clicked, this, &AppWindow::on_btnSettings_clicked);
}

void AppWindow::on_btnSettings_clicked()
{
    SettingsWindow *settingsWindow = new SettingsWindow(this);
    settingsWindow->show();
}

AppWindow::~AppWindow()
{
    delete ui;
}
