/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *centralwidget;
    QComboBox *cbxDropTheme;
    QCheckBox *cbNotifications;
    QPushButton *btnSave;
    QLabel *lblColor;
    QLabel *lblNotificationsOn;
    QLabel *lblNotificationsOff;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(345, 241);
        SettingsWindow->setStyleSheet(QString::fromUtf8("SettingsWindow{\n"
"        background-color: #F7F4F8;\n"
"}"));
        centralwidget = new QWidget(SettingsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cbxDropTheme = new QComboBox(centralwidget);
        cbxDropTheme->addItem(QString());
        cbxDropTheme->addItem(QString());
        cbxDropTheme->addItem(QString());
        cbxDropTheme->addItem(QString());
        cbxDropTheme->addItem(QString());
        cbxDropTheme->addItem(QString());
        cbxDropTheme->setObjectName(QString::fromUtf8("cbxDropTheme"));
        cbxDropTheme->setGeometry(QRect(20, 110, 101, 31));
        QFont font;
        font.setPointSize(12);
        cbxDropTheme->setFont(font);
        cbNotifications = new QCheckBox(centralwidget);
        cbNotifications->setObjectName(QString::fromUtf8("cbNotifications"));
        cbNotifications->setGeometry(QRect(185, 115, 121, 21));
        cbNotifications->setFont(font);
        cbNotifications->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"        color: black;\n"
"}"));
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(120, 180, 106, 31));
        btnSave->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/images/save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon);
        btnSave->setIconSize(QSize(24, 24));
        lblColor = new QLabel(centralwidget);
        lblColor->setObjectName(QString::fromUtf8("lblColor"));
        lblColor->setGeometry(QRect(40, 30, 51, 46));
        lblColor->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/color-palette.png")));
        lblColor->setScaledContents(true);
        lblNotificationsOn = new QLabel(centralwidget);
        lblNotificationsOn->setObjectName(QString::fromUtf8("lblNotificationsOn"));
        lblNotificationsOn->setGeometry(QRect(220, 30, 51, 51));
        lblNotificationsOn->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/bell.svg")));
        lblNotificationsOn->setScaledContents(true);
        lblNotificationsOff = new QLabel(centralwidget);
        lblNotificationsOff->setObjectName(QString::fromUtf8("lblNotificationsOff"));
        lblNotificationsOff->setGeometry(QRect(220, 30, 51, 51));
        lblNotificationsOff->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/bell-off.svg")));
        lblNotificationsOff->setScaledContents(true);
        SettingsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SettingsWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 345, 21));
        SettingsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SettingsWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SettingsWindow->setStatusBar(statusbar);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsWindow)
    {
        cbxDropTheme->setItemText(0, QCoreApplication::translate("SettingsWindow", "Blue", nullptr));
        cbxDropTheme->setItemText(1, QCoreApplication::translate("SettingsWindow", "Green", nullptr));
        cbxDropTheme->setItemText(2, QCoreApplication::translate("SettingsWindow", "Orange", nullptr));
        cbxDropTheme->setItemText(3, QCoreApplication::translate("SettingsWindow", "Pink", nullptr));
        cbxDropTheme->setItemText(4, QCoreApplication::translate("SettingsWindow", "Purple", nullptr));
        cbxDropTheme->setItemText(5, QCoreApplication::translate("SettingsWindow", "Default", nullptr));

        cbNotifications->setText(QCoreApplication::translate("SettingsWindow", "Notifications", nullptr));
        btnSave->setText(QCoreApplication::translate("SettingsWindow", "   Save", nullptr));
        lblColor->setText(QString());
        lblNotificationsOn->setText(QString());
        lblNotificationsOff->setText(QString());
        (void)SettingsWindow;
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
