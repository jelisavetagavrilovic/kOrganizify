//#include "mainwindow.h"
//#include "appwindow.h"
#include "settingswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    // AppWindow aw;
    // aw.show();

    SettingsWindow w(nullptr);
    w.show();

    return a.exec();
}

