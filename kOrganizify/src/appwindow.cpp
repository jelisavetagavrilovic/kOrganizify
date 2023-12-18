#include "appwindow.h"
#include "ui_appwindow.h"
#include "settingswindow.h"
#include <QPixmap>
#include <QDir>
#include <QScrollBar>

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

    Calendar calendar;
    this->eventWindow = new EventWindow(calendar);

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

    // table
    this->ui->tableWidget->setStyleSheet(QString("QTableWidget::item { background-color: white; } QTableWidget{background-color: %1}").arg(this->settingsWindow->getColor()));
    this->ui->tableWidget->verticalScrollBar()->setStyleSheet("background-color: lightblue");
    this->ui->tableWidget->horizontalHeader()->setStyleSheet("background-color: " + this->settingsWindow->getColor());
    this->ui->tableWidget->verticalHeader()->setStyleSheet("background-color: " + this->settingsWindow->getColor());
    int rowHeight = 50;
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
        this->ui->tableWidget->setRowHeight(i, rowHeight);

    int columnWidth = 110;
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i)
        this->ui->tableWidget->setColumnWidth(i, columnWidth);




    connect(ui->btnSettings, &QPushButton::clicked, this, &AppWindow::on_btnSettings_clicked);
    connect(settingsWindow, &SettingsWindow::colorChanged, this, &AppWindow::changeButtonColor);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &AppWindow::openEventWindow);

    connect(this->eventWindow, &EventWindow::saveButtonClicked, this, &AppWindow::colorCell);

}

void AppWindow::changeButtonColor(const QString& newColor) { // ovde se azuriraju boje elemenata ui-a
    QString styleSheet = "background-color: " + newColor + ";";
    this->ui->btnSettings->setStyleSheet(styleSheet);
    this->ui->leInput->setStyleSheet(styleSheet);
    this->ui->lblToDoList->setStyleSheet("color: " + newColor);
    this->ui->tableWidget->setStyleSheet(QString("QTableWidget{background-color: %1}").arg(newColor) + QString("QScrollBar:vertical { background-color: %1; }").arg(newColor));
    this->ui->tableWidget->horizontalHeader()->setStyleSheet(styleSheet);
    this->ui->tableWidget->verticalHeader()->setStyleSheet(styleSheet);

    // resizing cells
    int rowHeight = 50;
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
        this->ui->tableWidget->setRowHeight(i, rowHeight);

    int columnWidth = 110;
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i)
        this->ui->tableWidget->setColumnWidth(i, columnWidth);
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

void AppWindow::openEventWindow(int row, int column) {
    if (row >= 0 && column >= 0) {
        this->eventWindow->show();
    }
}

void AppWindow::colorCell(){
    qDebug() << "Radi2";

    QString color = "#EB212E"; // boja bi valjalo da se menja na osnovu prioriteta dogadjaja
    QTableWidgetItem *item = new QTableWidgetItem("Ime dogadjaja");
    item->setBackground(QBrush(QColor(color)));
    ui->tableWidget->setItem(5, 0, item); // hardkodirano za sad

    // this->ui->tableWidget->item(1, 1)->setBackground(QBrush(color));
    // this->ui->tableWidget->setStyleSheet("background-color: " + color + ";");
}

AppWindow::~AppWindow()
{
    delete ui;
}
