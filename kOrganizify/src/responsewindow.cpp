#include "responsewindow.h"
#include "ui_responsewindow.h"

ResponseWindow::ResponseWindow(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::ResponseWindow)
{
    ui->setupUi(this);

    QString foundDate = "01-11-2023";
    this->setDate(foundDate);

    connect(ui->btnYes, &QPushButton::clicked, this, &ResponseWindow::onYesClicked);
    connect(ui->btnNo, &QPushButton::clicked, this, &ResponseWindow::onNoClicked);

}

ResponseWindow::~ResponseWindow() {
    delete ui;
}

void ResponseWindow::setDate(QString& foundDate) {
    m_date = foundDate;
    ui->lbl_Date->setText(foundDate);
}

QString ResponseWindow::getDate() {
    return m_date;
}


void ResponseWindow::onYesClicked() {
    qDebug() << "I can on this date: " << getDate();
    close();
}

void ResponseWindow::onNoClicked() {
    qDebug() << "I cannot on this date: " << getDate();
    close();
}
