#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(Settings *settings, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SettingsWindow)
    , m_settings(settings)
{
    ui->setupUi(this);

    QMap<QString, QString> themeColors {
        {"Blue", "#0050B5"},
        {"Green", "#006E33"},
        {"Orange", "#FE5000"},
        {"Pink", "#D62598"},
        {"Purple", "#9063CD"},
        {"Default", "#A5A9A0"}
    };

    QString currentColor = m_settings->getColor();
    ui->cbxDropTheme->setCurrentText(getColorNameFromValue(themeColors, currentColor));
    this->setColor(currentColor);

    connect(ui->cbxDropTheme, QOverload<const QString &>::of(&QComboBox::currentTextChanged), [=](const QString &text){
        QString color = themeColors.value(text, themeColors["Default"]);

        this->setColor(color);

        QString styleSheet = QString("background-color: %1").arg(color);
        ui->btnSave->setStyleSheet(styleSheet);
    });
}

void SettingsWindow::on_btnSave_clicked(){
    emit colorChanged(this->m_settings->getColor());
    this->close();
}

void SettingsWindow::setColor(QString color){
    this->m_settings->setColor(color);
}

QString SettingsWindow::getColor(){
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

SettingsWindow::~SettingsWindow()
{
    delete ui;
}
