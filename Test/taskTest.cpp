#include "catch.hpp"
#include "../kOrganizify/src/task.h"

TEST_CASE("Task()", "[Task]") {
    SECTION("Postavljanje vrednosti polja u konstruktoru") {
        QString name = "newTask";

        Task task(name);
        QString taskName = task.getName();
        bool checked = task.getIsChecked();

        REQUIRE(taskName == name);
        REQUIRE(checked == false);
    }
}

TEST_CASE("setName()", "[Task]") {
    SECTION("Postavljanje vrednosti polja seterom") {
        Task task("newTask");
        QString newName = "newName";
        task.setName(newName);

        QString name = task.getName();

        REQUIRE(newName == name);
    }
}

TEST_CASE("setIsChecked()", "[Task]") {
    SECTION("Postavljanje vrednosti polja seterom") {
        Task task("newTask");
        bool newChecked = true;
        task.setIsChecked(newChecked);

        bool checked = task.getIsChecked();

        REQUIRE(newChecked == checked);
    }
}
