#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SettingsWindow)
    , settings(new Settings)
{
    ui->setupUi(this);

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

        QString styleSheet = QString("background-color: %1").arg(color);
        ui->btnSave->setStyleSheet(styleSheet);
    });
}

void SettingsWindow::on_btnSave_clicked(){
    emit colorChanged(this->settings->color());
    this->close();
}

void SettingsWindow::setColor(QString color){
    this->settings->setColor(color);
}

QString SettingsWindow::getColor(){
    return this->settings->color();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}
