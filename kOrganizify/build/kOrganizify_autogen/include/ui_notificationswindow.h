/********************************************************************************
** Form generated from reading UI file 'notificationswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFICATIONSWINDOW_H
#define UI_NOTIFICATIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotificationsWindow
{
public:
    QLabel *lblTimeEvent;
    QLabel *lblNameEvent;
    QLabel *lblIcon;
    QLabel *lblLocationEvent;

    void setupUi(QWidget *NotificationsWindow)
    {
        if (NotificationsWindow->objectName().isEmpty())
            NotificationsWindow->setObjectName(QString::fromUtf8("NotificationsWindow"));
        NotificationsWindow->resize(369, 180);
        NotificationsWindow->setStyleSheet(QString::fromUtf8("NotificationWindow{\n"
"	background-color: #F7F4F8;\n"
"}\n"
"\n"
"QLabel{\n"
"	color: black;\n"
"}"));
        lblTimeEvent = new QLabel(NotificationsWindow);
        lblTimeEvent->setObjectName(QString::fromUtf8("lblTimeEvent"));
        lblTimeEvent->setGeometry(QRect(90, 110, 251, 16));
        QFont font;
        font.setPointSize(12);
        lblTimeEvent->setFont(font);
        lblNameEvent = new QLabel(NotificationsWindow);
        lblNameEvent->setObjectName(QString::fromUtf8("lblNameEvent"));
        lblNameEvent->setGeometry(QRect(20, 80, 321, 16));
        lblNameEvent->setFont(font);
        lblIcon = new QLabel(NotificationsWindow);
        lblIcon->setObjectName(QString::fromUtf8("lblIcon"));
        lblIcon->setGeometry(QRect(160, 10, 51, 51));
        lblIcon->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/bell.svg")));
        lblIcon->setScaledContents(true);
        lblLocationEvent = new QLabel(NotificationsWindow);
        lblLocationEvent->setObjectName(QString::fromUtf8("lblLocationEvent"));
        lblLocationEvent->setGeometry(QRect(50, 140, 291, 16));
        lblLocationEvent->setFont(font);

        retranslateUi(NotificationsWindow);

        QMetaObject::connectSlotsByName(NotificationsWindow);
    } // setupUi

    void retranslateUi(QWidget *NotificationsWindow)
    {
        NotificationsWindow->setWindowTitle(QCoreApplication::translate("NotificationsWindow", "Form", nullptr));
        lblTimeEvent->setText(QCoreApplication::translate("NotificationsWindow", "At:", nullptr));
        lblNameEvent->setText(QCoreApplication::translate("NotificationsWindow", "30 min until:", nullptr));
        lblIcon->setText(QString());
        lblLocationEvent->setText(QCoreApplication::translate("NotificationsWindow", "Location:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotificationsWindow: public Ui_NotificationsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFICATIONSWINDOW_H
