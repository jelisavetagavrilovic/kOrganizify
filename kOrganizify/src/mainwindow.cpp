#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QCheckBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->leInput, &QLineEdit::returnPressed, this, &MainWindow::addTask); // for Enter button
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
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

        connect(checkBox, &QCheckBox::stateChanged, this, &MainWindow::onCheckBoxStateChanged);
    }
}

void MainWindow::onCheckBoxStateChanged(int state)
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








