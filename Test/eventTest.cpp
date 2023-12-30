#include "catch.hpp"
#include "../kOrganizify/src/event.h"
#include "../kOrganizify/src/basicevent.h"

TEST_CASE("Event()", "[Event]") {
    SECTION("Postavljanje vrednosti u konstruktoru") {
        Event event;

        CustomEventPriority priority = event.getPriority();
        QString title = event.getTitle();

        REQUIRE(priority == CustomEventPriority::NoPriority);
        REQUIRE(title.isEmpty());
    }
}

TEST_CASE("getTitle()", "[Event]") {
    SECTION("Dohvatanje imena") {
        Event event;
        const QString titleToSet = "Sample Title";
        event.setTitle(titleToSet);

        const QString title = event.getTitle();
        REQUIRE(title == titleToSet);
    }
}

TEST_CASE("getDuration()", "[Event]") {
    SECTION("Dohvatanje duzine vremena") {
        Event event;
        const int durationToSet = 120;
        event.setDuration(durationToSet);

        const int duration = event.getDuration();
        REQUIRE(duration == durationToSet);
    }
}

TEST_CASE("setTitle(const QString &title)", "[Event]") {
    SECTION("Postavljanje naslova") {
        Event event;
        const QString titleToSet = "Novi Naslov";
        event.setTitle(titleToSet);

        const QString title = event.getTitle();
        REQUIRE(title == titleToSet);
    }
}

TEST_CASE("setDuration(const int duration)", "[Event]") {
    SECTION("Postavljanje trajanja na osnovu prosledjene vrednosti") {
        Event event;
        const int durationToSet = 180;
        event.setDuration(durationToSet);

        const int duration = event.getDuration();
        REQUIRE(duration == durationToSet);
    }
}

TEST_CASE("setDuration()", "[Event]") {
    SECTION("Duzina vremena je dobro izracunata na osnovu startTime i endTime") {
        Event event;
        const QTime startTime(10, 0);
        const QTime endTime(12, 30);
        const QDateTime startDateTime(QDate(2023, 1, 1), startTime);
        const QDateTime endDateTime(QDate(2023, 1, 1), endTime);

        event.setStartTime(startDateTime);
        event.setEndTime(endDateTime);
        event.setDuration();

        const int calculatedDuration = event.getDuration();
        REQUIRE(calculatedDuration == 150);
    }
}

TEST_CASE("customEventPriorityToString(CustomEventPriority priority)", "[Event]") {
    SECTION("Tacno konvertuje prioritet u string") {
        const CustomEventPriority priorityToTest = CustomEventPriority::NoPriority;
        const QString convertedPriority = customEventPriorityToString(priorityToTest);
        REQUIRE(convertedPriority == "No Priority");
    }
}

TEST_CASE("customEventPriorityFromString(const QString &priorityString)", "[Event]") {
    SECTION("Tacno konvertuje string u enum prioritet") {
        const QString priorityStringToTest = "Low";
        const CustomEventPriority convertedPriority = customEventPriorityFromString(priorityStringToTest);
        REQUIRE(convertedPriority == CustomEventPriority::Low);
    }
}
