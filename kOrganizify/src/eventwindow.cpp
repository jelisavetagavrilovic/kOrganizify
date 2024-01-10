#include "eventwindow.h"
#include "event.h"
#include "ui_eventwindow.h"
#include <QKeyEvent>
#include <QMessageBox>

EventWindow::EventWindow(Calendar *calendar, QWidget *parent)
    : QWidget(parent), ui(new Ui::EventWindow), m_calendar(calendar) {
  ui->setupUi(this);
  setWindowTitle("Event details");

  ui->leTitle->setFocus();

  ui->cbPriority->addItem("No Priority",
                          QVariant::fromValue(CustomEventPriority::NoPriority));
  ui->cbPriority->addItem("Low", QVariant::fromValue(CustomEventPriority::Low));
  ui->cbPriority->addItem("Medium",
                          QVariant::fromValue(CustomEventPriority::Medium));
  ui->cbPriority->addItem("High",
                          QVariant::fromValue(CustomEventPriority::High));

  connect(ui->btnSave, &QPushButton::clicked, this,
          &EventWindow::onSaveButtonClicked);
  connect(ui->btnDelete, &QPushButton::clicked, this,
          &EventWindow::onDeleteButtonClicked);
}

void EventWindow::setStartDate(const QDateTime &dateTime) {
  ui->deDateStart->setDateTime(dateTime);
  ui->teTimeStart->setDateTime(dateTime);
}

void EventWindow::setEndDate(const QDateTime &dateTime) {
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

void EventWindow::setPriority(const CustomEventPriority &priority) {
  ui->cbPriority->setCurrentIndex(static_cast<int>(priority));
}

void EventWindow::setCurrentEvent(const Event &event) {
  m_currentEvent = event;
}

Event EventWindow::getCurrentEvent() const { return m_currentEvent; }

bool EventWindow::isEventNull() const {
  return m_currentEvent.getTitle().isEmpty() &&
         m_currentEvent.getDescription().isEmpty() &&
         m_currentEvent.getLocation().isEmpty() &&
         !m_currentEvent.getStartTime().isValid() &&
         !m_currentEvent.getEndTime().isValid();
}

void EventWindow::onDeleteButtonClicked() {
  if (!isEventNull()) {
    m_calendar->removeEvent(m_currentEvent);
  }

  emit deleteButtonClicked();
  close();
}

void EventWindow::onSaveButtonClicked() {

  QString title = ui->leTitle->text();

  if (title.isEmpty()) {
    QMessageBox::critical(this, "Error", "Title cannot be empty.",
                          QMessageBox::Ok);
    return;
  }

  Event newEvent;

  newEvent.setTitle(title);
  newEvent.setDescription(ui->teDescription->toPlainText());
  newEvent.setLocation(ui->leLocation->text());

  QDateTime startDateTime(ui->deDateStart->date(), ui->teTimeStart->time());
  QDateTime endDateTime(ui->deDateEnd->date(), ui->teTimeEnd->time());

  if (endDateTime <= startDateTime) {
    QMessageBox::critical(this, "Error", "End time must be after start time.",
                          QMessageBox::Ok);
    return;
  }

  newEvent.setStartTime(startDateTime);
  newEvent.setEndTime(endDateTime);

  CustomEventPriority selectedPriority =
      ui->cbPriority->currentData().value<CustomEventPriority>();
  newEvent.setPriority(selectedPriority);

  if (!isEventNull() && !checkEventOverlap(newEvent)) {
    m_calendar->updateEvent(m_currentEvent, newEvent);
  } else if (checkEventOverlap(newEvent)) {
    QMessageBox::warning(this, "Error",
                         "The new event overlaps with existing events.");
    return;
  } else {
    m_calendar->addEvent(newEvent);
  }

  emit saveButtonClicked();
  close();
}

void EventWindow::changeColor(QString color) {
  QString styleSheet = QString("background-color: %1; ").arg(color);
  QString btnStyleSheet = QString("QPushButton{" + styleSheet +
                                  "border-radius: 10px; color:black;}");
  QString leStyleSheet = QString("QLineEdit{" + styleSheet + "}");
  QString teStyleSheet = QString("QTextEdit{" + styleSheet + "}");
  QString dateEditStyleSheet = QString("QDateEdit{" + styleSheet + "}");
  QString timeEditStyleSheet = QString("QTimeEdit{" + styleSheet + "}");
  QString ewStyleSheet =
      QString("QWidget{color: black; background-color: #F7F4F8;}");
  QString cbStyleSheet = QString("QComboBox{" + styleSheet + "}");

  QString ultimateStyleSheet = ewStyleSheet + btnStyleSheet + leStyleSheet +
                               teStyleSheet + dateEditStyleSheet +
                               timeEditStyleSheet + cbStyleSheet;

  setStyleSheet(ultimateStyleSheet);
}

bool EventWindow::checkEventOverlap(const Event &newEvent) {
  QList<Event> existingEvents = m_calendar->getEventsForWeek(
      newEvent.getStartTime().date(), newEvent.getEndTime().date().addDays(6));

  for (const Event &existingEvent : existingEvents) {
    if (existingEvent == newEvent) {
      continue;
    }
    if (existingEvent.overlapsWith(newEvent)) {
      return true;
    }
  }
  return false;
}

void EventWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
    onSaveButtonClicked();
  } else {
    QWidget::keyPressEvent(event);
  }
}

EventWindow::~EventWindow() { delete ui; }
