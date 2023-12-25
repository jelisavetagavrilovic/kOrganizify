#include "basiceventwindow.h"
#include "ui_basiceventwindow.h"

BasicEventWindow::BasicEventWindow(Calendar *calendar, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BasicEventWindow)
    , m_event(new BasicEvent())
    , m_calendar(calendar)
{
    ui->setupUi(this);
    setWindowTitle("Smart plan");

    m_startIndex = m_calendar->size();
    m_currentIndex = m_startIndex;

    connect(ui->btnGenerate, &QPushButton::clicked, this, &BasicEventWindow::generate);
    connect(ui->btnNext, &QPushButton::clicked, this, &BasicEventWindow::nextEvent);
    connect(ui->btnPrevious, &QPushButton::clicked, this, &BasicEventWindow::previousEvent);
    connect(ui->btnRemove, &QPushButton::clicked, this, &BasicEventWindow::removeEvent);
}

void BasicEventWindow::addEvent() {
     {
        if (m_currentIndex == m_calendar->size()) {
            qDebug() << "next if";
            QString title = ui->leTitle->text();
            QString durationString = ui->leDuration->text();

            if (title.isEmpty() || durationString.isEmpty()) {
                QMessageBox::warning(this, "Warning", "Please enter the title and duration of the event");
                return;
            }

            bool ok;
            int duration = durationString.toInt(&ok);
            if (!ok) {
                QMessageBox::warning(this, "Warning", "Duration must be an integer number");
                return;
            }

            m_event->setTitle(title);
            m_event->setDuration(duration);

            qDebug() << "addevent" << m_event->getTitle() << m_event->getDuration();

            m_calendar->addBasicEvent(*m_event);
            //m_calendar->print();
        }
    }
}

void BasicEventWindow::nextEvent() {
    // qDebug() << "next";
    // if (m_currentIndex < m_calendar->size()-1) {
    qDebug() << "next pocetak" << m_currentIndex << m_calendar->size();
    //if (m_currentIndex == m_calendar->size())

    addEvent();

    m_currentIndex++;
    qDebug() << "next kraj" << m_currentIndex << m_calendar->size();
    updateUi();
    // }
}


void BasicEventWindow::removeEvent() {
    if (m_currentIndex >= m_startIndex && m_currentIndex < m_calendar->size()) {
        m_calendar->removeEvent(m_calendar->getEvent(m_currentIndex));

        m_currentIndex = std::max(m_startIndex+1, m_currentIndex-1);
        updateUi();
    }
}

void BasicEventWindow::previousEvent() {
    if (m_currentIndex > m_startIndex) {

        qDebug() << "previus pocetak" << m_currentIndex;
        addEvent();

        m_currentIndex--;
        qDebug() << "previus kraj" << m_currentIndex;
        updateUi();
    }
}



void BasicEventWindow::generate() {

}

void BasicEventWindow::updateUi() {
    if (m_currentIndex >= m_startIndex && m_currentIndex < m_calendar->size()) {
        ui->leTitle->setText(m_calendar->getEvent(m_currentIndex).getTitle());
        ui->leDuration->setText(QString::number(m_calendar->getEvent(m_currentIndex).getDuration()));
    } else {
        // Postavite polja na prazne vrednosti kada nema događaja za prikaz
        ui->leTitle->clear();
        ui->leDuration->clear();
    }
}

BasicEventWindow::~BasicEventWindow()
{
    delete m_event;
    delete ui;
}
