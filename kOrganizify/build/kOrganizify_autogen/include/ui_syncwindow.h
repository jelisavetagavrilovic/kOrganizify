/********************************************************************************
** Form generated from reading UI file 'syncwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYNCWINDOW_H
#define UI_SYNCWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SyncWindow
{
public:
    QLineEdit *leNameInput;
    QComboBox *cbSelectHours;
    QPushButton *btnSync;
    QLabel *lblChooseTime;
    QLabel *lblIcon;

    void setupUi(QWidget *SyncWindow)
    {
        if (SyncWindow->objectName().isEmpty())
            SyncWindow->setObjectName(QString::fromUtf8("SyncWindow"));
        SyncWindow->resize(282, 254);
        SyncWindow->setStyleSheet(QString::fromUtf8("SyncWindow{\n"
"	background-color: #F7F4F8;\n"
"}\n"
"QLabel{\n"
"	color: black;\n"
"}"));
        leNameInput = new QLineEdit(SyncWindow);
        leNameInput->setObjectName(QString::fromUtf8("leNameInput"));
        leNameInput->setGeometry(QRect(10, 90, 261, 22));
        leNameInput->setStyleSheet(QString::fromUtf8("SyncWindow{\n"
"	background-color: #F7F4F8;\n"
"}\n"
"\n"
"QLabel{\n"
"	color: black;\n"
"}"));
        cbSelectHours = new QComboBox(SyncWindow);
        cbSelectHours->setObjectName(QString::fromUtf8("cbSelectHours"));
        cbSelectHours->setGeometry(QRect(200, 148, 51, 23));
        cbSelectHours->setProperty("maximum", QVariant(24));
        cbSelectHours->setProperty("minimum", QVariant(1));
        btnSync = new QPushButton(SyncWindow);
        btnSync->setObjectName(QString::fromUtf8("btnSync"));
        btnSync->setGeometry(QRect(90, 200, 101, 23));
        lblChooseTime = new QLabel(SyncWindow);
        lblChooseTime->setObjectName(QString::fromUtf8("lblChooseTime"));
        lblChooseTime->setGeometry(QRect(15, 150, 171, 16));
        QFont font;
        font.setPointSize(12);
        lblChooseTime->setFont(font);
        lblIcon = new QLabel(SyncWindow);
        lblIcon->setObjectName(QString::fromUtf8("lblIcon"));
        lblIcon->setGeometry(QRect(120, 20, 41, 41));
        lblIcon->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/link.png")));
        lblIcon->setScaledContents(true);

        retranslateUi(SyncWindow);

        cbSelectHours->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SyncWindow);
    } // setupUi

    void retranslateUi(QWidget *SyncWindow)
    {
        SyncWindow->setWindowTitle(QCoreApplication::translate("SyncWindow", "Form", nullptr));
        leNameInput->setPlaceholderText(QCoreApplication::translate("SyncWindow", "Enter Event Name", nullptr));
        btnSync->setText(QCoreApplication::translate("SyncWindow", "Sync", nullptr));
        lblChooseTime->setText(QCoreApplication::translate("SyncWindow", "Choose event duration:", nullptr));
        lblIcon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SyncWindow: public Ui_SyncWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYNCWINDOW_H
