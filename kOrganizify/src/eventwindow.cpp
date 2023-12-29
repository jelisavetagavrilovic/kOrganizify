#include "event.h"
#include "eventwindow.h"
#include "ui_eventwindow.h"
#include <QMessageBox>

EventWindow::EventWindow(Calendar* calendar, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EventWindow)
    , m_calendar(calendar)
{
    ui->setupUi(this);

    ui->cbPriority->addItem("No Priority", QVariant::fromValue(CustomEventPriority::NoPriority));
    ui->cbPriority->addItem("Low", QVariant::fromValue(CustomEventPriority::Low));
    ui->cbPriority->addItem("Medium", QVariant::fromValue(CustomEventPriority::Medium));
    ui->cbPriority->addItem("High", QVariant::fromValue(CustomEventPriority::High));

    connect(ui->btnSave, &QPushButton::clicked, this, &EventWindow::onSaveButtonClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &EventWindow::onDeleteButtonClicked);
}

void EventWindow::setStartDate(const QDateTime &dateTime){
    qDebug() << "SET START TIM: " << dateTime;
    ui->deDateStart->setDateTime(dateTime);
    ui->teTimeStart->setDateTime(dateTime);
}

void EventWindow::setEndDate(const QDateTime &dateTime){
    qDebug() << "SET END TIME: " << dateTime;
    ui->deDateEnd->setDateTime(dateTime);
    ui->teTimeEnd->setDateTime(dateTime);
}

void EventWindow::setTitle(const QString &title) {
    ui->leTitle->setText(title);
}

void EventWindow::setDescription(const QString &description) {
    ui->teDescription->setText(description);
}

void EventWindow::setLocation(const QString &location) {
    ui->leLocation->setText(location);
}


void EventWindow::setPriority(const CustomEventPriority &priority){
    ui->cbPriority->setCurrentIndex(static_cast<int>(priority));
}

void EventWindow::setCurrentEvent(const Event &event){
    m_currentEvent = event;
}

Event EventWindow::getCurrentEvent() const {
    return m_currentEvent;
}



bool EventWindow::isEventNull() const {
    return m_currentEvent.getTitle().isEmpty()
           && m_currentEvent.getDescription().isEmpty()
           && m_currentEvent.getLocation().isEmpty()
           && !m_currentEvent.getStartTime().isValid()
           && !m_currentEvent.getEndTime().isValid();
}

void EventWindow::onDeleteButtonClicked() {
    if (!isEventNull()) {
        m_calendar->removeEvent(m_currentEvent);
    }

    emit deleteButtonClicked();
    close();
}

void EventWindow::onSaveButtonClicked()
{
    Event newEvent;

    newEvent.setTitle(ui->leTitle->text());
    newEvent.setDescription(ui->teDescription->toPlainText());
    newEvent.setLocation(ui->leLocation->text());

    QDateTime startDateTime(ui->deDateStart->date(), ui->teTimeStart->time());
    QDateTime endDateTime(ui->deDateEnd->date(), ui->teTimeEnd->time());

    if (endDateTime <= startDateTime) {
        QMessageBox::critical(this, "Error", "End time must be after start time.", QMessageBox::Ok);
        return;
    }

    newEvent.setStartTime(startDateTime);
    newEvent.setEndTime(endDateTime);

    CustomEventPriority selectedPriority = ui->cbPriority->currentData().value<CustomEventPriority>();
    newEvent.setPriority(selectedPriority);

    if (!isEventNull()){
        m_calendar->updateEvent(m_currentEvent, newEvent);
    } else {
        m_calendar->addEvent(newEvent);
    }

    emit saveButtonClicked();

//    QList<Event> events = m_calendar->getEvents();
//    for (const Event &e : events) {
//<<<<<<< HEAD
//        qDebug() << "Event in calendar: " << e.getTitle();
//        if (e.getPriority() == CustomEventPriority::High) {
//            // Prioritet je High
//            qDebug() << "PHIGH";
//        } else if (e.getPriority() == CustomEventPriority::Medium) {
//            // Prioritet nije High
//            qDebug() << "MEDIUM";
//        } else if (e.getPriority() == CustomEventPriority::Low){
//            qDebug() << "LOW";
//        } else {
//            qDebug() << "No Priority";
//        }
//=======
////        qDebug() << "Event in calendar: " << e.getTitle();
//    }


//    QList<Event> weekEvents = m_calendar->getEventsForWeek(QDate(2000, 1, 1), QDate(2000, 1, 7));
//    for (const Event &e : weekEvents) {
////        qDebug() << "Event in weekly calendar: " << e.getTitle();
//>>>>>>> feature/smartPlan
//    }

    this->close();
}

void EventWindow::changeColor(QString color)
{
    QString styleSheet = QString("background-color: %1; ").arg(color);
    QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px; color:black;}");
    QString leStyleSheet = QString("QLineEdit{" + styleSheet + "}");
    QString teStyleSheet = QString("QTextEdit{" + styleSheet + "}");
    QString dateEditStyleSheet = QString("QDateEdit{" + styleSheet + "}");
    QString timeEditStyleSheet = QString("QTimeEdit{" + styleSheet + "}");
    QString ewStyleSheet = QString("QWidget{color: black; background-color: #F7F4F8;}");
    QString cbStyleSheet = QString("QComboBox{" + styleSheet + "}");

    QString ultimateStyleSheet = ewStyleSheet + btnStyleSheet + leStyleSheet + teStyleSheet + dateEditStyleSheet + timeEditStyleSheet + cbStyleSheet;

    this->setStyleSheet(ultimateStyleSheet);
}

EventWindow::~EventWindow()
{
    delete ui;
}

