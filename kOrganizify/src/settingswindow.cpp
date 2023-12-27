#include "settingswindow.h"
#include "ui_settingswindow.h"

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
    ui->lblNotificationsOn->setVisible(false);


//    QPalette btnSavePalette = ui->btnSave->palette();

    QMap<QString, QString> themeColors {
        {"Blue", "#0050B5"},
        {"Green", "#006E33"},
        {"Orange", "#FE5000"},
        {"Pink", "#D62598"},
        {"Purple", "#9063CD"},
        {"Default", "#A5A9A0"}
    };


    connect(ui->dropTheme, QOverload<const QString &>::of(&QComboBox::currentTextChanged), [=](const QString &text){
        QString color = themeColors.value(text, themeColors["Default"]);

        this->setColor(color);

        QString styleSheet = QString("background-color: %1; ").arg(color);
        QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px; color:black;}");
        this->ui->btnSave->setStyleSheet(btnStyleSheet);
        this->ui->dropTheme->setStyleSheet(QString("QComboBox{color: black; border-radius:10px; background-color: %1; }").arg(color));
    });
}

void SettingsWindow::on_btnSave_clicked(){
    emit colorChanged(this->m_settings->color());
    this->close();
}

void SettingsWindow::changeColor(QString color)
{
    QString styleSheet = QString("background-color: %1; ").arg(color);
    QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px; color:black;}");
    this->ui->btnSave->setStyleSheet(btnStyleSheet);
    this->ui->dropTheme->setStyleSheet(QString("QComboBox{color: black; border-radius:10px; background-color: %1; }").arg(color));
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
