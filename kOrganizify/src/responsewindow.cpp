#include "responsewindow.h"
#include "ui_responsewindow.h"

ResponseWindow::ResponseWindow(QString eventTitle, QString startTime, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::ResponseWindow)
{
    ui->setupUi(this);

    setDate(startTime);
    setTitle(eventTitle);

    connect(ui->btnYes, &QPushButton::clicked, this, &ResponseWindow::onYesClicked);
    connect(ui->btnNo, &QPushButton::clicked, this, &ResponseWindow::onNoClicked);
}

ResponseWindow::~ResponseWindow() {
    delete ui;
}

void ResponseWindow::setTitle(QString title) {
    ui->lblQuestion->setText(title);
}

void ResponseWindow::setDate(QString startTime) {
    m_date = startTime;
    ui->lblDate->setText(startTime);
}

QString ResponseWindow::getDate() {
    return m_date;
}


void ResponseWindow::onYesClicked() {
    qDebug() << "I can on this date: " << getDate();
    emit sendResponse(true);
    close();
}

void ResponseWindow::onNoClicked() {
    qDebug() << "I cannot on this date: " << getDate();
    emit sendResponse(false);
    close();
}

void ResponseWindow::changeColor(QString color){
    QString styleSheet = QString("background-color: %1; ").arg(color);
    QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px; color:black;}");
    ui->btnYes->setStyleSheet(btnStyleSheet);
    ui->btnNo->setStyleSheet(btnStyleSheet);
}
