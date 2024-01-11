/********************************************************************************
** Form generated from reading UI file 'eventwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTWINDOW_H
#define UI_EVENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventWindow
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *lblTitle;
    QLineEdit *leTitle;
    QLabel *lblStart;
    QHBoxLayout *horizontalLayoutStart;
    QDateEdit *deDateStart;
    QTimeEdit *teTimeStart;
    QLabel *lblEnd;
    QHBoxLayout *horizontalLayoutEnd;
    QDateEdit *deDateEnd;
    QTimeEdit *teTimeEnd;
    QTextEdit *teDescription;
    QLabel *lblDescription;
    QLineEdit *leLocation;
    QLabel *lblLocation;
    QComboBox *cbPriority;
    QLabel *label;
    QPushButton *btnSave;
    QPushButton *btnDelete;

    void setupUi(QWidget *EventWindow)
    {
        if (EventWindow->objectName().isEmpty())
            EventWindow->setObjectName(QString::fromUtf8("EventWindow"));
        EventWindow->resize(443, 373);
        formLayoutWidget = new QWidget(EventWindow);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 421, 281));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(6);
        formLayout->setContentsMargins(0, 0, 0, 0);
        lblTitle = new QLabel(formLayoutWidget);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblTitle);

        leTitle = new QLineEdit(formLayoutWidget);
        leTitle->setObjectName(QString::fromUtf8("leTitle"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leTitle);

        lblStart = new QLabel(formLayoutWidget);
        lblStart->setObjectName(QString::fromUtf8("lblStart"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblStart);

        horizontalLayoutStart = new QHBoxLayout();
        horizontalLayoutStart->setObjectName(QString::fromUtf8("horizontalLayoutStart"));
        deDateStart = new QDateEdit(formLayoutWidget);
        deDateStart->setObjectName(QString::fromUtf8("deDateStart"));

        horizontalLayoutStart->addWidget(deDateStart);

        teTimeStart = new QTimeEdit(formLayoutWidget);
        teTimeStart->setObjectName(QString::fromUtf8("teTimeStart"));

        horizontalLayoutStart->addWidget(teTimeStart);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayoutStart);

        lblEnd = new QLabel(formLayoutWidget);
        lblEnd->setObjectName(QString::fromUtf8("lblEnd"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblEnd);

        horizontalLayoutEnd = new QHBoxLayout();
        horizontalLayoutEnd->setObjectName(QString::fromUtf8("horizontalLayoutEnd"));
        deDateEnd = new QDateEdit(formLayoutWidget);
        deDateEnd->setObjectName(QString::fromUtf8("deDateEnd"));

        horizontalLayoutEnd->addWidget(deDateEnd);

        teTimeEnd = new QTimeEdit(formLayoutWidget);
        teTimeEnd->setObjectName(QString::fromUtf8("teTimeEnd"));

        horizontalLayoutEnd->addWidget(teTimeEnd);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayoutEnd);

        teDescription = new QTextEdit(formLayoutWidget);
        teDescription->setObjectName(QString::fromUtf8("teDescription"));

        formLayout->setWidget(5, QFormLayout::FieldRole, teDescription);

        lblDescription = new QLabel(formLayoutWidget);
        lblDescription->setObjectName(QString::fromUtf8("lblDescription"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lblDescription);

        leLocation = new QLineEdit(formLayoutWidget);
        leLocation->setObjectName(QString::fromUtf8("leLocation"));

        formLayout->setWidget(7, QFormLayout::FieldRole, leLocation);

        lblLocation = new QLabel(formLayoutWidget);
        lblLocation->setObjectName(QString::fromUtf8("lblLocation"));

        formLayout->setWidget(7, QFormLayout::LabelRole, lblLocation);

        cbPriority = new QComboBox(formLayoutWidget);
        cbPriority->setObjectName(QString::fromUtf8("cbPriority"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cbPriority);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        btnSave = new QPushButton(EventWindow);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(340, 330, 89, 25));
        btnDelete = new QPushButton(EventWindow);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setGeometry(QRect(210, 330, 89, 25));

        retranslateUi(EventWindow);

        QMetaObject::connectSlotsByName(EventWindow);
    } // setupUi

    void retranslateUi(QWidget *EventWindow)
    {
        EventWindow->setWindowTitle(QCoreApplication::translate("EventWindow", "Form", nullptr));
        lblTitle->setText(QCoreApplication::translate("EventWindow", "Event title", nullptr));
        lblStart->setText(QCoreApplication::translate("EventWindow", "Start", nullptr));
        lblEnd->setText(QCoreApplication::translate("EventWindow", "End", nullptr));
        lblDescription->setText(QCoreApplication::translate("EventWindow", "Description       ", nullptr));
        lblLocation->setText(QCoreApplication::translate("EventWindow", "Location", nullptr));
        label->setText(QCoreApplication::translate("EventWindow", "Priority", nullptr));
        btnSave->setText(QCoreApplication::translate("EventWindow", "Save", nullptr));
        btnDelete->setText(QCoreApplication::translate("EventWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventWindow: public Ui_EventWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTWINDOW_H
