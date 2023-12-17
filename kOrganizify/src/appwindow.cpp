#include "appwindow.h"
#include "ui_appwindow.h"
#include "settingswindow.h"
#include <QPixmap>
#include <QDir>

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setAutoFillBackground(true);

    this->settingsWindow = new SettingsWindow(this);
    this->settingsWindow->setColor("#0050B5");
    this->ui->lwToDoList->setStyleSheet("background-color: #FCD299");

    QString sourceDir = QCoreApplication::applicationDirPath();
    QString path = QDir(sourceDir).filePath("../kOrganizify/src/images/background1.jpg");
    QPixmap background(path);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(palette);

    QString styleSheet = QString("background-color: %1").arg(this->settingsWindow->getColor());
    this->ui->btnSettings->setStyleSheet(styleSheet);
    this->ui->leInput->setStyleSheet(styleSheet);
    this->ui->lblToDoList->setStyleSheet("color: " + this->settingsWindow->getColor());
    this->ui->tableWidget->setStyleSheet("QTableWidget::item { background-color: white; }");



    connect(ui->btnSettings, &QPushButton::clicked, this, &AppWindow::on_btnSettings_clicked);
    connect(settingsWindow, &SettingsWindow::colorChanged, this, &AppWindow::changeButtonColor);
}

void AppWindow::changeButtonColor(const QString& newColor) { // ovde se azuriraju boje elemenata ui-a
    this->ui->btnSettings->setStyleSheet("background-color: " + newColor);
    this->ui->leInput->setStyleSheet("background-color: " + newColor);
    this->ui->lblToDoList->setStyleSheet("color: " + newColor);
    this->ui->tableWidget->horizontalHeader()->setStyleSheet("background-color: " + newColor);
    this->ui->tableWidget->verticalHeader()->setStyleSheet("background-color: " + newColor);

}

void AppWindow::on_btnSettings_clicked()
{
    if (this->settingsWindow && this->settingsWindow->isVisible()) {
        this->settingsWindow->activateWindow();
    } else {
        this->settingsWindow->show();
    }
    QString styleSheet = QString("background-color: %1").arg(this->settingsWindow->getColor());
    this->ui->btnSettings->setStyleSheet(styleSheet);
    this->ui->btnSettings->update();
}

AppWindow::~AppWindow()
{
    delete ui;
}
