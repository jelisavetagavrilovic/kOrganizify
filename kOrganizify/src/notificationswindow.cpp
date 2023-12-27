#include "notificationswindow.h"
#include "ui_notificationswindow.h"

NotificationsWindow::NotificationsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationsWindow),
    m_mediaPlayer(new QSoundEffect())
{
    ui->setupUi(this);

    m_mediaPlayer->setSource(QUrl("qrc:/images/resources/notification.wav"));
    m_mediaPlayer->setVolume(50);
    m_mediaPlayer->setLoopCount(1);
}

void NotificationsWindow::updateWindow(const QString &name, const QString &time)
{
    ui->lbl_timeEvent->setText("Time: " + time);
    ui->lbl_nameEvent->setText("Name: " + name);

    show();
    m_mediaPlayer->play();
}

NotificationsWindow::~NotificationsWindow()
{
    delete ui;
}
