#include "syncwindow.h"
#include "ui_syncwindow.h"
#include "settingswindow.h"
#include <QDebug>

SyncWindow::SyncWindow(QString username, QString friendName, Calendar calendar, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SyncWindow),
    m_selectedNumber(1),
    m_username(username),
    m_friendName(friendName),
    m_calendar(calendar)
{
    ui->setupUi(this);
    setWindowTitle("");
    setFixedSize(size());

    for (int i = 1; i <= 24; ++i) {
        ui->cbSelectHours->addItem(QString::number(i));
    }

    connect(ui->leNameInput, &QLineEdit::textChanged, this, &SyncWindow::onTextEntered);
    connect(ui->cbSelectHours, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SyncWindow::onNumberSelected);
    connect(ui->btnSync, &QPushButton::clicked, this, &SyncWindow::onSyncButtonClicked);
}

void SyncWindow::changeColor(QString color){
    QString styleSheet = QString("background-color: %1; ").arg(color);
    QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px; color:black;}");
    ui->btnSync->setStyleSheet(btnStyleSheet);
    ui->cbSelectHours->setStyleSheet(QString("QComboBox{color: black; border-radius:10px; background-color: %1; }").arg(color));
    ui->leNameInput->setStyleSheet(styleSheet + "color: black;");
}

SyncWindow::~SyncWindow()
{
    delete ui;
}

void SyncWindow::onTextEntered(const QString &m_text)
{
    m_enteredText = m_text;
}

void SyncWindow::onNumberSelected(int m_index)
{
    m_selectedNumber = m_index + 1;
}

QString SyncWindow::getEnteredText() const
{
    return m_enteredText;
}

int SyncWindow::getSelectedNumber() const
{
    return m_selectedNumber;
}

void SyncWindow::onSyncButtonClicked()
{
    emit sendSyncRequest(m_username, m_friendName, getEnteredText(), getSelectedNumber(), m_calendar);
    qDebug() << "Entered Text: " << getEnteredText();
    qDebug() << "Selected Number: " << getSelectedNumber();
    close();
}
