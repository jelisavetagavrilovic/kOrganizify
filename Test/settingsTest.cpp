#include "catch.hpp"
#include <QJsonObject>
#include "../kOrganizify/src/settings.h"

TEST_CASE("Settings()", "[Settings]") {
    SECTION("Postavljanje vrednosti u konstruktoru") {

        Settings settings;
        QString color = settings.getColor();
        bool notifications = settings.getNotifications();

        REQUIRE(color == "#A5A9A0");
        REQUIRE(notifications == false);
    }
}
