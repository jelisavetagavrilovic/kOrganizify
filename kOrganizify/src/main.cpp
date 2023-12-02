#include "mainwindow.h"
#include "appwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // AppWindow aw;
    // aw.show();


    return a.exec();
}
