#include "event.h"
#include "eventwindow.h"
#include "ui_eventwindow.h"

EventWindow::EventWindow(Calendar* calendar, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EventWindow)
    , m_calendar(calendar)
{
    ui->setupUi(this);
    connect(ui->btnSave, &QPushButton::clicked, this, &EventWindow::onSaveButtonClicked);
}

void EventWindow::onSaveButtonClicked()
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

    m_calendar->addEvent(event);

    emit saveButtonClicked();

    QList<Event> events = m_calendar->getEvents();
    for (const Event &e : events) {
        qDebug() << "Event in calendar: " << e.getTitle();
    }

    qDebug() << "Event saved to calendar: " << event.getTitle();

    QList<Event> weekEvents = m_calendar->getEventsForWeek(QDate(2000, 1, 1), QDate(2000, 1, 7));
    for (const Event &e : weekEvents) {
        qDebug() << "Event in weekly calendar: " << e.getTitle();
    }

    this->close();

    //qDebug() << "title: " << event.getTitle();
    //qDebug() << "start date and time: " << event.getStartTime();
    //qDebug() << "end date and time: " << event.getEndTime();
    //qDebug() << "description: " << event.getDescription();
    //qDebug() << "location: " << event.getLocation();
}

void EventWindow::setDateAndTime(const QDateTime &dateTime){
    ui->deDateStart->setDateTime(dateTime);
    ui->teTimeStart->setDateTime(dateTime);
    ui->deDateEnd->setDateTime(dateTime);
    ui->teTimeEnd->setDateTime(dateTime.addSecs(3600));
}

EventWindow::~EventWindow()
{
    delete ui;
}
