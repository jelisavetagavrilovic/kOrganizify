#include "appwindow.h"
#include "qlistwidget.h"
#include "ui_appwindow.h"
#include "settingswindow.h"
#include "syncresponsewindow.h"
#include "mainwindow.h"
#include "ui_settingswindow.h"

AppWindow::AppWindow(User *user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppWindow)
    , m_user(user)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    initialize();

    connect(ui->btnLogout, &QPushButton::clicked, this, &AppWindow::logoutUser);
    connect(ui->btnSettings, &QPushButton::clicked, this, &AppWindow::openSettings);
    connect(settingsWindow, &SettingsWindow::enabledNotifications, this, &AppWindow::enabledNotifications);
    connect(settingsWindow, &SettingsWindow::enabledNotifications, m_notifications, &Notifications::enabledNotifications);
    connect(settingsWindow, &SettingsWindow::colorChanged, this, &AppWindow::changeButtonColor);
    connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask); // for Enter button
    connect(ui->btnClear, &QPushButton::clicked, this, &AppWindow::clearFinishedTasks);

    populateFriends(m_user->m_client->m_friends);
    connect(m_user->m_client, &Client::newUserLoggedIn, this, &AppWindow::handleNewUserLoggedIn);
    connect(m_user->m_client, &Client::disconnectedUser, this, &AppWindow::handleUserDisconnected);
    connect(m_user->m_client, &Client::showSyncWindow, this, &AppWindow::showSyncWindow);
    connect(m_user->m_client, &Client::syncRequestDenied, this, &AppWindow::syncDenied);
    connect(m_user->m_client, &Client::newEventSync, this, &AppWindow::showResponseWindow);
    connect(m_user->m_client, &Client::syncSuccess, this, &AppWindow::agreedSync);
}

void AppWindow::handleNewUserLoggedIn(const QString& username) {
    ui->lwFriends->addItem(username);
}

void AppWindow::handleUserDisconnected(const QString& username) {
    auto user = ui->lwFriends->findItems(username,Qt::MatchExactly);
    if (user.size() > 0) {
        delete user[0];
    }
}

void AppWindow::populateFriends(const QList<QString>& friends) {
    ui->lwFriends->clear();
    connect(ui->lwFriends, &QListWidget::itemClicked, this, &AppWindow::openSyncWindow);

    for (const QString& name : friends) {
        QListWidgetItem* item = new QListWidgetItem(name);
        ui->lwFriends->addItem(item);
    }
}

void AppWindow::openSyncWindow(QListWidgetItem *item) {
    this->syncWindow = new SyncWindow(m_user->getUsername(),item->text(), m_user->getCalendar());
    connect(syncWindow, &SyncWindow::sendSyncRequest, m_user->m_client, &Client::syncRequest);
    this->syncWindow->changeColor(settingsWindow->getColor());
    syncWindow->show();
}

void AppWindow::changeButtonColor(const QString& newColor) {
    QString styleSheet = "background-color: " + newColor + ";";
    QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px;}");
    this->ui->btnSettings->setStyleSheet(btnStyleSheet);
    this->ui->btnClear->setStyleSheet(btnStyleSheet);
    this->ui->btnLogout->setStyleSheet(btnStyleSheet);
    this->ui->btnSmartPlan->setStyleSheet(btnStyleSheet);
    this->ui->leInput->setStyleSheet(styleSheet);
    this->ui->lblToDoList->setStyleSheet("color: " + newColor);
    this->ui->tableWidget->setStyleSheet(QString("QTableWidget::item { background-color: white; } QTableWidget{background-color: %1}").arg(newColor));
    this->ui->tableWidget->horizontalHeader()->setStyleSheet(styleSheet);
    this->ui->tableWidget->verticalHeader()->setStyleSheet(styleSheet);
    this->ui->calendarWidget->setStyleSheet(QString("QCalendarWidget QWidget#qt_calendar_navigationbar { color: black; background-color: %1;}"
                                                    "QCalendarWidget QAbstractItemView:enabled {selection-background-color: %2 ;}").arg(newColor, newColor));


    QString backgroundPath = this->settingsWindow->colorToPath(newColor);
    QPixmap background(backgroundPath);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(palette);
}

