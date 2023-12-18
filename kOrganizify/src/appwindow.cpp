#include "appwindow.h"
#include "ui_appwindow.h"
#include "settingswindow.h"

#include <QPixmap>
#include <QCheckBox>
#include <QDir>
#include <QDir>
#include <QScrollBar>

AppWindow::AppWindow(User *user, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::AppWindow),
    m_user(user)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->setAutoFillBackground(true);

    this->settingsWindow = new SettingsWindow(this);
    this->settingsWindow->setColor("#0050B5");
    this->ui->lwToDoList->setStyleSheet("background-color: #FCD299");

    QString sourceDir = QCoreApplication::applicationDirPath();
    QString path = QDir(sourceDir).filePath("../kOrganizify/src/images/background1.jpg");
    QPixmap background(path);

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(palette);

    QString styleSheet = QString("background-color: %1").arg(this->settingsWindow->getColor());
    this->ui->btnSettings->setStyleSheet(styleSheet);
    this->ui->leInput->setStyleSheet(styleSheet);
    this->ui->lblToDoList->setStyleSheet("color: " + this->settingsWindow->getColor());

    // table
    this->ui->tableWidget->setStyleSheet(QString("QTableWidget::item { background-color: white; } QTableWidget{background-color: %1}").arg(this->settingsWindow->getColor()));
    this->ui->tableWidget->verticalScrollBar()->setStyleSheet("background-color: lightblue");
    this->ui->tableWidget->horizontalHeader()->setStyleSheet("background-color: " + this->settingsWindow->getColor());
    this->ui->tableWidget->verticalHeader()->setStyleSheet("background-color: " + this->settingsWindow->getColor());
    int rowHeight = 50;
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
        this->ui->tableWidget->setRowHeight(i, rowHeight);

    int columnWidth = 110;
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i)
        this->ui->tableWidget->setColumnWidth(i, columnWidth);

    connect(ui->btnLogout, &QPushButton::clicked, this, &AppWindow::logoutUser);
    // connect(ui->btnSettings, &QPushButton::clicked, this, &AppWindow::on_btnSettings_clicked);
    // connect(settingsWindow, &SettingsWindow::colorChanged, this, &AppWindow::changeButtonColor);
    // connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask); // for Enter button

    populateFriends(m_user->m_client->m_friends);
    connect(m_user->m_client, &Client::newUserLoggedIn, this, &AppWindow::handleNewUserLoggedIn);
    connect(m_user->m_client, &Client::disconnectedUser, this, &AppWindow::handleUserDisconnected);
}

void AppWindow::handleNewUserLoggedIn(const QString& username) {
    ui->lwFriends->addItem(username);
}

void AppWindow::handleUserDisconnected(const QString& username) {
    delete ui->lwFriends->findItems(username,Qt::MatchExactly)[0];
}

void AppWindow::populateFriends(const QList<QString>& friends) {
    ui->lwFriends->clear();

    for (const QString& name : friends) {
        QListWidgetItem* item = new QListWidgetItem(name);
        ui->lwFriends->addItem(item);
    }
}

void AppWindow::changeButtonColor(const QString& newColor) { // ovde se azuriraju boje elemenata ui-a
    QString styleSheet = "background-color: " + newColor + ";";
    this->ui->btnSettings->setStyleSheet(styleSheet);
    this->ui->leInput->setStyleSheet(styleSheet);
    this->ui->lblToDoList->setStyleSheet("color: " + newColor);
    this->ui->tableWidget->setStyleSheet(QString("QTableWidget::item { background-color: white; } QTableWidget{background-color: %1}").arg(newColor) + QString("QScrollBar:vertical { background-color: %1; }").arg(newColor));
    this->ui->tableWidget->horizontalHeader()->setStyleSheet(styleSheet);
    this->ui->tableWidget->verticalHeader()->setStyleSheet(styleSheet);

    // resizing cells
    int rowHeight = 50;
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
        this->ui->tableWidget->setRowHeight(i, rowHeight);

    int columnWidth = 110;
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i)
        this->ui->tableWidget->setColumnWidth(i, columnWidth);
}

void AppWindow::logoutUser() {

    // for (auto i : m_user->m_client->m_friends){
    //     qDebug() <<i;
    // }

    if (m_user) {
        m_user->logout();

        delete m_user;
        m_user = nullptr;
    }

    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
    this->close();
}

AppWindow::~AppWindow() {
    delete ui;
}
