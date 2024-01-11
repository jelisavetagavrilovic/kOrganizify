/********************************************************************************
** Form generated from reading UI file 'basiceventwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICEVENTWINDOW_H
#define UI_BASICEVENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_BasicEventWindow
{
public:
    QPushButton *btnNext;
    QPushButton *btnPrevious;
    QPushButton *btnGenerate;
    QLabel *lblPlanStartTime;
    QLabel *lblPlanEndTime;
    QLineEdit *leTitle;
    QLineEdit *leDuration;
    QLabel *lblTitle;
    QLabel *lblDuration;
    QPushButton *btnRemove;
    QTimeEdit *tePlanStartTime;
    QTimeEdit *tePlanEndTime;
    QPushButton *btnPreviousCalendar;
    QPushButton *btnNextCalendar;

    void setupUi(QDialog *BasicEventWindow)
    {
        if (BasicEventWindow->objectName().isEmpty())
            BasicEventWindow->setObjectName(QString::fromUtf8("BasicEventWindow"));
        BasicEventWindow->resize(454, 260);
        btnNext = new QPushButton(BasicEventWindow);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(350, 90, 89, 25));
        btnPrevious = new QPushButton(BasicEventWindow);
        btnPrevious->setObjectName(QString::fromUtf8("btnPrevious"));
        btnPrevious->setGeometry(QRect(10, 90, 89, 25));
        btnGenerate = new QPushButton(BasicEventWindow);
        btnGenerate->setObjectName(QString::fromUtf8("btnGenerate"));
        btnGenerate->setGeometry(QRect(350, 220, 89, 25));
        lblPlanStartTime = new QLabel(BasicEventWindow);
        lblPlanStartTime->setObjectName(QString::fromUtf8("lblPlanStartTime"));
        lblPlanStartTime->setGeometry(QRect(90, 25, 141, 17));
        lblPlanEndTime = new QLabel(BasicEventWindow);
        lblPlanEndTime->setObjectName(QString::fromUtf8("lblPlanEndTime"));
        lblPlanEndTime->setGeometry(QRect(90, 48, 131, 20));
        leTitle = new QLineEdit(BasicEventWindow);
        leTitle->setObjectName(QString::fromUtf8("leTitle"));
        leTitle->setGeometry(QRect(220, 140, 221, 25));
        leDuration = new QLineEdit(BasicEventWindow);
        leDuration->setObjectName(QString::fromUtf8("leDuration"));
        leDuration->setGeometry(QRect(220, 170, 221, 25));
        lblTitle = new QLabel(BasicEventWindow);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));
        lblTitle->setGeometry(QRect(10, 140, 111, 17));
        lblDuration = new QLabel(BasicEventWindow);
        lblDuration->setObjectName(QString::fromUtf8("lblDuration"));
        lblDuration->setGeometry(QRect(10, 170, 201, 17));
        btnRemove = new QPushButton(BasicEventWindow);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        btnRemove->setGeometry(QRect(10, 220, 141, 25));
        tePlanStartTime = new QTimeEdit(BasicEventWindow);
        tePlanStartTime->setObjectName(QString::fromUtf8("tePlanStartTime"));
        tePlanStartTime->setGeometry(QRect(240, 18, 118, 26));
        tePlanEndTime = new QTimeEdit(BasicEventWindow);
        tePlanEndTime->setObjectName(QString::fromUtf8("tePlanEndTime"));
        tePlanEndTime->setGeometry(QRect(240, 48, 118, 26));
        btnPreviousCalendar = new QPushButton(BasicEventWindow);
        btnPreviousCalendar->setObjectName(QString::fromUtf8("btnPreviousCalendar"));
        btnPreviousCalendar->setGeometry(QRect(160, 220, 89, 25));
        btnNextCalendar = new QPushButton(BasicEventWindow);
        btnNextCalendar->setObjectName(QString::fromUtf8("btnNextCalendar"));
        btnNextCalendar->setGeometry(QRect(250, 220, 89, 25));

        retranslateUi(BasicEventWindow);

        QMetaObject::connectSlotsByName(BasicEventWindow);
    } // setupUi

    void retranslateUi(QDialog *BasicEventWindow)
    {
        BasicEventWindow->setWindowTitle(QCoreApplication::translate("BasicEventWindow", "Dialog", nullptr));
        btnNext->setText(QCoreApplication::translate("BasicEventWindow", "Next", nullptr));
        btnPrevious->setText(QCoreApplication::translate("BasicEventWindow", "Previous", nullptr));
        btnGenerate->setText(QCoreApplication::translate("BasicEventWindow", "Generate", nullptr));
        lblPlanStartTime->setText(QCoreApplication::translate("BasicEventWindow", "Planning start time:", nullptr));
        lblPlanEndTime->setText(QCoreApplication::translate("BasicEventWindow", "Planning end time:", nullptr));
        lblTitle->setText(QCoreApplication::translate("BasicEventWindow", "Event title:", nullptr));
        lblDuration->setText(QCoreApplication::translate("BasicEventWindow", "Event duration (in minutes):", nullptr));
        btnRemove->setText(QCoreApplication::translate("BasicEventWindow", "Remove this event", nullptr));
        btnPreviousCalendar->setText(QCoreApplication::translate("BasicEventWindow", "<", nullptr));
        btnNextCalendar->setText(QCoreApplication::translate("BasicEventWindow", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BasicEventWindow: public Ui_BasicEventWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICEVENTWINDOW_H
