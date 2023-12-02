#include "mainwindow.h"
#include "appwindow.h"

#include <QApplication>

#include <QDebug>
#include "user.h"
#include "saveload.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    AppWindow aw;
    aw.show();


    // TEST LOGIN USER!!! //

    // Create SaveLoad object
    SaveLoad saveLoad;

    // Test user registration and login
    User user1("john_doe", "password123", &saveLoad);

    // Attempt to log in (should fail as the user is not registered)
    if (user1.login("password123")) {
        qDebug() << "Login successful.";
    } else {
        qDebug() << "Login failed.";
    }

    // Register the user
    user1.registerUser();

    // Attempt to log in again (should succeed after registration)
    if (user1.login("password123")) {
        qDebug() << "Login successful.";
    } else {
        qDebug() << "Login failed.";
    }

    // Test user logout
    user1.logout();



    return a.exec();
}
