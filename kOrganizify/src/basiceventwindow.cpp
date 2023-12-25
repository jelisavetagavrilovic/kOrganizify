#include "basiceventwindow.h"
#include "ui_basiceventwindow.h"

BasicEventWindow::BasicEventWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BasicEventWindow)
{
    ui->setupUi(this);
}

BasicEventWindow::~BasicEventWindow()
{
    delete ui;
}
