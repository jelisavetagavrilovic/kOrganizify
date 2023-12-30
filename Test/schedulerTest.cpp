#include "catch.hpp"
#include "../kOrganizify/src/scheduler.h"
#include "../kOrganizify/src/calendar.h"

TEST_CASE("Scheduler(Calendar *calendar, Calendar *basicCalendar, QDate *startDate)", "[Scheduler]") {
    SECTION("Provera konstruktora 1") {
        Calendar calendar;
        Calendar basicCalendar;
        QDate startDate(2023, 1, 1);

        Scheduler* scheduler = new Scheduler(&calendar, &basicCalendar, &startDate);

        REQUIRE(scheduler != nullptr);
    }

    SECTION("Provera konstruktora 2") {
        Calendar calendar;
        Calendar basicCalendar;
        QDate startDate(2023, 2, 10);

        Scheduler* scheduler = new Scheduler(&calendar, &basicCalendar, &startDate);

        REQUIRE(scheduler != nullptr);
    }

    SECTION("Provera konstruktora 3") {
        Calendar calendar;
        Calendar basicCalendar;
        QDate startDate(2023, 18, 12);

        Scheduler* scheduler = new Scheduler(&calendar, &basicCalendar, &startDate);

        REQUIRE(scheduler != nullptr);
    }

    SECTION("Provera konstruktora 4") {
        Calendar calendar;
        Calendar basicCalendar;
        QDate startDate(2023, 30, 30);

        Scheduler* scheduler = new Scheduler(&calendar, &basicCalendar, &startDate);

        REQUIRE(scheduler != nullptr);
    }

    SECTION("Provera konstruktora 5") {
        Calendar calendar;
        Calendar basicCalendar;
        QDate startDate(2023, 7, 5);

        Scheduler* scheduler = new Scheduler(&calendar, &basicCalendar, &startDate);

        REQUIRE(scheduler != nullptr);
    }

    SECTION("Provera konstruktora 6") {
        Calendar calendar;
        Calendar basicCalendar;
        QDate startDate(2023, 11, 9);

        Scheduler* scheduler = new Scheduler(&calendar, &basicCalendar, &startDate);

        REQUIRE(scheduler != nullptr);
    }

}