void AppWindow::enabledNotifications(const bool enabled) {
    m_user->getSettings().setNotifications(enabled);
}

void AppWindow::initialize() {
    m_toDoList = &m_user->getToDoList();
    const QVector<Task>& tasks = m_toDoList->getTasks();
    for (const Task& task : tasks)
        addTaskToListWidget(task);

    Settings& settings = m_user->getSettings();
    settingsWindow = new SettingsWindow(&settings, this);

    settingsWindow->setColor(settings.getColor());
    settingsWindow->setBackgroundPath(settingsWindow->colorToPath(settingsWindow->getColor()));
    this->ui->lwToDoList->setStyleSheet("background-color: #FCD299");
    this->ui->lwFriends->setStyleSheet("background-color: #E5E1E6; color: black;");
    settingsWindow->ui->cbNotifications->setChecked(m_user->getSettings().getNotifications());
    ui->lwToDoList->setStyleSheet("background-color: #FCD299");

    this->setFixedSize(this->size());
    this->setAutoFillBackground(true);

    m_calendar = &m_user->getCalendar();
//    for (Event& e: m_calendar->getEvents()){
//        qDebug() << e.getStartTime();
//    }
    m_notifications = new Notifications(m_calendar);
//    m_notifications->checkEvents();
    this->eventWindow = new EventWindow(m_calendar);

    QString sourceDir = QCoreApplication::applicationDirPath();
    QString path = QDir(sourceDir).filePath(settingsWindow->getBackgroundPath());
    QPixmap background(path);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(palette);

    QString styleSheet = QString("background-color: %1; ").arg(this->settingsWindow->getColor());
    QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px; color:black;}");
    this->ui->btnSettings->setStyleSheet(btnStyleSheet);
    this->ui->btnClear->setStyleSheet(btnStyleSheet);
    this->ui->btnLogout->setStyleSheet(btnStyleSheet);
    this->ui->btnSmartPlan->setStyleSheet(btnStyleSheet);
    this->ui->leInput->setStyleSheet(styleSheet);
    this->ui->lblToDoList->setStyleSheet("color: " + this->settingsWindow->getColor());

    this->ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    this->ui->calendarWidget->setStyleSheet(QString("QCalendarWidget QWidget#qt_calendar_navigationbar {"
                                                    "   color: black; background-color: %1;}"
                                                    "QCalendarWidget QAbstractItemView:enabled {"
                                                    "   selection-background-color: %2 ;}"
                                                    "QCalendarWidget QToolButton:hover {"
                                                    "    background-color: #3C5291;" // Boja pozadine kada se pređe mišem preko datuma
                                                    "}").arg(this->settingsWindow->getColor(), this->settingsWindow->getColor()));
    // table
    this->ui->tableWidget->setStyleSheet(QString("QTableWidget::item { background-color: white; } QTableWidget{background-color: %1}").arg(this->settingsWindow->getColor()));
    this->ui->tableWidget->verticalScrollBar()->setStyleSheet("background-color: lightblue");
    this->ui->tableWidget->horizontalHeader()->setStyleSheet("background-color: " + this->settingsWindow->getColor());
    this->ui->tableWidget->verticalHeader()->setStyleSheet("background-color: " + this->settingsWindow->getColor());
    int columnWidth = 110;
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i)
        this->ui->tableWidget->setColumnWidth(i, columnWidth);
    int scrollBarValue = this->ui->tableWidget->verticalScrollBar()->maximum();
    this->ui->tableWidget->verticalScrollBar()->setValue(scrollBarValue);

    this->eventWindow->changeColor(this->settingsWindow->getColor());
    this->settingsWindow->changeColor(this->settingsWindow->getColor());

    connect(settingsWindow, &SettingsWindow::colorChanged, this, &AppWindow::changeButtonColor);
    connect(settingsWindow, &SettingsWindow::colorChanged, this->eventWindow, &EventWindow::changeColor);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &AppWindow::openEventWindowForCell);
    connect(eventWindow, &EventWindow::saveButtonClicked, this, &AppWindow::updateTableForSelectedDate);
    connect(eventWindow, &EventWindow::deleteButtonClicked, this, &AppWindow::updateTableForSelectedDate);
    connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask); // for Enter button
    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged, this, &AppWindow::updateTableForSelectedDate);
}

