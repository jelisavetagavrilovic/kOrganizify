/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *gbLogin;
    QLabel *lblUsername;
    QLabel *lblPassword;
    QLineEdit *leUsername;
    QLineEdit *lePassword;
    QPushButton *btnLogin;
    QLabel *lblRegister;
    QPushButton *btnRegister;
    QLabel *lblStatus;
    QLabel *lblUserChecked;
    QLabel *lblUserPlus;
    QLabel *lblPoster;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(352, 453);
        MainWindow->setStyleSheet(QString::fromUtf8("MainWindow{\n"
"	background-color: #F7F4F8;\n"
"}\n"
"\n"
"QLabel{\n"
"	color: black;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gbLogin = new QGroupBox(centralwidget);
        gbLogin->setObjectName(QString::fromUtf8("gbLogin"));
        gbLogin->setGeometry(QRect(-70, -10, 501, 301));
        lblUsername = new QLabel(gbLogin);
        lblUsername->setObjectName(QString::fromUtf8("lblUsername"));
        lblUsername->setGeometry(QRect(100, 100, 91, 21));
        lblUsername->setTabletTracking(false);
        lblUsername->setAutoFillBackground(false);
        lblPassword = new QLabel(gbLogin);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));
        lblPassword->setGeometry(QRect(100, 130, 91, 21));
        leUsername = new QLineEdit(gbLogin);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));
        leUsername->setGeometry(QRect(190, 100, 201, 24));
        leUsername->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: #B4B19A;\n"
"}"));
        lePassword = new QLineEdit(gbLogin);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setGeometry(QRect(190, 130, 201, 24));
        lePassword->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: #B4B19A;\n"
"}"));
        btnLogin = new QPushButton(gbLogin);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(190, 180, 111, 41));
        btnLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #D0443F;\n"
"    border: none;\n"
"    color: black;\n"
"    padding: 10px 24px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    display: inline-block;\n"
"    font-size: 13px;\n"
"    margin: 4px 2px;\n"
"    cursor: pointer;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DD7875;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/images/log-in.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnLogin->setIcon(icon);
        lblRegister = new QLabel(gbLogin);
        lblRegister->setObjectName(QString::fromUtf8("lblRegister"));
        lblRegister->setGeometry(QRect(120, 250, 161, 17));
        btnRegister = new QPushButton(gbLogin);
        btnRegister->setObjectName(QString::fromUtf8("btnRegister"));
        btnRegister->setGeometry(QRect(270, 240, 121, 41));
        btnRegister->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #D0443F;\n"
"    border: none;\n"
"    color: black;\n"
"    padding: 10px 24px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    display: inline-block;\n"
"    font-size: 13px;\n"
"    margin: 4px 2px;\n"
"    cursor: pointer;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DD7875;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/images/user-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnRegister->setIcon(icon1);
        lblStatus = new QLabel(gbLogin);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setGeometry(QRect(110, 210, 291, 20));
        lblStatus->setAlignment(Qt::AlignCenter);
        lblUserChecked = new QLabel(gbLogin);
        lblUserChecked->setObjectName(QString::fromUtf8("lblUserChecked"));
        lblUserChecked->setGeometry(QRect(230, 20, 51, 51));
        lblUserChecked->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/user-check.svg")));
        lblUserChecked->setScaledContents(true);
        lblUserPlus = new QLabel(gbLogin);
        lblUserPlus->setObjectName(QString::fromUtf8("lblUserPlus"));
        lblUserPlus->setGeometry(QRect(230, 20, 51, 51));
        lblUserPlus->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/user-plus.svg")));
        lblUserPlus->setScaledContents(true);
        lblPoster = new QLabel(centralwidget);
        lblPoster->setObjectName(QString::fromUtf8("lblPoster"));
        lblPoster->setGeometry(QRect(-20, 290, 381, 131));
        lblPoster->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/LoginPoster.png")));
        lblPoster->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 352, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        gbLogin->setTitle(QString());
        lblUsername->setText(QCoreApplication::translate("MainWindow", " Username", nullptr));
        lblPassword->setText(QCoreApplication::translate("MainWindow", " Password", nullptr));
        btnLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        lblRegister->setText(QCoreApplication::translate("MainWindow", "Don't have an account?", nullptr));
        btnRegister->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        lblStatus->setText(QString());
        lblUserChecked->setText(QString());
        lblUserPlus->setText(QString());
        lblPoster->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
