#include "appwindow.h"
#include "qlistwidget.h"
#include "ui_appwindow.h"

AppWindow::AppWindow(User *user, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AppWindow), m_user(user) {
  ui->setupUi(this);
  setAttribute(Qt::WA_DeleteOnClose);
  setWindowTitle("kOrganizify");

  initialize();

  connect(ui->btnLogout, &QPushButton::clicked, this, &AppWindow::logoutUser);
  connect(ui->btnSmartPlan, &QPushButton::clicked, this, &AppWindow::smartPlan);
  connect(ui->btnSettings, &QPushButton::clicked, this,
          &AppWindow::openSettings);
  connect(m_settingsWindow, &SettingsWindow::enabledNotifications, this,
          &AppWindow::enabledNotifications);
  connect(m_settingsWindow, &SettingsWindow::enabledNotifications,
          m_notifications, &Notifications::enabledNotifications);
  connect(m_settingsWindow, &SettingsWindow::colorChanged, this,
          &AppWindow::changeButtonColor);
  connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask);
  connect(ui->btnClear, &QPushButton::clicked, this,
          &AppWindow::clearFinishedTasks);

  populateFriends(m_user->m_client->m_friends);
  connect(m_user->m_client, &Client::newUserLoggedIn, this,
          &AppWindow::handleNewUserLoggedIn);
  connect(m_user->m_client, &Client::disconnectedUser, this,
          &AppWindow::handleUserDisconnected);
  connect(m_user->m_client, &Client::showSyncWindow, this,
          &AppWindow::showSyncWindow);
  connect(m_user->m_client, &Client::syncRequestDenied, this,
          &AppWindow::syncDenied);
  connect(m_user->m_client, &Client::newEventSync, this,
          &AppWindow::showResponseWindow);
  connect(m_user->m_client, &Client::syncSuccess, this, &AppWindow::agreedSync);
}

void AppWindow::handleNewUserLoggedIn(const QString &username) {
  ui->lwFriends->addItem(username);
}

void AppWindow::handleUserDisconnected(const QString &username) {
  auto user = ui->lwFriends->findItems(username, Qt::MatchExactly);
  if (user.size() > 0) {
    delete user[0];
  }
}

void AppWindow::populateFriends(const QList<QString> &friends) {
  ui->lwFriends->clear();
  connect(ui->lwFriends, &QListWidget::itemClicked, this,
          &AppWindow::openSyncWindow);

  for (const QString &name : friends) {
    QListWidgetItem *item = new QListWidgetItem(name);
    ui->lwFriends->addItem(item);
  }
}

void AppWindow::openSyncWindow(QListWidgetItem *item) {
  m_syncWindow = new SyncWindow(m_user->getUsername(), item->text(),
                                m_user->getCalendar());
  connect(m_syncWindow, &SyncWindow::sendSyncRequest, m_user->m_client,
          &Client::syncRequest);
  m_syncWindow->changeColor(m_settingsWindow->getColor());
  m_syncWindow->show();
}

void AppWindow::changeButtonColor(const QString &newColor) {
  QString styleSheet = "background-color: " + newColor + ";";
  QString btnStyleSheet =
      QString("QPushButton{" + styleSheet + "border-radius: 10px;}");
  ui->btnSettings->setStyleSheet(btnStyleSheet);
  ui->btnClear->setStyleSheet(btnStyleSheet);
  ui->btnLogout->setStyleSheet(btnStyleSheet);
  ui->btnSmartPlan->setStyleSheet(btnStyleSheet);
  ui->leInput->setStyleSheet(styleSheet);
  ui->lblToDoList->setStyleSheet("color: " + newColor);
  ui->tableWidget->setStyleSheet(
      QString("QTableWidget { gridline-color: %1; }").arg(newColor));
  ui->tableWidget->horizontalHeader()->setStyleSheet(styleSheet);
  ui->tableWidget->verticalHeader()->setStyleSheet(styleSheet);
  ui->calendarWidget->setStyleSheet(
      QString("QCalendarWidget QWidget#qt_calendar_navigationbar { color: "
              "black; background-color: %1;}"
              "QCalendarWidget QAbstractItemView:enabled "
              "{selection-background-color: %2 ;}")
          .arg(newColor, newColor));

  QString backgroundPath = m_settingsWindow->colorToPath(newColor);
  QPixmap background(backgroundPath);
  QPalette palette;
  palette.setBrush(backgroundRole(), QBrush(background));
  setPalette(palette);
}

