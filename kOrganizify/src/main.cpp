#include "mainwindow.h"
#include "appwindow.h"
#include "settingswindow.h"
#include "eventwindow.h"
#include "calendar.h"
#include "user.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // MainWindow w;
    // w.show();

    // AppWindow ap;
    // ap.show();

    // SettingsWindow sw;
    // sw.show();

   // EventWindow ew(calendar);
   // ew.show();


    // User user("jelisavtea", "j");
    // user.loadData("jelisaveta");
    // user.saveData("jelisaveta");

    // Calendar calendar;
    // calendar.loadData("jelisaveta");
    // calendar.saveData("jelisaveta");

    // Settings settings;
    // settings.loadData("jelisaveta");
    // settings.setColor("#0050B5");
    // settings.setNightMode(false);
    // settings.setNotifications(false);
    // settings.saveData("jelisaveta");

    // ToDoList toDoList;
    // toDoList.loadData("jelisaveta");
    // toDoList.addTask(Task("ok"));
    // toDoList.addTask(Task("drugi"));
    // toDoList.saveData("jelisaveta");

    return a.exec();
}

