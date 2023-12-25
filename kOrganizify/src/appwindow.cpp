#include "appwindow.h"
#include "qlistwidget.h"
#include "ui_appwindow.h"
#include "settingswindow.h"
#include "mainwindow.h"

AppWindow::AppWindow(User *user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppWindow)
    , m_user(user)
{
    ui->setupUi(this);

    initialize();

    connect(ui->btnLogout, &QPushButton::clicked, this, &AppWindow::logoutUser);

    connect(ui->btnSettings, &QPushButton::clicked, this, &AppWindow::openSettings);
    connect(settingsWindow, &SettingsWindow::colorChanged, this, &AppWindow::changeButtonColor);
    connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask); // for Enter button
    connect(ui->btnClear, &QPushButton::clicked, this, &AppWindow::clearFinishedTasks);

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
    connect(ui->lwFriends, &QListWidget::itemClicked, this, &AppWindow::openSyncWindow);

    for (const QString& name : friends) {
        QListWidgetItem* item = new QListWidgetItem(name);
        ui->lwFriends->addItem(item);
    }
}

void AppWindow::openSyncWindow() {
    this->syncWindow = new SyncWindow();
    syncWindow->show();
}

void AppWindow::changeButtonColor(const QString& newColor) {
    QString styleSheet = "background-color: " + newColor + ";";
    this->ui->btnSettings->setStyleSheet(styleSheet);
    this->ui->leInput->setStyleSheet(styleSheet);
    this->ui->lblToDoList->setStyleSheet("color: " + newColor);
    this->ui->tableWidget->setStyleSheet(QString("QTableWidget::item { background-color: white; } QTableWidget{background-color: %1}").arg(newColor) + QString("QScrollBar:vertical { background-color: %1; }").arg(newColor));
    this->ui->tableWidget->horizontalHeader()->setStyleSheet(styleSheet);
    this->ui->tableWidget->verticalHeader()->setStyleSheet(styleSheet);
}

void AppWindow::initialize() {
    ToDoList& toDoList = m_user->getToDoList();
    const QVector<Task>& tasks = toDoList.getTasks();
    for (const Task& task : tasks)
        addTaskToListWidget(task);

    Settings& settings = m_user->getSettings();
    settingsWindow = new SettingsWindow(&settings, this);
    settingsWindow->setColor(settings.color());
    ui->lwToDoList->setStyleSheet("background-color: #FCD299");

    this->setFixedSize(this->size());
    this->setAutoFillBackground(true);

    m_calendar = new Calendar();
    this->eventWindow = new EventWindow(m_calendar);

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

    int columnWidth = 110;
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i)
        this->ui->tableWidget->setColumnWidth(i, columnWidth);


    connect(settingsWindow, &SettingsWindow::colorChanged, this, &AppWindow::changeButtonColor);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &AppWindow::openEventWindow);
    connect(this->eventWindow, &EventWindow::saveButtonClicked, this, &AppWindow::colorCell);
    connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask); // for Enter button
}

void AppWindow::openEventWindow(int row, int column) {
    if (row >= 0 && column >= 0) {
        this->eventWindow->show();
    }
}

void AppWindow::colorCell(){
    qDebug() << "Radi2";

    QString color = "#EB212E"; // boja bi valjalo da se menja na osnovu prioriteta dogadjaja
    QTableWidgetItem *item = new QTableWidgetItem("Ime dogadjaja");
    item->setBackground(QBrush(QColor(color)));
    ui->tableWidget->setItem(5, 0, item); // hardkodirano za sad

    // this->ui->tableWidget->item(1, 1)->setBackground(QBrush(color));
    // this->ui->tableWidget->setStyleSheet("background-color: " + color + ";");
}

void AppWindow::addTask()
{
    const auto text = ui->leInput->text();

    if(!text.isEmpty()){
        Task task(text);
        ui->leInput->clear();

        this->m_user->getToDoList().addTask(task);
        addTaskToListWidget(task);
    }
}

void AppWindow::addTaskToListWidget(const Task &task) {
    QListWidgetItem *item = new QListWidgetItem();
    ui->lwToDoList->addItem(item);

    QCheckBox *checkBox = new QCheckBox(task.getName());
    ui->lwToDoList->setItemWidget(item, checkBox);

    QFont font;
    font.setPointSize(15); // Postavljanje veličine fonta na 20 piksela za čekboks tekst
    checkBox->setFont(font);
    checkBox->setText(task.getName());
    checkBox->setStyleSheet("color: black;");
    checkBox->

    connect(checkBox, &QCheckBox::stateChanged, this, &AppWindow::onCheckBoxStateChanged);
}

void AppWindow::onCheckBoxStateChanged(int state) {
    QCheckBox *checkBox = qobject_cast<QCheckBox*>(sender());
    if (checkBox && state == Qt::Checked) {
        QString taskName = checkBox->text();
        QString newTaskName = "";
        for (auto ch : taskName)
        {
            newTaskName.append(QChar(0x0336));
            newTaskName.push_back(ch);
        }
        newTaskName.append(QChar(0x0336));

        checkBox->setText(newTaskName);  // crossed task name
    }
    else if (checkBox && state == Qt::Unchecked){
        QString taskName = checkBox->text();
        QString newTaskName = "";

        int i = 0;
        for (auto ch : taskName){
            if(i % 2 == 1)
                newTaskName.push_back(ch);
            i++;
        }
        checkBox->setText(newTaskName); // regular task name
    }
}

void AppWindow::clearFinishedTasks(){
    for (int i = ui->lwToDoList->count() - 1; i >= 0; --i) {
        QListWidgetItem* item = ui->lwToDoList->item(i);
        QWidget* widget = ui->lwToDoList->itemWidget(item);

        if (widget && widget->inherits("QCheckBox")) {
            QCheckBox* checkBox = static_cast<QCheckBox*>(widget);
            if (checkBox->isChecked()) {
                ui->lwToDoList->takeItem(i);
                delete item;
            }
        }
    }
}

void AppWindow::openSettings() {
    settingsWindow->show();
    QString styleSheet = QString("background-color: %1").arg(this->settingsWindow->getColor());
    this->ui->btnSettings->setStyleSheet(styleSheet);
    this->ui->btnSettings->update();
}

void AppWindow::logoutUser() {
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
    delete m_calendar;
}