void AppWindow::enabledNotifications(const bool enabled) {
  m_user->getSettings().setNotifications(enabled);
}

void AppWindow::initialize() {
  m_toDoList = &m_user->getToDoList();
  const QVector<Task> &tasks = m_toDoList->getTasks();
  for (const Task &task : tasks)
    addTaskToListWidget(task);

  Settings &settings = m_user->getSettings();
  m_settingsWindow = new SettingsWindow(&settings, this);

  m_settingsWindow->setColor(settings.getColor());
  m_settingsWindow->setBackgroundPath(
      m_settingsWindow->colorToPath(m_settingsWindow->getColor()));
  ui->lwToDoList->setStyleSheet("background-color: #FCD299");
  ui->lwFriends->setStyleSheet("background-color: #E5E1E6; color: black;");
  m_settingsWindow->ui->cbNotifications->setChecked(
      m_user->getSettings().getNotifications());
  ui->lwToDoList->setStyleSheet("background-color: #F4F4F4");

  setFixedSize(size());
  setAutoFillBackground(true);

  m_calendar = &m_user->getCalendar();
  m_notifications = new Notifications(m_calendar);
  m_eventWindow = new EventWindow(m_calendar);

  QString sourceDir = QCoreApplication::applicationDirPath();
  QString path =
      QDir(sourceDir).filePath(m_settingsWindow->getBackgroundPath());
  QPixmap background(path);
  QPalette palette;
  palette.setBrush(backgroundRole(), QBrush(background));
  setPalette(palette);

  QString styleSheet =
      QString("background-color: %1; ").arg(m_settingsWindow->getColor());
  QString btnStyleSheet = QString("QPushButton{" + styleSheet +
                                  "border-radius: 10px; color:black;}");
  ui->btnSettings->setStyleSheet(btnStyleSheet);
  ui->btnClear->setStyleSheet(btnStyleSheet);
  ui->btnLogout->setStyleSheet(btnStyleSheet);
  ui->btnSmartPlan->setStyleSheet(btnStyleSheet);
  ui->leInput->setStyleSheet(styleSheet);
  ui->lblToDoList->setStyleSheet("color: " + m_settingsWindow->getColor());

  ui->calendarWidget->setVerticalHeaderFormat(
      QCalendarWidget::NoVerticalHeader);
  ui->calendarWidget->setStyleSheet(
      QString("QCalendarWidget QWidget#qt_calendar_navigationbar {"
              "   color: black; background-color: %1;}"
              "QCalendarWidget QAbstractItemView:enabled {"
              "   selection-background-color: %2 ;}"
              "QCalendarWidget QToolButton:hover {"
              "    background-color: #3C5291;"
              "}")
          .arg(m_settingsWindow->getColor(), m_settingsWindow->getColor()));
  ui->tableWidget->setStyleSheet(QString("QTableWidget { gridline-color: %1; }")
                                     .arg(m_settingsWindow->getColor()));
  ui->tableWidget->verticalScrollBar()->setStyleSheet(
      "background-color: lightblue");
  ui->tableWidget->horizontalHeader()->setStyleSheet(
      "background-color: " + m_settingsWindow->getColor());
  ui->tableWidget->verticalHeader()->setStyleSheet(
      "background-color: " + m_settingsWindow->getColor());
  int columnWidth = 110;
  for (int i = 0; i < ui->tableWidget->columnCount(); ++i)
    ui->tableWidget->setColumnWidth(i, columnWidth);
  int scrollBarValue = ui->tableWidget->verticalScrollBar()->maximum();
  ui->tableWidget->verticalScrollBar()->setValue(scrollBarValue);

  m_eventWindow->changeColor(m_settingsWindow->getColor());
  m_settingsWindow->changeColor(m_settingsWindow->getColor());

  connect(m_settingsWindow, &SettingsWindow::colorChanged, this,
          &AppWindow::changeButtonColor);
  connect(m_settingsWindow, &SettingsWindow::colorChanged, m_eventWindow,
          &EventWindow::changeColor);
  connect(ui->tableWidget, &QTableWidget::cellDoubleClicked, this,
          &AppWindow::openEventWindowForCell);
  connect(m_eventWindow, &EventWindow::saveButtonClicked, this,
          &AppWindow::updateTableForSelectedDate);
  connect(m_eventWindow, &EventWindow::deleteButtonClicked, this,
          &AppWindow::updateTableForSelectedDate);
  connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask);
  connect(ui->calendarWidget, &QCalendarWidget::selectionChanged, this,
          &AppWindow::updateTableForSelectedDate);
  connect(m_eventWindow, &EventWindow::saveButtonClicked, this,
          &AppWindow::updatedEvents);
  connect(m_eventWindow, &EventWindow::deleteButtonClicked, this,
          &AppWindow::updatedEvents);

  updateTableForSelectedDate();
}

