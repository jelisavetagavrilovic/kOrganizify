#include "mainwindow.h"
//#include "appwindow.h"
//#include "eventwindow.h"
//#include "settingswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

