#include "mainwindow.h"
#include "appwindow.h"
#include "settingswindow.h"
#include "eventwindow.h"
#include "calendar.h"

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


//    Calendar calendar;

//    EventWindow ew(calendar);
//    ew.show();

    Calendar calendar;
    calendar.loadData("jelisaveta");

    ToDoList toDoList;
    toDoList.loadData("jelisaveta");

    return a.exec();
}

