#include "mainwindow.h"
#include "./ui_mainwindow.h"


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
    Task task(text);
    this->m_toDoList.addTask(task);
    ui->textEdit->setText(this->m_toDoList.toString());
    ui->leInput->clear();
}

