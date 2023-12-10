#include "mainwindow.h"
#include "appwindow.h"
#include "eventwindow.h"
#include "settingswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // AppWindow aw;
    // aw.show();

    // EventWindow ew;
    // ew.show();

    SettingsWindow sw;
    sw.show();

    return a.exec();
}

