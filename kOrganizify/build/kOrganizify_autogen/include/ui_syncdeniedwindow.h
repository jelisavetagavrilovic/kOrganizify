/********************************************************************************
** Form generated from reading UI file 'syncdeniedwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYNCDENIEDWINDOW_H
#define UI_SYNCDENIEDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SyncDeniedWindow
{
public:
    QLabel *lblMessage;

    void setupUi(QWidget *SyncDeniedWindow)
    {
        if (SyncDeniedWindow->objectName().isEmpty())
            SyncDeniedWindow->setObjectName(QString::fromUtf8("SyncDeniedWindow"));
        SyncDeniedWindow->resize(440, 126);
        SyncDeniedWindow->setStyleSheet(QString::fromUtf8("SyncDeniedWindow{\n"
"	background-color: #F7F4F8;\n"
"}\n"
"\n"
"QLabel{\n"
"	color: black;\n"
"}"));
        lblMessage = new QLabel(SyncDeniedWindow);
        lblMessage->setObjectName(QString::fromUtf8("lblMessage"));
        lblMessage->setGeometry(QRect(0, 10, 441, 101));
        QFont font;
        font.setPointSize(12);
        lblMessage->setFont(font);
        lblMessage->setStyleSheet(QString::fromUtf8(""));
        lblMessage->setAlignment(Qt::AlignCenter);

        retranslateUi(SyncDeniedWindow);

        QMetaObject::connectSlotsByName(SyncDeniedWindow);
    } // setupUi

    void retranslateUi(QWidget *SyncDeniedWindow)
    {
        SyncDeniedWindow->setWindowTitle(QCoreApplication::translate("SyncDeniedWindow", "Form", nullptr));
        lblMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SyncDeniedWindow: public Ui_SyncDeniedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYNCDENIEDWINDOW_H
