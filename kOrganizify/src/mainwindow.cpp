#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "appwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Login");

    ui->lblStatus->setVisible(false);
    ui->lePassword->setEchoMode(QLineEdit::Password);

    connect(ui->btnLogin, &QPushButton::clicked, this, &MainWindow::login);
    connect(ui->btnRegister, &QPushButton::clicked, this, &MainWindow::registerUser);
}

void MainWindow::login()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    User user(username, password);


    if (user.login(password)) {
        ui->lblStatus->setText("Login successful.");

        this->close();

        AppWindow *app = new AppWindow(&user, this);
        app->show();
    } else if (user.userExists(username))
        ui->lblStatus->setText("Login failed. Check the password.");
    else
        ui->lblStatus->setText("Login failed. User doesn't exist.");

    ui->lblStatus->setVisible(true);
}

void MainWindow::registerUser()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    User user(username, password);
    if (user.registerUser(password)) {
        ui->lblStatus->setText("Registration successful. Login successful.");

        this->close();

        AppWindow *app = new AppWindow(&user, this);
        app->show();
    } else
        ui->lblStatus->setText("Registration failed. User already exists.");

    ui->lblStatus->setVisible(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}
