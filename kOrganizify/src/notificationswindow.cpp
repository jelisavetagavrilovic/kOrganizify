#include "notificationswindow.h"
#include "ui_notificationswindow.h"

NotificationsWindow::NotificationsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationsWindow)
{
    ui->setupUi(this);
}

void NotificationsWindow::updateWindow(const QString &name, const QString &time)
{
    ui->lbl_timeEvent->setText("Time: " + time);
    ui->lbl_nameEvent->setText("Name: " + name);

    show();
}

NotificationsWindow::~NotificationsWindow()
{
    delete ui;
}