void AppWindow::openEventWindowForCell(int row, int column) {
    if (row >= 0 && column >= 0) {
        QDate selectedDate = ui->calendarWidget->selectedDate();
        QDate startDate = selectedDate.addDays(-selectedDate.dayOfWeek() + 1);
        QDateTime cellDateTime(startDate.addDays(column), QTime(row + 1, 0));

        QList<Event> weekEvents = m_calendar->getEventsForWeek(startDate, startDate.addDays(6));
        for(const Event &event: weekEvents){
            int startHour = event.getStartTime().time().hour();
            int endHour = event.getEndTime().time().hour();

            if(row >= startHour && row < endHour && column == event.getStartTime().date().dayOfWeek() - 1){
                eventWindow->setCurrentEvent(event);
                eventWindow->setStartDate(cellDateTime);
                eventWindow->setEndDate(cellDateTime.addSecs(3600 * (endHour - startHour)));
                eventWindow->setTitle(event.getTitle());
                eventWindow->setDescription(event.getDescription());
                eventWindow->setLocation(event.getLocation());

                eventWindow->show();
                return;
            }
        }

        eventWindow->setCurrentEvent(Event());
        eventWindow->setTitle("");
        eventWindow->setDescription("");
        eventWindow->setLocation("");
        eventWindow->setStartDate(cellDateTime);
        eventWindow->setEndDate(cellDateTime.addSecs(3600));
        eventWindow->show();
    }
}

void AppWindow::addTask() {
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
    font.setPointSize(10);

    checkBox->setFont(font);
    checkBox->setStyleSheet("color: black;");
    if (task.getIsChecked()) {
        checkBox->setText(crossTask(task.getName()));
        checkBox->setChecked(true);
    } else
        checkBox->setText(task.getName());

    connect(checkBox, &QCheckBox::stateChanged, this, &AppWindow::onCheckBoxStateChanged);
}

void AppWindow::onCheckBoxStateChanged(int state) {
    QCheckBox *checkBox = qobject_cast<QCheckBox*>(sender());
    if (checkBox) {
        int index = ui->lwToDoList->row(ui->lwToDoList->itemFromIndex(ui->lwToDoList->indexAt(checkBox->pos())));
        if (state == Qt::Checked) {
            m_toDoList->getTask(index)->setIsChecked(true);
            checkBox->setText(crossTask(m_toDoList->getTask(index)->getName()));  // crossed task name
        } else if (state == Qt::Unchecked) {
            m_toDoList->getTask(index)->setIsChecked(false);
            checkBox->setText(m_toDoList->getTask(index)->getName()); // regular task name
        }
    }
}

QString AppWindow::crossTask(const QString &taskName) {
    QString newTaskName = "";
    for (auto ch : taskName) {
        newTaskName.append(QChar(0x0336));
        newTaskName.push_back(ch);
    }
    newTaskName.append(QChar(0x0336));

    return newTaskName;
}

// void AppWindow::reorderCheckedTasks(){
//     QList<QListWidgetItem*> checkedItems;
//     QString text = "";

//     for (int i = ui->lwToDoList->count() - 1; i >= 0; --i) {
//         QListWidgetItem* item = ui->lwToDoList->item(i);
//         QWidget* widget = ui->lwToDoList->itemWidget(item);

//         if (widget && widget->inherits("QCheckBox")) {
//             QCheckBox* checkBox = static_cast<QCheckBox*>(widget);
//             if (checkBox->isChecked()) {

//                 text = checkBox->text();

//                 checkedItems.append(item);
//                 ui->lwToDoList->takeItem(i);
//                 --i;
//             }
//         }
//     }

//     if(!text.isEmpty()){
//         Task task(text);

