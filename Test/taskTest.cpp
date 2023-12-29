#include "catch.hpp"
#include "../kOrganizify/src/task.h"

TEST_CASE("Task()", "[Task]") {
    SECTION("Postavljanje vrednosti u konstruktoru") {
        Task task("eeee");

        REQUIRE(task.getName() == "eeee");
    }
}

TEST_CASE("isChecked()", "[Task]") {
    SECTION("Postavljanje vrednosti u konstruktoru") {
        Task task("andji");

        REQUIRE(task.getIsChecked() == false);
    }

    SECTION("Postavljanje vrednosti u konstruktoru") {
        Task task("andji");
        task.setIsChecked(true);

        REQUIRE(task.getIsChecked() == true);
    }
}
