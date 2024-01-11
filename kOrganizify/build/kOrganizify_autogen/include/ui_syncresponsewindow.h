/********************************************************************************
** Form generated from reading UI file 'syncresponsewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYNCRESPONSEWINDOW_H
#define UI_SYNCRESPONSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SyncResponseWindow
{
public:
    QLabel *lblTitle;
    QLabel *lblT;
    QLabel *lblEventTitle;
    QLabel *lblD;
    QLabel *lblDuration;
    QPushButton *btnYes;
    QPushButton *btnNo;
    QLabel *lblQuestion;

    void setupUi(QWidget *SyncResponseWindow)
    {
        if (SyncResponseWindow->objectName().isEmpty())
            SyncResponseWindow->setObjectName(QString::fromUtf8("SyncResponseWindow"));
        SyncResponseWindow->resize(376, 300);
        SyncResponseWindow->setStyleSheet(QString::fromUtf8("SyncResponseWindow{\n"
"	background-color: #F7F4F8;\n"
"}\n"
"QLabel{\n"
"	color: black;\n"
"}"));
        lblTitle = new QLabel(SyncResponseWindow);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setGeometry(QRect(40, 20, 301, 41));
        QFont font;
        font.setPointSize(12);
        lblTitle->setFont(font);
        lblTitle->setStyleSheet(QString::fromUtf8("SyncResponseWindow{\n"
"	background-color: #F7F4F8;\n"
"}\n"
"QLabel{\n"
"	color: black;\n"
"}"));
        lblT = new QLabel(SyncResponseWindow);
        lblT->setObjectName(QString::fromUtf8("lblT"));
        lblT->setGeometry(QRect(50, 80, 81, 41));
        lblT->setFont(font);
        lblEventTitle = new QLabel(SyncResponseWindow);
        lblEventTitle->setObjectName(QString::fromUtf8("lblEventTitle"));
        lblEventTitle->setGeometry(QRect(110, 80, 361, 41));
        lblEventTitle->setFont(font);
        lblD = new QLabel(SyncResponseWindow);
        lblD->setObjectName(QString::fromUtf8("lblD"));
        lblD->setGeometry(QRect(30, 130, 81, 31));
        lblD->setFont(font);
        lblDuration = new QLabel(SyncResponseWindow);
        lblDuration->setObjectName(QString::fromUtf8("lblDuration"));
        lblDuration->setGeometry(QRect(110, 120, 231, 51));
        lblDuration->setFont(font);
        lblDuration->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	backgroun-color: #F7F4F8;\n"
"}\n"
"QLabel{\n"
"	color: black;\n"
"}"));
        btnYes = new QPushButton(SyncResponseWindow);
        btnYes->setObjectName(QString::fromUtf8("btnYes"));
        btnYes->setGeometry(QRect(230, 240, 91, 31));
        btnYes->setFont(font);
        btnNo = new QPushButton(SyncResponseWindow);
        btnNo->setObjectName(QString::fromUtf8("btnNo"));
        btnNo->setGeometry(QRect(50, 244, 91, 31));
        btnNo->setFont(font);
        lblQuestion = new QLabel(SyncResponseWindow);
        lblQuestion->setObjectName(QString::fromUtf8("lblQuestion"));
        lblQuestion->setGeometry(QRect(130, 190, 141, 16));
        lblQuestion->setFont(font);

        retranslateUi(SyncResponseWindow);

        QMetaObject::connectSlotsByName(SyncResponseWindow);
    } // setupUi

    void retranslateUi(QWidget *SyncResponseWindow)
    {
        SyncResponseWindow->setWindowTitle(QCoreApplication::translate("SyncResponseWindow", "Form", nullptr));
        lblTitle->setText(QString());
        lblT->setText(QCoreApplication::translate("SyncResponseWindow", "Event:", nullptr));
        lblEventTitle->setText(QString());
        lblD->setText(QCoreApplication::translate("SyncResponseWindow", "Duration:", nullptr));
        lblDuration->setText(QString());
        btnYes->setText(QCoreApplication::translate("SyncResponseWindow", "Yes", nullptr));
        btnNo->setText(QCoreApplication::translate("SyncResponseWindow", "No", nullptr));
        lblQuestion->setText(QCoreApplication::translate("SyncResponseWindow", "Add to calendar?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SyncResponseWindow: public Ui_SyncResponseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYNCRESPONSEWINDOW_H
