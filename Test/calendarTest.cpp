#include "catch.hpp"
#include "../kOrganizify/src/calendar.h"
#include "../kOrganizify/src/event.h"

TEST_CASE("addEvent()", "[Calendar]") {
    SECTION("Dodavanje novog eventa") {
        Calendar cal;
        Event event;
        event.setTitle("title");
        event.setStartTime(QDateTime::currentDateTime());
        event.setEndTime(QDateTime::currentDateTime().addSecs(60*60));
        cal.addEvent(event);
        int size = cal.size();

        REQUIRE(size > 0);
    }
}

TEST_CASE("removeEvent()", "[Calendar]") {
    SECTION("Uklanjanje postojeceg dogadjaja") {
        Calendar cal;
        Event event;
        event.setTitle("title");
        event.setStartTime(QDateTime::currentDateTime());
        event.setEndTime(QDateTime::currentDateTime().addSecs(60*60));
        cal.addEvent(event);
        int sizeBefore = cal.size();
        cal.removeEvent(event);
        int sizeAfter = cal.size();

        REQUIRE(sizeAfter == sizeBefore - 1);
    }
}

TEST_CASE("hasEventAt()", "[Calendar]") {
    SECTION("Provera postojanja dogadjaja u odredjeno vreme") {
        Calendar cal;
        Event event;
        QDate date(2023,12,31);
        QTime time(23,59,59);
        QDateTime dateTime(date,time);
        event.setTitle("newYear");
        event.setStartTime(dateTime);
        event.setEndTime(dateTime.addSecs(2));
        cal.addEvent(event);

        bool exists = cal.hasEventAt(dateTime);

        REQUIRE(exists == true);
    }

    SECTION("Provera nepostojanja dogadjaja u odredjeno vreme") {
        Calendar cal;
        Event event;
        QDate date(2023,12,31);
        QTime time(23,59,59);
        QDateTime dateTime(date,time);
        event.setTitle("newYear");
        event.setStartTime(dateTime);
        event.setEndTime(dateTime.addSecs(2));
        cal.addEvent(event);

        bool exists = cal.hasEventAt(dateTime.addYears(1));

        REQUIRE(exists == false);
    }
}
