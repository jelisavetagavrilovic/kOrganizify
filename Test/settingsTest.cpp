#include "catch.hpp"
#include "../kOrganizify/src/settings.h"

TEST_CASE("Settings()", "[Settings]") {
    SECTION("Postavljanje vrednosti u konstruktoru") {
        Settings settings;

        REQUIRE(settings.getColor() == "#A5A9A0");
    }

    SECTION("Postavljanje vrednosti u konstruktoru") {
        Settings settings;

        REQUIRE(settings.getNotifications() == false);
    }
}
