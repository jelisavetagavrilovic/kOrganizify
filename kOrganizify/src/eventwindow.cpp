#include "eventwindow.h"
#include "ui_eventwindow.h"

#include "event.h"

EventWindow::EventWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EventWindow)
{
    ui->setupUi(this);
}

void EventWindow::on_btnSave_clicked()
{
    // create new event
    Event event;

    event.setTitle(ui->leTitle->text());
    event.setDescription(ui->teDescription->toPlainText());
    event.setLocation(ui->leLocation->text());

    QDateTime startDateTime(ui->deDateStart->date(), ui->teTimeStart->time());
    QDateTime endDateTime(ui->deDateEnd->date(), ui->teTimeEnd->time());

    event.setStartTime(startDateTime);
    event.setEndTime(endDateTime);

    qDebug() << "title: " << event.getTitle();
    qDebug() << "start date and time: " << event.getStartTime();
    qDebug() << "end date and time: " << event.getEndTime();
    qDebug() << "description: " << event.getDescription();
    qDebug() << "location: " << event.getLocation();
}

EventWindow::~EventWindow()
{
    delete ui;
}
