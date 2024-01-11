/********************************************************************************
** Form generated from reading UI file 'responsewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESPONSEWINDOW_H
#define UI_RESPONSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResponseWindow
{
public:
    QLabel *lblQuestion;
    QLabel *lblDate;
    QPushButton *btnYes;
    QPushButton *btnNo;
    QLabel *lblEvent;
    QLabel *lblWork;

    void setupUi(QWidget *ResponseWindow)
    {
        if (ResponseWindow->objectName().isEmpty())
            ResponseWindow->setObjectName(QString::fromUtf8("ResponseWindow"));
        ResponseWindow->resize(431, 280);
        ResponseWindow->setStyleSheet(QString::fromUtf8("ResponseWindow{\n"
"	background-color: #F7F4F8;\n"
"}\n"
"QLabel{\n"
"	color: black;\n"
"}"));
        lblQuestion = new QLabel(ResponseWindow);
        lblQuestion->setObjectName(QString::fromUtf8("lblQuestion"));
        lblQuestion->setGeometry(QRect(160, 37, 221, 20));
        QFont font;
        font.setPointSize(12);
        lblQuestion->setFont(font);
        lblDate = new QLabel(ResponseWindow);
        lblDate->setObjectName(QString::fromUtf8("lblDate"));
        lblDate->setGeometry(QRect(110, 140, 211, 31));
        lblDate->setFont(font);
        btnYes = new QPushButton(ResponseWindow);
        btnYes->setObjectName(QString::fromUtf8("btnYes"));
        btnYes->setGeometry(QRect(240, 210, 91, 31));
        btnYes->setFont(font);
        btnNo = new QPushButton(ResponseWindow);
        btnNo->setObjectName(QString::fromUtf8("btnNo"));
        btnNo->setGeometry(QRect(90, 210, 91, 31));
        btnNo->setFont(font);
        lblEvent = new QLabel(ResponseWindow);
        lblEvent->setObjectName(QString::fromUtf8("lblEvent"));
        lblEvent->setGeometry(QRect(100, 40, 58, 15));
        lblEvent->setFont(font);
        lblWork = new QLabel(ResponseWindow);
        lblWork->setObjectName(QString::fromUtf8("lblWork"));
        lblWork->setGeometry(QRect(100, 100, 211, 16));
        lblWork->setFont(font);

        retranslateUi(ResponseWindow);

        QMetaObject::connectSlotsByName(ResponseWindow);
    } // setupUi

    void retranslateUi(QWidget *ResponseWindow)
    {
        ResponseWindow->setWindowTitle(QCoreApplication::translate("ResponseWindow", "Form", nullptr));
        lblQuestion->setText(QString());
        lblDate->setText(QString());
        btnYes->setText(QCoreApplication::translate("ResponseWindow", "Yes", nullptr));
        btnNo->setText(QCoreApplication::translate("ResponseWindow", "No", nullptr));
        lblEvent->setText(QCoreApplication::translate("ResponseWindow", "Event:", nullptr));
        lblWork->setText(QCoreApplication::translate("ResponseWindow", "Does this time work for you?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResponseWindow: public Ui_ResponseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESPONSEWINDOW_H
