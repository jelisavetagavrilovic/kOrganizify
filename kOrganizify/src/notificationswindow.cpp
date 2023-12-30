#include "notificationswindow.h"
#include "ui_notificationswindow.h"

NotificationsWindow::NotificationsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationsWindow),
    m_mediaPlayer(new QSoundEffect())
{
    ui->setupUi(this);
    setFixedSize(size());
    setWindowTitle("Notification");

    m_mediaPlayer->setSource(QUrl("qrc:/resources/sound/notification.wav"));
    m_mediaPlayer->setVolume(50);
    m_mediaPlayer->setLoopCount(1);
}

void NotificationsWindow::updateWindow(const QString &name, const QString &time, const QString &location)
{
    ui->lblNameEvent->setText("30 min until: " + name);
    ui->lblLocationEvent->setText("Location: " + location);
    ui->lblTimeEvent->setText("At: " + time);

    show();
    m_mediaPlayer->play();
}

NotificationsWindow::~NotificationsWindow()
{
    delete ui;
}