//         this->m_user->getToDoList().addTask(task);
//         addTaskToListWidget(task);
//     }
// }

void AppWindow::clearFinishedTasks(){
    for (int i = ui->lwToDoList->count() - 1; i >= 0; --i) {
        QListWidgetItem* item = ui->lwToDoList->item(i);
        QWidget* widget = ui->lwToDoList->itemWidget(item);

        if (widget && widget->inherits("QCheckBox")) {
            QCheckBox* checkBox = static_cast<QCheckBox*>(widget);
            if (checkBox->isChecked()) {
                ui->lwToDoList->takeItem(i);
                delete item;

                m_toDoList->removeTask(i);
            }
        }
    }
}

void AppWindow::openSettings() {
    settingsWindow->show();
    QString styleSheet = QString("background-color: %1; ").arg(this->settingsWindow->getColor());
    QString btnStyleSheet = QString("QPushButton{" + styleSheet + "border-radius: 10px; color:black;}");
    this->ui->btnSettings->setStyleSheet(btnStyleSheet);
    this->ui->btnSettings->update();
}

void AppWindow::updateTableForSelectedDate() {
    QDate selectedDate = ui->calendarWidget->selectedDate();
    showWeeklyEvents(selectedDate);
}

void AppWindow::showWeeklyEvents(const QDate& selectedDate){
    ui->tableWidget->clearContents();
    ui->tableWidget->clearSpans();

    QDate startDate = selectedDate.addDays(-selectedDate.dayOfWeek() + 1);
    QDate endDate = startDate.addDays(6);

    QList<Event> weekEvents = m_calendar->getEventsForWeek(startDate, endDate);

    for(const Event &event: weekEvents){

        int startHour = event.getStartTime().time().hour();
        int endHour = event.getEndTime().time().hour();

        int row = startHour;
        if(row < 0){
            row += 24;
        }

        int column = event.getStartTime().date().dayOfWeek() - 1;

        QTableWidgetItem *item = new QTableWidgetItem(event.getTitle());

        int duration = endHour - startHour;
        qDebug() << "Duration: " << duration;
        if (duration > 1){
            ui->tableWidget->setSpan(row, column, duration, 1);
        }

        ui->tableWidget->setItem(row, column, item);
    }
}

void AppWindow::logoutUser() {
    emit m_user->m_client->disconnectedUser(m_user->getUsername());

    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
    this->close();
    // delete this;
}

void AppWindow::showSyncWindow(QString username, QString title, int duration) {
    SyncResponseWindow* responseWindow = new SyncResponseWindow(username, title, duration);
    responseWindow->show();
    connect(responseWindow, &SyncResponseWindow::yesResponse, this, &AppWindow::sendYesResponse);
    connect(responseWindow, &SyncResponseWindow::noResponse, this, &AppWindow::sendNoResponse);
}

AppWindow::~AppWindow() {
    m_user->logout();
    delete m_user;
    m_user = nullptr;

    delete ui;
}

void AppWindow::sendYesResponse(QString friendName, int duration) {
    m_user->m_client->syncResponse(true, m_user->getUsername(), friendName, duration, m_user->getCalendar());
}

void AppWindow::sendNoResponse(QString friendName) {
    m_user->m_client->syncResponse(false, m_user->getUsername(), friendName, 0);
}

void AppWindow::syncDenied(QString friendName) {
    SyncDeniedWindow *syncDeniedWindow = new SyncDeniedWindow(friendName);
    syncDeniedWindow->show();
}

void AppWindow::showResponseWindow(QString eventTitle, QString startTime) {
    ResponseWindow *responseWindow = new ResponseWindow(eventTitle,startTime);
    responseWindow->show();
    connect(responseWindow, &ResponseWindow::sendResponse, m_user->m_client, &Client::eventResponse);
}

void AppWindow::agreedSync(QDateTime startTime, QDateTime endTime, QString title) {
    Event event;
    event.setStartTime(startTime);
    event.setEndTime(endTime);
    event.setTitle(title);

    m_user->getCalendar().addEvent(event);
}
