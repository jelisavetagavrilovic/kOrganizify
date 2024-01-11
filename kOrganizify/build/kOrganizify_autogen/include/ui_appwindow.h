/********************************************************************************
** Form generated from reading UI file 'appwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPWINDOW_H
#define UI_APPWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppWindow
{
public:
    QWidget *centralwidget;
    QListWidget *lwToDoList;
    QLabel *lblToDoList;
    QLineEdit *leInput;
    QTableWidget *tableWidget;
    QListWidget *lwFriends;
    QHBoxLayout *horizontalLayout;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout2;
    QPushButton *btnClear;
    QPushButton *btnLogout;
    QCalendarWidget *calendarWidget;
    QPushButton *btnSettings;
    QPushButton *btnSmartPlan;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AppWindow)
    {
        if (AppWindow->objectName().isEmpty())
            AppWindow->setObjectName(QString::fromUtf8("AppWindow"));
        AppWindow->resize(1276, 654);
        centralwidget = new QWidget(AppWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setTabletTracking(false);
        centralwidget->setFocusPolicy(Qt::TabFocus);
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 12px;\n"
"}"));
        lwToDoList = new QListWidget(centralwidget);
        lwToDoList->setObjectName(QString::fromUtf8("lwToDoList"));
        lwToDoList->setGeometry(QRect(880, 35, 231, 261));
        lblToDoList = new QLabel(centralwidget);
        lblToDoList->setObjectName(QString::fromUtf8("lblToDoList"));
        lblToDoList->setGeometry(QRect(960, 0, 81, 41));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        lblToDoList->setFont(font);
        leInput = new QLineEdit(centralwidget);
        leInput->setObjectName(QString::fromUtf8("leInput"));
        leInput->setGeometry(QRect(880, 305, 231, 22));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 24)
            tableWidget->setRowCount(24);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(21, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(22, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(23, __qtablewidgetitem30);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 35, 821, 581));
        tableWidget->setFrameShape(QFrame::Box);
        tableWidget->horizontalHeader()->setDefaultSectionSize(110);
        lwFriends = new QListWidget(centralwidget);
        lwFriends->setObjectName(QString::fromUtf8("lwFriends"));
        lwFriends->setGeometry(QRect(880, 345, 231, 61));
        horizontalLayout = new QHBoxLayout(lwFriends);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 170, 91, 221));
        verticalLayout2 = new QVBoxLayout(layoutWidget);
        verticalLayout2->setObjectName(QString::fromUtf8("verticalLayout2"));
        verticalLayout2->setContentsMargins(0, 0, 0, 0);
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(1074, 260, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/images/trash-2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon);
        btnClear->setIconSize(QSize(22, 22));
        btnLogout = new QPushButton(centralwidget);
        btnLogout->setObjectName(QString::fromUtf8("btnLogout"));
        btnLogout->setGeometry(QRect(1197, 361, 45, 45));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/images/user-x.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnLogout->setIcon(icon1);
        btnLogout->setIconSize(QSize(30, 30));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(880, 425, 361, 187));
        btnSettings = new QPushButton(centralwidget);
        btnSettings->setObjectName(QString::fromUtf8("btnSettings"));
        btnSettings->setGeometry(QRect(1133, 361, 45, 45));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/images/settings.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnSettings->setIcon(icon2);
        btnSettings->setIconSize(QSize(30, 30));
        btnSmartPlan = new QPushButton(centralwidget);
        btnSmartPlan->setObjectName(QString::fromUtf8("btnSmartPlan"));
        btnSmartPlan->setGeometry(QRect(1197, 35, 45, 45));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/images/calendar.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnSmartPlan->setIcon(icon3);
        btnSmartPlan->setIconSize(QSize(30, 30));
        AppWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AppWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1276, 21));
        AppWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AppWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AppWindow->setStatusBar(statusbar);

        retranslateUi(AppWindow);

        QMetaObject::connectSlotsByName(AppWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AppWindow)
    {
        AppWindow->setWindowTitle(QCoreApplication::translate("AppWindow", "MainWindow", nullptr));
        lblToDoList->setText(QCoreApplication::translate("AppWindow", "ToDo", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AppWindow", "Mon", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AppWindow", "Tue", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AppWindow", "Wed", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AppWindow", "Thu", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AppWindow", "Fri", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AppWindow", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AppWindow", "Sun", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("AppWindow", "00h", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("AppWindow", "1h", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("AppWindow", "2h", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("AppWindow", "3h", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("AppWindow", "4h", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("AppWindow", "5h", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("AppWindow", "6h", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("AppWindow", "7h", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("AppWindow", "8h", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("AppWindow", "9h", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("AppWindow", "10h", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("AppWindow", "11h", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("AppWindow", "12h", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("AppWindow", "13h", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("AppWindow", "14h", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("AppWindow", "15h", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("AppWindow", "16h", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("AppWindow", "17h", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("AppWindow", "18h", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("AppWindow", "19h", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("AppWindow", "20h", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("AppWindow", "21h", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("AppWindow", "22h", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("AppWindow", "23h", nullptr));
        btnClear->setText(QString());
        btnLogout->setText(QString());
        btnSettings->setText(QString());
        btnSmartPlan->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AppWindow: public Ui_AppWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPWINDOW_H
