#include "mainwindow.h"
#include "eventwindow.h"
#include "calendar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    Calendar calendar;

    EventWindow ew(calendar);
    ew.show();

    return a.exec();
}

