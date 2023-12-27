#include "syncresponsewindow.h"
#include "ui_syncresponsewindow.h"

SyncResponseWindow::SyncResponseWindow(QString friendName, QString title, int duration, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SyncResponseWindow),
    m_friendName(friendName)
{
    ui->setupUi(this);

    ui->lblDuration->setText(QString::number(duration) + " hours");
    ui->lblEventTitle->setText(title);
    ui->lblTitle->setText("Hey, " + friendName + " wants to sync with you");

    // connect(ui->le_nameInput, &QLineEdit::textChanged, this, &SyncWindow::onTextEntered);
    // connect(ui->cb_selectHours, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SyncWindow::onNumberSelected);
    // connect(ui->btn_sync, &QPushButton::clicked, this, &SyncWindow::onSyncButtonClicked);
    connect(ui->btnNo, &QPushButton::clicked, this, &SyncResponseWindow::sendNo);
    connect(ui->btnYes, &QPushButton::clicked, this, &SyncResponseWindow::sendYes);
}

SyncResponseWindow::~SyncResponseWindow()
{
    delete ui;
}

void SyncResponseWindow::sendYes() {
    emit yesResponse(m_friendName);
    close();
}

void SyncResponseWindow::sendNo() {
    emit noResponse(m_friendName);
    close();
}
