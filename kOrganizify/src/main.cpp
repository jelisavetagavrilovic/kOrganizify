#include "mainwindow.h"
#include "appwindow.h"
//#include "settingswindow.h"
//#include "eventwindow.h"
//#include "calendar.h"
#include "syncwindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // MainWindow w;
    // w.show();

//    AppWindow aw;
//    aw.show();

    SyncWindow sw;
    sw.show();

    return a.exec();
}

