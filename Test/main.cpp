#define CATCH_CONFIG_RUNNER

#include <QCoreApplication>
#include "catch.hpp"
#include "../kOrganizify/src/task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    return Catch::Session().run(argc, argv);
}
