#include "appwindow.h"
#include "ui_appwindow.h"
#include "settingswindow.h"
#include <QPixmap>
#include <QDir>
#include <QScrollBar>
#include <QCheckBox>

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
    connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask); // for Enter button
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

void AppWindow::addTask()
{
    const auto text = ui->leInput->text();

    if(!text.isEmpty()){
        Task task(text);
        ui->leInput->clear();

        this->m_toDoList.addTask(task);

        QListWidgetItem *item = new QListWidgetItem();
        ui->lwToDoList->addItem(item);

        QCheckBox *checkBox = new QCheckBox(task.getName());
        ui->lwToDoList->setItemWidget(item, checkBox);

        connect(checkBox, &QCheckBox::stateChanged, this, &AppWindow::onCheckBoxStateChanged);
    }
}

void AppWindow::onCheckBoxStateChanged(int state)
{
    QCheckBox *checkBox = qobject_cast<QCheckBox*>(sender());
    if (checkBox && state == Qt::Checked) {
        QString taskName = checkBox->text();

        this->m_toDoList.removeTask(taskName);

        // Uklanjanje elementa iz QListWidget-a
        QListWidgetItem *item = ui->lwToDoList->itemAt(checkBox->pos());
        if (item != nullptr) {
            int row = ui->lwToDoList->row(item);
            ui->lwToDoList->takeItem(row);
            delete item;
        }
    }
}

AppWindow::~AppWindow()
{
    delete ui;
}