void AppWindow::openEventWindowForCell(int row, int column) {
  if (row >= 0 && column >= 0) {
    QDate selectedDate = ui->calendarWidget->selectedDate();
    QDate startDate = selectedDate.addDays(-selectedDate.dayOfWeek() + 1);
    QDateTime cellDateTime(startDate.addDays(column), QTime(row + 1, 0));

    QList<Event> weekEvents =
        m_calendar->getEventsForWeek(startDate, startDate.addDays(6));
    for (const Event &event : weekEvents) {
      QDateTime startTime = event.getStartTime();
      QDateTime endTime = event.getEndTime();

      int startHour = startTime.time().hour();
      int endHour = endTime.time().hour();
      int startMinute = startTime.time().minute();
      int endMinute = endTime.time().minute();

      int duration = endHour - startHour;

      if (((row >= startHour && row < endHour) ||
           (duration < 1 && row >= startHour && row <= endHour)) &&
          column == event.getStartTime().date().dayOfWeek() - 1) {
        m_eventWindow->setCurrentEvent(event);
        m_eventWindow->setStartDate(cellDateTime.addSecs(60 * startMinute));
        m_eventWindow->setEndDate(
            cellDateTime.addSecs(3600 * duration + 60 * endMinute));
        m_eventWindow->setTitle(event.getTitle());
        m_eventWindow->setDescription(event.getDescription());
        m_eventWindow->setLocation(event.getLocation());
        m_eventWindow->setPriority(event.getPriority());

        m_eventWindow->show();
        return;
      }
    }

    m_eventWindow->setCurrentEvent(Event());
    m_eventWindow->setTitle("");
    m_eventWindow->setDescription("");
    m_eventWindow->setLocation("");
    if (row == 23) {
      m_eventWindow->setStartDate(cellDateTime.addDays(1));
      m_eventWindow->setEndDate(cellDateTime.addSecs(3600 * 24 + 59 * 60));
    } else {
      m_eventWindow->setStartDate(cellDateTime);
      m_eventWindow->setEndDate(cellDateTime.addSecs(3600));
    }
    m_eventWindow->setPriority(CustomEventPriority::NoPriority);
    m_eventWindow->show();
  }
}

void AppWindow::addTask() {
  const auto text = ui->leInput->text();

  if (!text.isEmpty()) {
    Task task(text);
    ui->leInput->clear();

    m_user->getToDoList().addTask(task);
    addTaskToListWidget(task);
  }
}

void AppWindow::addTaskToListWidget(const Task &task) {
  QListWidgetItem *item = new QListWidgetItem();
  ui->lwToDoList->addItem(item);

  QCheckBox *checkBox = new QCheckBox(task.getName());
  ui->lwToDoList->setItemWidget(item, checkBox);

  QFont font{"Times New Roman", 12};

  checkBox->setFont(font);
  checkBox->setStyleSheet("color: black;");
  if (task.getIsChecked()) {
    checkBox->setText(crossTask(task.getName()));
    checkBox->setChecked(true);
  } else
    checkBox->setText(task.getName());

  connect(checkBox, &QCheckBox::stateChanged, this,
          &AppWindow::onCheckBoxStateChanged);
}

