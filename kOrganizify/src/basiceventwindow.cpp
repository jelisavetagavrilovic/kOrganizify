#include "basiceventwindow.h"
#include "ui_basiceventwindow.h"

BasicEventWindow::BasicEventWindow(Calendar *calendar, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BasicEventWindow)
    , m_basicEvent(new BasicEvent())
    , m_calendar(calendar)
    , m_basicCalendar(new Calendar)
{
    ui->setupUi(this);
    setWindowTitle("Smart plan");

    // m_startIndex = m_calendar->size();
    m_currentIndex = 0;

    connect(ui->btnGenerate, &QPushButton::clicked, this, &BasicEventWindow::generate);
    connect(ui->btnNext, &QPushButton::clicked, this, &BasicEventWindow::nextEvent);
    connect(ui->btnPrevious, &QPushButton::clicked, this, &BasicEventWindow::previousEvent);
    connect(ui->btnRemove, &QPushButton::clicked, this, &BasicEventWindow::removeEvent);
}

bool BasicEventWindow::addEvent() {
    if (m_currentIndex == m_basicCalendar->sizeBasic()) {
        QString title = ui->leTitle->text();
        QString durationString = ui->leDuration->text();

        if (title.isEmpty() || durationString.isEmpty()) {
            QMessageBox::warning(this, "Warning", "Please enter the title and duration of the event");
            return false;
        }

        bool ok;
        int duration = durationString.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Warning", "Duration must be an integer number");
            return false;
        }

        m_basicEvent->setTitle(title);
        m_basicEvent->setDuration(duration);

        m_basicCalendar->addEvent(*m_basicEvent);
    }
    return true;
}

void BasicEventWindow::nextEvent() {
    if(addEvent())
        m_currentIndex++;

    updateUi();
}


void BasicEventWindow::removeEvent() {
    if (m_currentIndex >= 0  &&  m_currentIndex < m_basicCalendar->sizeBasic()) {
        m_basicCalendar->removeEvent(*m_basicEvent);

        m_currentIndex = std::max(0, m_currentIndex-1);
        updateUi();
    }
}

void BasicEventWindow::previousEvent() {
    if (m_currentIndex > 0) {
        if(addEvent())
            m_currentIndex--;

        updateUi();
    }
}

void BasicEventWindow::generate() {

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
