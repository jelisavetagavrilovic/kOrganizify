#include "basiceventwindow.h"
#include "ui_basiceventwindow.h"

BasicEventWindow::BasicEventWindow(Calendar *calendar, QDate *startDate,
                                   QWidget *parent)
    : QDialog(parent), ui(new Ui::BasicEventWindow), m_calendar(calendar),
      m_basicEvent(new BasicEvent()), m_basicCalendar(new Calendar),
      m_startDate(startDate) {
  ui->setupUi(this);
  setWindowTitle("Smart plan");
  setFixedSize(size());

  m_currentIndex = 0;

  connect(ui->btnGenerate, &QPushButton::clicked, this,
          &BasicEventWindow::generate);
  connect(ui->btnNext, &QPushButton::clicked, this,
          &BasicEventWindow::nextEvent);
  connect(ui->btnPrevious, &QPushButton::clicked, this,
          &BasicEventWindow::previousEvent);
  connect(ui->btnRemove, &QPushButton::clicked, this,
          &BasicEventWindow::removeEvent);
  connect(ui->btnPreviousCalendar, &QPushButton::clicked, this,
          &BasicEventWindow::previousCalendar);
  connect(ui->btnNextCalendar, &QPushButton::clicked, this,
          &BasicEventWindow::nextCalendar);
}

bool BasicEventWindow::addEvent(const char op) {
  if (m_currentIndex == m_basicCalendar->sizeBasic()) {
    QString title = ui->leTitle->text();
    QString durationString = ui->leDuration->text();
    bool ok;
    int duration = durationString.toInt(&ok);

    if (op == 'n') {
      if (title.isEmpty() || durationString.isEmpty()) {
        QMessageBox::warning(
            this, "Warning",
            "Please enter the title and duration of the event");
        return false;
      }

      if (!ok) {
        QMessageBox::warning(this, "Warning",
                             "Duration must be an integer number");
        return false;
      }
    }

    m_basicEvent->setTitle(title);
    m_basicEvent->setDuration(duration);

    m_basicCalendar->addEvent(*m_basicEvent);
  }
  return true;
}

void BasicEventWindow::nextEvent() {
  if (addEvent('n'))
    m_currentIndex++;

  updateUi();
}

void BasicEventWindow::removeEvent() {
  if (m_currentIndex >= 0 && m_currentIndex < m_basicCalendar->sizeBasic()) {
    m_basicCalendar->removeEvent(*m_basicEvent);
    m_currentIndex = std::max(0, m_currentIndex - 1);
    updateUi();
    if (m_currentIndex == 0)
      nextEvent();
    else
      previousEvent();
  }
}

void BasicEventWindow::previousEvent() {
  if (m_currentIndex > 0) {
    if (addEvent('p'))
      m_currentIndex--;

    updateUi();
  }
}

void BasicEventWindow::generate() {
  if (addEvent('g')) {
    QTime startTime = ui->tePlanStartTime->time();
    QTime endTime = ui->tePlanEndTime->time();

    Calendar *tmp = new Calendar(*m_calendar);
    m_scheduler = new Scheduler(tmp, m_basicCalendar, m_startDate);
    m_scheduler->generateSchedule(startTime, endTime);
    m_listOfCalendars.append(tmp);

    for (int i = 0; i <= 10; i++) {
      tmp = new Calendar(*m_calendar);
      m_scheduler = new Scheduler(tmp, m_basicCalendar, m_startDate);
      m_scheduler->generateSchedule(startTime, endTime);
      m_listOfCalendars.append(tmp);
    }
  }

  m_currentCalendarIndex = 0;
}

void BasicEventWindow::previousCalendar() {
  if (m_currentCalendarIndex > 0) {
    m_currentCalendarIndex--;
    Calendar *previousCalendar = m_listOfCalendars[m_currentCalendarIndex];
    m_calendar = previousCalendar;
    emit previousCalendarSignal(m_calendar);
  }
}

void BasicEventWindow::nextCalendar() {
  if (m_currentCalendarIndex < m_listOfCalendars.size() - 1) {
    m_currentCalendarIndex++;
    Calendar *nextCalendar = m_listOfCalendars[m_currentCalendarIndex];
    m_calendar = nextCalendar;
    emit nextCalendarSignal(m_calendar);
  }
}

void BasicEventWindow::updateUi() {
  if (m_currentIndex >= 0 && m_currentIndex < m_basicCalendar->sizeBasic()) {
    ui->leTitle->setText(
        m_basicCalendar->getBasicEvent(m_currentIndex).getTitle());
    ui->leDuration->setText(QString::number(
        m_basicCalendar->getBasicEvent(m_currentIndex).getDuration()));
  } else {
    ui->leTitle->clear();
    ui->leDuration->clear();
  }
}

BasicEventWindow::~BasicEventWindow() {
  emit saveCalendar(m_calendar);
  delete m_basicEvent;
  delete m_basicCalendar;
  delete ui;
}

void BasicEventWindow::changeColor(QString color) {
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
