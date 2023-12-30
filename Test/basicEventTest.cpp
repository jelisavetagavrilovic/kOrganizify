#include "catch.hpp"
#include "../kOrganizify/src/basicevent.h"

TEST_CASE("BasicEvent()", "[BasicEvent]") {
    SECTION("Provera konstruktora") {
        BasicEvent event;

        const QString actualTitle = event.getTitle();
        const int actualDuration = event.getDuration();
        const bool actualValidation = event.isValidate();

        REQUIRE(actualTitle == "");
        REQUIRE(actualValidation == false);
    }
}

TEST_CASE("getTitle() Basic", "[BasicEvent]") {
    SECTION("Dohvatanje imena") {
        BasicEvent event;

        const QString expectedTitle = "Test Title";
        event.setTitle(expectedTitle);
        const QString actualTitle = event.getTitle();

        REQUIRE(actualTitle == expectedTitle);
    }
}

TEST_CASE("setTitle() Basic", "[BasicEvent]") {
    SECTION("Postavljanje titla") {
        BasicEvent event;

        const QString expectedTitle = "Test Title";
        event.setTitle(expectedTitle);
        const QString actualTitle = event.getTitle();

        REQUIRE(actualTitle == expectedTitle);
    }
}

TEST_CASE("getDuration() Basic", "[BasicEvent]") {
    SECTION("Dohvatanje trajanja dogadjaja") {
        BasicEvent event;

        const int expectedDuration = 60;
        event.setDuration(expectedDuration);
        const int actualDuration = event.getDuration();

        REQUIRE(actualDuration == expectedDuration);
    }
}

TEST_CASE("setDuration() Basic", "[BasicEvent]") {
    SECTION("Namestanje trajanja dogadjaja") {
        BasicEvent event;

        const int expectedDuration = 60;
        event.setDuration(expectedDuration);
        const int actualDuration = event.getDuration();

        REQUIRE(actualDuration == expectedDuration);
    }
}

TEST_CASE("deleteString() Basic", "[BasicEvent]") {
    SECTION("Brisanje stringa") {
        BasicEvent event;

        const QString expectedTitle = "Test Title";
        event.setTitle(expectedTitle);
        event.deleteString();

        const QString actualTitle = event.getTitle();
        REQUIRE(actualTitle == "");
    }
}

TEST_CASE("isValidate() Basic", "[BasicEvent]") {
    SECTION("Validacija imena i vremana") {
        BasicEvent validEvent;
        const QString validTitle = "Valid Title";
        const int validDuration = 30;
        validEvent.setTitle(validTitle);
        validEvent.setDuration(validDuration);

        const bool actualValidation = validEvent.isValidate();
        REQUIRE(actualValidation == true);
    }

    SECTION("Validacija imena i vremana sa praznim titlom i losim vremenom") {
        BasicEvent invalidTitleEvent;
        const QString invalidTitle = "";
        const int invalidDuration = 45;
        invalidTitleEvent.setTitle(invalidTitle);
        invalidTitleEvent.setDuration(invalidDuration);

        BasicEvent invalidDurationEvent;
        const QString validInvalidTitle = "Invalid Title";
        const int zeroDuration = 0;
        invalidDurationEvent.setTitle(validInvalidTitle);
        invalidDurationEvent.setDuration(zeroDuration);

        const bool actualInvalidTitleValidation = invalidTitleEvent.isValidate();
        const bool actualInvalidDurationValidation = invalidDurationEvent.isValidate();
        REQUIRE(actualInvalidTitleValidation == false);
        REQUIRE(actualInvalidDurationValidation == false);
    }
}

TEST_CASE("operator==(const BasicEvent &other)", "[BasicEvent]") {
    SECTION("Poredjenje jednakosti") {
        BasicEvent event1;
        const QString title1 = "Title1";
        const int duration1 = 60;
        event1.setTitle(title1);
        event1.setDuration(duration1);

        BasicEvent event2;
        const QString title2 = "Title1";
        const int duration2 = 60;
        event2.setTitle(title2);
        event2.setDuration(duration2);

        BasicEvent event3;
        const QString title3 = "Title2";
        const int duration3 = 90;
        event3.setTitle(title3);
        event3.setDuration(duration3);

        const bool equalityCheck1 = (event1 == event2);
        const bool equalityCheck2 = !(event1 == event3);
        REQUIRE(equalityCheck1);
        REQUIRE(equalityCheck2);
    }
}