void AppWindow::onCheckBoxStateChanged(int state) {
  QCheckBox *checkBox = qobject_cast<QCheckBox *>(sender());
  if (checkBox) {
    int index = ui->lwToDoList->row(ui->lwToDoList->itemFromIndex(
        ui->lwToDoList->indexAt(checkBox->pos())));
    if (state == Qt::Checked) {
      m_toDoList->getTask(index)->setIsChecked(true);
      checkBox->setText(crossTask(m_toDoList->getTask(index)->getName()));
    } else if (state == Qt::Unchecked) {
      m_toDoList->getTask(index)->setIsChecked(false);
      checkBox->setText(m_toDoList->getTask(index)->getName());
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

void AppWindow::clearFinishedTasks() {
  for (int i = ui->lwToDoList->count() - 1; i >= 0; --i) {
    QListWidgetItem *item = ui->lwToDoList->item(i);
    QWidget *widget = ui->lwToDoList->itemWidget(item);

    if (widget && widget->inherits("QCheckBox")) {
      QCheckBox *checkBox = static_cast<QCheckBox *>(widget);
      if (checkBox->isChecked()) {
        ui->lwToDoList->takeItem(i);
        delete item;

        m_toDoList->removeTask(i);
      }
    }
  }
}

void AppWindow::openSettings() {
  m_settingsWindow->show();
  QString styleSheet =
      QString("background-color: %1; ").arg(m_settingsWindow->getColor());
  QString btnStyleSheet = QString("QPushButton{" + styleSheet +
                                  "border-radius: 10px; color:black;}");
  ui->btnSettings->setStyleSheet(btnStyleSheet);
  ui->btnSettings->update();
}

void AppWindow::updateTableForSelectedDateCalendar(Calendar *calendar) {
  m_user->setCalendar(*calendar);
  updateTableForSelectedDate();
}

void AppWindow::updateTableForSelectedDate() {
  QDate selectedDate = ui->calendarWidget->selectedDate();
  showWeeklyEvents(selectedDate);
}

void AppWindow::showWeeklyEvents(const QDate &selectedDate) {
  ui->tableWidget->clearContents();
  ui->tableWidget->clearSpans();

  m_startDate = selectedDate.addDays(-selectedDate.dayOfWeek() + 1);
  m_endDate = m_startDate.addDays(6);

  QList<Event> weekEvents =
      m_calendar->getEventsForWeek(m_startDate, m_endDate);

  for (const Event &event : weekEvents) {
    QDateTime startTime = event.getStartTime();
    QDateTime endTime = event.getEndTime();

    int startHour = startTime.time().hour();
    int endHour = endTime.time().hour();
    int endMinute = endTime.time().minute();

    int row = startHour;
    if (row < 0) {
      row += 24;
    }

    int column = startTime.date().dayOfWeek() - 1;

    QString title = event.getTitle();
    if (!event.getLocation().isEmpty()) {
      title += QString("\nLocation: %1").arg(event.getLocation());
    }
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setData(Qt::DisplayRole, title);
    item->setTextAlignment(Qt::AlignCenter);
    QFont font = item->font();
    font.setBold(true);
    item->setFont(font);
    CustomEventPriority priority = event.getPriority();
    QColor priorityColor = getColorFromPriority(priority);
    item->setBackground(QBrush(priorityColor));

    int durationInHours = (endHour - startHour) + (endMinute > 0 ? 1 : 0);

    if (durationInHours > 1) {
      ui->tableWidget->setSpan(row, column, durationInHours, 1);
    }

    ui->tableWidget->setItem(row, column, item);

    QString tooltipText =
        QString("<div style='max-width: 300px;'>"
                "<b>Title:</b> %1<br>"
                "<b>Location:</b> %2<br>"
                "<b>Start:</b> %3<br>"
                "<b>End:</b> %4<br>"
                "<b>Description:</b> %5</div>")
            .arg(event.getTitle())
            .arg(event.getLocation().isEmpty() ? "N/A" : event.getLocation())
            .arg(event.getStartTime().toString("hh:mm"))
            .arg(event.getEndTime().toString("hh:mm"))
            .arg(event.getDescription().isEmpty() ? "N/A"
                                                  : event.getDescription());

    item->setToolTip(tooltipText);
  }
}

QColor AppWindow::getColorFromPriority(CustomEventPriority priority) {
  switch (priority) {
  case CustomEventPriority::NoPriority:
    return QColor(247, 244, 248);
  case CustomEventPriority::Low:
    return QColor(209, 244, 164);
  case CustomEventPriority::Medium:
    return QColor(250, 226, 127);
  case CustomEventPriority::High:
    return QColor(207, 91, 87);
  default:
    return QColor(247, 244, 248);
  }
}

void AppWindow::logoutUser() {
  emit m_user->m_client->disconnectedUser(m_user->getUsername());
  emit exit();

  close();
  delete this;
}

void AppWindow::showSyncWindow(QString username, QString title, int duration) {
  SyncResponseWindow *responseWindow =
      new SyncResponseWindow(username, title, duration);
  responseWindow->changeColor(m_settingsWindow->getColor());
  responseWindow->show();
  connect(responseWindow, &SyncResponseWindow::yesResponse, this,
          &AppWindow::sendYesResponse);
  connect(responseWindow, &SyncResponseWindow::noResponse, this,
          &AppWindow::sendNoResponse);
}

void AppWindow::smartPlan() {
  QDate selectedDate = ui->calendarWidget->selectedDate();
  if (selectedDate == QDate::currentDate()) {
    m_startDate = selectedDate;
  } else {
    m_startDate = selectedDate.addDays(-selectedDate.dayOfWeek() + 1);
  }
  BasicEventWindow *basicEventWindow =
      new BasicEventWindow(m_calendar, &m_startDate);
  basicEventWindow->changeColor(m_settingsWindow->getColor());
  basicEventWindow->show();

  connect(basicEventWindow, &BasicEventWindow::nextCalendarSignal, this,
          &AppWindow::updateTableForSelectedDateCalendar);
  connect(basicEventWindow, &BasicEventWindow::previousCalendarSignal, this,
          &AppWindow::updateTableForSelectedDateCalendar);
  connect(basicEventWindow, &BasicEventWindow::saveCalendar, this,
          &AppWindow::updateTableForSelectedDateCalendar);
}

AppWindow::~AppWindow() {
  m_user->logout();
  delete m_user;
  m_user = nullptr;
  delete m_notifications;
  delete m_eventWindow;

  delete ui;
}

void AppWindow::sendYesResponse(QString friendName, int duration) {
  m_user->m_client->syncResponse(true, m_user->getUsername(), friendName,
                                 duration, m_user->getCalendar());
}

void AppWindow::sendNoResponse(QString friendName) {
  m_user->m_client->syncResponse(false, m_user->getUsername(), friendName, 0);
}

void AppWindow::syncDenied(QString friendName) {
  SyncDeniedWindow *syncDeniedWindow = new SyncDeniedWindow(friendName);
  syncDeniedWindow->show();
}

void AppWindow::showResponseWindow(QString eventTitle, QString startTime) {
  ResponseWindow *responseWindow = new ResponseWindow(eventTitle, startTime);
  responseWindow->changeColor(m_settingsWindow->getColor());
  responseWindow->show();
  connect(responseWindow, &ResponseWindow::sendResponse, m_user->m_client,
          &Client::eventResponse);
}

void AppWindow::agreedSync(QDateTime startTime, QDateTime endTime,
                           QString title) {
  Event event;
  event.setStartTime(startTime);
  event.setEndTime(endTime);
  event.setTitle(title);

  m_user->getCalendar().addEvent(event);
  updateTableForSelectedDate();
}

void AppWindow::updatedEvents() {
  delete m_notifications;
  m_notifications = new Notifications(m_calendar);
}
