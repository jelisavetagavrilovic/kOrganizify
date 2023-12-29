#include "basiceventwindow.h"
#include "ui_basiceventwindow.h"
#include "appwindow.h"

BasicEventWindow::BasicEventWindow(Calendar *calendar, QDate *startDate, QDate *endDate,  QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BasicEventWindow)
    , m_calendar(calendar)
    , m_basicEvent(new BasicEvent())
    , m_basicCalendar(new Calendar)
    , m_startDate(startDate)
    , m_endDate(endDate)
{
    ui->setupUi(this);
    setWindowTitle("Smart plan");

    m_currentIndex = 0;

    connect(ui->btnGenerate, &QPushButton::clicked, this, &BasicEventWindow::generate);
    connect(ui->btnNext, &QPushButton::clicked, this, &BasicEventWindow::nextEvent);
    connect(ui->btnPrevious, &QPushButton::clicked, this, &BasicEventWindow::previousEvent);
    connect(ui->btnRemove, &QPushButton::clicked, this, &BasicEventWindow::removeEvent);
}

bool BasicEventWindow::addEvent(const char op) {
    if (m_currentIndex == m_basicCalendar->sizeBasic()) {
        QString title = ui->leTitle->text();
        QString durationString = ui->leDuration->text();
        bool ok;
        int duration = durationString.toInt(&ok);

        if (op == 'n') {
            if (title.isEmpty() || durationString.isEmpty()) {
                QMessageBox::warning(this, "Warning", "Please enter the title and duration of the event");
                return false;
            }

            if (!ok) {
                QMessageBox::warning(this, "Warning", "Duration must be an integer number");
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
    if(addEvent('n'))
        m_currentIndex++;

    updateUi();
}

void BasicEventWindow::removeEvent() {
    if (m_currentIndex >= 0  &&  m_currentIndex < m_basicCalendar->sizeBasic()) {
        m_basicCalendar->removeEvent(*m_basicEvent);

        m_currentIndex = std::max(0, m_currentIndex-1);
        updateUi();
        if (m_currentIndex == 0)
            nextEvent();
        else
            previousEvent();
    }
}

void BasicEventWindow::previousEvent() {
    if (m_currentIndex > 0) {
        if(addEvent('p'))
            m_currentIndex--;

        updateUi();
    }
}

void BasicEventWindow::print() {
//    for (int i = 0; i < m_basicCalendar->sizeBasic(); i++)
//        qDebug() << m_basicCalendar->getBasicEvent(i).getTitle() << m_basicCalendar->getBasicEvent(i).getDuration();
}


void BasicEventWindow::generate() {
    if(addEvent('g')) {
        QTime startTime = ui->tePlanStartTime->time();
        QTime endTime = ui->tePlanEndTime->time();

        Calendar* tmp = new Calendar(*m_calendar);
        m_scheduler = new Scheduler(tmp, m_basicCalendar);
        m_scheduler->generateSchedule(startTime, endTime);
        m_listOfCalendars.append(tmp);

        for (int i = 0; i <= 10; i++) {
            tmp = new Calendar;
            m_cal = m_calendar->getEvents();
            m_basicCal = m_basicCalendar->getEvents();

            auto it = std::remove_if(m_cal.begin(), m_cal.end(), [this](const Event& calEvent) {
                const QString& calEventName = calEvent.getTitle();
                return std::any_of(m_basicCal.begin(), m_basicCal.end(), [&calEventName](const Event& basicEvent) {
                    return basicEvent.getTitle() == calEventName;
                });
            });
            m_cal.erase(it, m_cal.end());

            for(Event& e : m_cal)
                tmp->addEvent(e);

            m_scheduler = new Scheduler(tmp, m_basicCalendar);
            m_scheduler->generateSchedule(startTime, endTime);
            m_listOfCalendars.append(tmp);
        }
    }
}

void BasicEventWindow::updateUi() {
    if (m_currentIndex >= 0 && m_currentIndex < m_basicCalendar->sizeBasic()) {
        ui->leTitle->setText(m_basicCalendar->getBasicEvent(m_currentIndex).getTitle());
        ui->leDuration->setText(QString::number(m_basicCalendar->getBasicEvent(m_currentIndex).getDuration()));
    } else {
        ui->leTitle->clear();
        ui->leDuration->clear();
    }
}

BasicEventWindow::~BasicEventWindow()
{
    delete m_basicEvent;
    delete m_basicCalendar;
    delete ui;
}
