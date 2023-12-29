#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QDir>
#include <QMap>

SettingsWindow::SettingsWindow(Settings *settings, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SettingsWindow)
    , m_settings(settings)
{
    ui->setupUi(this);
    setWindowTitle("Settings");
    setFixedSize(this->size());


    if(this->getNotifications()){
        ui->lblNotificationsOn->setVisible(true);
        ui->lblNotificationsOff->setVisible(false);
    }
    else{
        ui->lblNotificationsOn->setVisible(false);
        ui->lblNotificationsOff->setVisible(true);
    }

    ui->cbxDropTheme->setCurrentText(colorToText(this->getColor()));

    connect(ui->cbNotifications, &QCheckBox::stateChanged, this, &SettingsWindow::updateNotificationIcon);
    connect(ui->cbxDropTheme, QOverload<const QString &>::of(&QComboBox::currentTextChanged), [=](const QString &text){
        QString color = this->textToColor(text);

        QString path = this->colorToPath(color);

        this->setColor(color);
        this->setBackgroundPath(path);

        QString styleSheet = QString("background-color: %1; ").arg(color);
        QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px; color:black;}");
        this->ui->btnSave->setStyleSheet(btnStyleSheet);
        this->ui->cbxDropTheme->setStyleSheet(QString("QComboBox{color: black; border-radius:10px; background-color: %1; }").arg(color));
    });

    connect(ui->btnSave, &QPushButton::clicked, this, &SettingsWindow::save);
}

void SettingsWindow::changeColor(QString color)
{
    QString styleSheet = QString("background-color: %1; ").arg(color);
    QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px; color:black;}");
    this->ui->btnSave->setStyleSheet(btnStyleSheet);
    this->ui->cbxDropTheme->setStyleSheet(QString("QComboBox{color: black; border-radius:10px; background-color: %1; }").arg(color));
}

void SettingsWindow::setBackgroundPath(QString backgroundPath)
{
    this->m_settings->setBackgroundPath(backgroundPath);
}

QString SettingsWindow::getBackgroundPath()
{
    return this->m_settings->backgroundPath();
}

QString SettingsWindow::textToColor(QString text)
{
    return this->m_themeColors.value(text);
}

QString SettingsWindow::textToPath(QString text)
{
    QString sourceDir = QCoreApplication::applicationDirPath();
    QString pathBlue = QDir(sourceDir).filePath(":/images/images/backgroundBlue.png");
    QString pathGreen = QDir(sourceDir).filePath(":/images/images/backgroundGreen.png");
    QString pathOrange = QDir(sourceDir).filePath(":/images/images/backgroundOrange.png");
    QString pathPink = QDir(sourceDir).filePath(":/images/images/backgroundPink.png");
    QString pathPurple = QDir(sourceDir).filePath(":/images/images/backgroundPurple.png");
    QString pathDefault = QDir(sourceDir).filePath(":/images/images/backgroundDefault.png");

    QMap<QString, QString> themeBackgrounds {
        {"Blue", pathBlue},
        {"Green", pathGreen},
        {"Orange", pathOrange},
        {"Pink", pathPink},
        {"Purple", pathPurple},
        {"Default", pathDefault}
    };

    return themeBackgrounds.value(text, themeBackgrounds["Default"]);
}

QString SettingsWindow::colorToPath(QString color)
{
    return this->textToPath(colorToText(color));
}

QString SettingsWindow::colorToText(QString color)
{
    return this->m_themeColors.key(color);
}

void SettingsWindow::save() {
    emit colorChanged(this->m_settings->getColor());
    emit enabledNotifications(this->ui->cbNotifications->isChecked());
    this->close();
}

void SettingsWindow::setColor(const QString color) {
    this->m_settings->setColor(color);
}

QString SettingsWindow::getColor()  {
    return this->m_settings->getColor();
}


QString SettingsWindow::getColorNameFromValue(const QMap<QString, QString> &colorMap, const QString &value) {
    for (auto it = colorMap.begin(); it != colorMap.end(); ++it) {
        if (it.value() == value) {
            return it.key();
        }
    }
    return "";
}

void SettingsWindow::setNotifications(const bool notification) {
    this->m_settings->setNotifications(notification);
}

bool SettingsWindow::getNotifications() const {
    return this->m_settings->getNotifications();
}

void SettingsWindow::updateNotificationIcon(bool state){
    if(state){
        ui->lblNotificationsOn->setVisible(true);
        ui->lblNotificationsOff->setVisible(false);
    }
    else{
        ui->lblNotificationsOn->setVisible(false);
        ui->lblNotificationsOff->setVisible(true);
    }
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}
