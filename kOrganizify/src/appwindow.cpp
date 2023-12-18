// appwindow.cpp
#include "appwindow.h"
#include "ui_appwindow.h"

AppWindow::AppWindow(User *user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppWindow)
    , m_user(user)
{
    ui->setupUi(this);

    initialize();

    connect(ui->btnLogout, &QPushButton::clicked, this, &AppWindow::logoutUser);
    connect(ui->leInput, &QLineEdit::returnPressed, this, &AppWindow::addTask);
}

void AppWindow::initialize() {
    ToDoList& toDoList = m_user->getToDoList();
    const QVector<Task>& tasks = toDoList.getTasks();

    for (const Task& task : tasks)
        addTaskToListWidget(task);
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

    connect(checkBox, &QCheckBox::stateChanged, this, &AppWindow::onCheckBoxStateChanged);
}

void AppWindow::onCheckBoxStateChanged(int state) {
    QCheckBox *checkBox = qobject_cast<QCheckBox*>(sender());
    if (checkBox && state == Qt::Checked) {
        QString taskName = checkBox->text();

        this->m_user->getToDoList().removeTask(taskName);

        // Uklanjanje elementa iz QListWidget-a
        QListWidgetItem *item = ui->lwToDoList->itemAt(checkBox->pos());
        if (item != nullptr) {
            int row = ui->lwToDoList->row(item);
            ui->lwToDoList->takeItem(row);
            delete item;
        }
    }
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
}



//     // this->settingsWindow = new SettingsWindow(this);
//     // this->settingsWindow->setColor("#0050B5");
//     // this->ui->lwToDoList->setStyleSheet("background-color: #FCD299");

//     // QString sourceDir = QCoreApplication::applicationDirPath();
//     // QString path = QDir(sourceDir).filePath("../kOrganizify/src/images/background1.jpg");
//     // QPixmap background(path);

//     // QPalette palette;
//     // palette.setBrush(this->backgroundRole(), QBrush(background));
//     // this->setPalette(palette);

//     // QString styleSheet = QString("background-color: %1").arg(this->settingsWindow->getColor());
//     // this->ui->btnSettings->setStyleSheet(styleSheet);
//     // this->ui->leInput->setStyleSheet(styleSheet);
//     // this->ui->lblToDoList->setStyleSheet("color: " + this->settingsWindow->getColor());

//     // connect(ui->btnSettings, &QPushButton::clicked, this, &AppWindow::on_btnSettings_clicked);
//     // connect(settingsWindow, &SettingsWindow::colorChanged, this, &AppWindow::changeButtonColor);
//

// void AppWindow::changeButtonColor(const QString& newColor) {
//     // this->ui->btnSettings->setStyleSheet("background-color: " + newColor);
//     // this->ui->leInput->setStyleSheet("background-color: " + newColor);
//     // this->ui->lblToDoList->setStyleSheet("color: " + newColor);
// }

// void AppWindow::on_btnSettings_clicked()
// {
//     // if (this->settingsWindow && this->settingsWindow->isVisible()) {
//     //     this->settingsWindow->activateWindow();
//     // } else {
//     //     this->settingsWindow->show();
//     // }
//     // QString styleSheet = QString("background-color: %1").arg(this->settingsWindow->getColor());
//     // this->ui->btnSettings->setStyleSheet(styleSheet);
//     // this->ui->btnSettings->update();
// }




