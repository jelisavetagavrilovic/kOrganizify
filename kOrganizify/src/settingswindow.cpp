#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QPalette>

SettingsWindow::SettingsWindow(Settings *settings, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SettingsWindow)
    , m_settings(settings)
//,
    // m_theme(Custom),
    // m_notifications(true),
    // m_nightMode(false)
{
    ui->setupUi(this);

    // // Connect signals and slots
    // connect(ui->dropTheme, SIGNAL(currentIndexChanged(int)), this, SLOT(onThemeChanged(int)));
    // connect(ui->btnNotifications, SIGNAL(toggled(bool)), this, SLOT(onNotificationsToggled(bool)));
    // connect(ui->btnNightMode, SIGNAL(toggled(bool)), this, SLOT(onNightModeToggled(bool)));

    // // Initialize UI components based on current settings
    // ui->dropTheme->setCurrentIndex(static_cast<int>(m_theme));
    // ui->btnNotifications->setChecked(m_notifications);
    // ui->btnNightMode->setChecked(m_nightMode);


    // ui->btnSave->setStyleSheet(("background-color: %1").arg(this->settings->color()));
    QPalette btnSavePalette = ui->btnSave->palette();
    connect(ui->dropTheme, QOverload<const QString &>::of(&QComboBox::currentTextChanged), [=](const QString &text){

        QString color;
        if(text == "Blue"){
            color = "#0050B5";
        }
        else if(text == "Green"){
            color = "#006E33";
        }
        else if(text == "Orange"){
            color = "#FE5000";
        }
        else if(text == "Pink"){
            color = "#D62598";
        }
        else if(text == "Purple"){
            color = "#9063CD";
        }
        else{
            color = "#A5A9A0";
        }

        this->setColor(color);

        QString styleSheet = QString("background-color: %1").arg(color);
        ui->btnSave->setStyleSheet(styleSheet);
    });


}

void SettingsWindow::on_btnSave_clicked(){
    emit colorChanged(this->m_settings->color());
    this->close();
}

void SettingsWindow::setColor(QString color){
    this->m_settings->setColor(color);
}

QString SettingsWindow::getColor(){
    return this->m_settings->color();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

// void SettingsWindow::onThemeChanged(/*int index*/)
// {
//     // m_theme = static_cast<Theme>(index);
// }

// void SettingsWindow::onNotificationsToggled(/*bool checked*/)
// {
//     // m_notifications = checked;
// }

// void SettingsWindow::onNightModeToggled(/*bool checked*/)
// {
//     // m_nightMode = checked;
// }
