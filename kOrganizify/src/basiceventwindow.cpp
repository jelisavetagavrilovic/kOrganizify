#include "basiceventwindow.h"
#include "ui_basiceventwindow.h"

BasicEventWindow::BasicEventWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BasicEventWindow)
{
    ui->setupUi(this);
    setWindowTitle("Smart plan");

    connect(ui->btnGenerate, &QPushButton::clicked, this, &BasicEventWindow::generate);
    connect(ui->btnNext, &QPushButton::clicked, this, &BasicEventWindow::nextEvent);
    connect(ui->btnPrevious, &QPushButton::clicked, this, &BasicEventWindow::previousEvent);
    connect(ui->btnRemove, &QPushButton::clicked, this, &BasicEventWindow::removeEvent);
}

void BasicEventWindow::nextEvent() {
    // qDebug() << "next";

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

    BasicEvent event;
    event.setTitle(title);
    event.setDuration(duration);

    ui->leTitle->clear();
    ui->leDuration->clear();
}


void BasicEventWindow::removeEvent() {

}

void BasicEventWindow::previousEvent() {

}


void BasicEventWindow::generate() {

}

BasicEventWindow::~BasicEventWindow()
{
    delete ui;
}
