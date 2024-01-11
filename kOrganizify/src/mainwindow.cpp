// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), m_user(nullptr) {
    ui->setupUi(this);
    setWindowTitle("Login");
    setFixedSize(size());

    ui->lblStatus->setVisible(false);
    ui->lblUserPlus->setVisible(false);
    ui->lePassword->setEchoMode(QLineEdit::Password);

    ui->leUsername->setStyleSheet("QLineEdit{color: black; background-color: #B4B19A; }");
    ui->lePassword->setStyleSheet("QLineEdit{color: black; background-color: #B4B19A; }");

    connect(ui->btnLogin, &QPushButton::clicked, this, &MainWindow::loginUser);
    connect(ui->lePassword, &QLineEdit::returnPressed, this, &MainWindow::loginUser);
    connect(ui->btnRegister, &QPushButton::clicked, this, &MainWindow::registerUser);
}

void MainWindow::loginUser() {
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    if (username.isEmpty() || password.isEmpty())
        return;

    m_user = new User(username, password);

    if (m_user->login(password)) {
        auto *appWindow = new AppWindow(m_user);
        appWindow->show();
        hide();
        connect(appWindow, &AppWindow::exit, this, &MainWindow::appear);
    } else {
        if (m_user->userExists(username))
            ui->lblStatus->setText("Login failed. Check the password.");
        else
            ui->lblStatus->setText("Login failed. User doesn't exist.");

        delete m_user;
        m_user = nullptr;
    }

    ui->lblStatus->setVisible(true);
}


void MainWindow::registerUser() {
    ui->lblUserPlus->setVisible(true);
    ui->lblUserChecked->setVisible(false);
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    if (username.isEmpty() || password.isEmpty())
        return;

    m_user = new User(username, password);

    if (m_user->registerUser(password)) {
        ui->lblStatus->setText("Registration successful. Login successful.");

        auto *appWindow = new AppWindow(m_user);
        appWindow->show();
        hide();
        connect(appWindow, &AppWindow::exit, this, &MainWindow::appear);
    } else {
        ui->lblStatus->setText("Registration failed. User already exists.");

        delete m_user;
        m_user = nullptr;
    }

    ui->lblStatus->setVisible(true);
}

void MainWindow::appear() {
    show();
}

MainWindow::~MainWindow() {
    delete ui;
}
