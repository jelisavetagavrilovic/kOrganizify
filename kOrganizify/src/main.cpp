#include "mainwindow.h"
#include "eventwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    EventWindow ew;
    ew.show();

    return a.exec();
}

