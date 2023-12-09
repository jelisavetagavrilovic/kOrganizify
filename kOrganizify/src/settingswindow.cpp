// settingswindow.cpp
#include "settingswindow.h"
#include "./ui_settingswindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

SettingsWindow::SettingsWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::SettingsWindow),
    popupDialog(new QDialog(this)),
    m_theme(Custom),
    m_notifications(true),
    m_nightMode(false)
{
    ui->setupUi(this);

    // Connect signals and slots
    connect(ui->dropTheme, SIGNAL(currentIndexChanged(int)), this, SLOT(onThemeChanged(int)));
    connect(ui->btnNotifications, SIGNAL(toggled(bool)), this, SLOT(onNotificationsToggled(bool)));
    connect(ui->btnNightMode, SIGNAL(toggled(bool)), this, SLOT(onNightModeToggled(bool)));

    // Initialize UI components based on current settings
    ui->dropTheme->setCurrentIndex(static_cast<int>(m_theme));
    ui->btnNotifications->setChecked(m_notifications);
    ui->btnNightMode->setChecked(m_nightMode);

    // Initialize the pop-up dialog
    QVBoxLayout *layout = new QVBoxLayout(popupDialog);
    QLabel *popupLabel = new QLabel("This is the settings pop-up", popupDialog);
    QPushButton *closeButton = new QPushButton("Close", popupDialog);

    layout->addWidget(popupLabel);
    layout->addWidget(closeButton);

    connect(closeButton, SIGNAL(clicked()), popupDialog, SLOT(close()));
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::onThemeChanged(int index)
{
    m_theme = static_cast<Theme>(index);
}

void SettingsWindow::onNotificationsToggled(bool checked)
{
    m_notifications = checked;
}

void SettingsWindow::onNightModeToggled(bool checked)
{
    m_nightMode = checked;
}

void SettingsWindow::onOpenPopupClicked()
{
    popupDialog->show();
}
