#include "mainwindow.h"
#include "appwindow.h"
//#include "settingswindow.h"
//#include "eventwindow.h"
//#include "calendar.h"
#include "syncwindow.h"
#include "responsewindow.h"
#include "ui_responsewindow.h"
#include <QApplication>

#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}

