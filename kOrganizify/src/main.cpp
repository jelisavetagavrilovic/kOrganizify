#include "mainwindow.h"
//#include "appwindow.h"
//#include "settingswindow.h"
//#include "eventwindow.h"
#include "calendar.h"
//#include "user.h"
#include"notifications.h"
#include "notificationswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.show();


    Calendar calendar;
    calendar.loadData("andjela");
    Notifications notif(&calendar);
    notif.checkEvents();

//     User user("andjela", "a");
//     user.loadData("andjela");
//     user.saveData("andjela");

//    NotificationsWindow nw;
//    nw.show();

    // calendar.saveData("andjela");

//     Settings settings;
//     settings.loadData("andjela");
//     settings.setColor("#0050B5");
//     settings.setNightMode(false);
//     settings.setNotifications(false);
//     settings.saveData("andjela");

//     ToDoList toDoList;
//     toDoList.loadData("andjela");
//     toDoList.addTask(Task("ok"));
//     toDoList.addTask(Task("drugi"));
//     toDoList.saveData("andjela");

    return a.exec();
}

