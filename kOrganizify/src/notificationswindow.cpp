#include "notificationswindow.h"
#include "ui_notificationswindow.h"

NotificationsWindow::NotificationsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationsWindow),
    mediaPlayer(new QSoundEffect())
{
    ui->setupUi(this);

//    mediaPlayer->setSource(QUrl::fromLocalFile(":/resources/notification.wav"));
//    mediaPlayer->setVolume(50);
//    mediaPlayer->setLoopCount(QSoundEffect::Infinite);

}

void NotificationsWindow::updateWindow(const QString &name, const QString &time)
{
    ui->lbl_timeEvent->setText("Time: " + time);
    ui->lbl_nameEvent->setText("Name: " + name);

//    mediaPlayer->play();
    show();
}

NotificationsWindow::~NotificationsWindow()
{
    delete ui;
}

