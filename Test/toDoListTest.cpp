#include "catch.hpp"
#include "../kOrganizify/src/toDoList.h"
#include "../kOrganizify/src/task.h"

TEST_CASE("ToDoList(QObject *parent)", "[ToDoList]") {
    SECTION("Provera konstruktora") {
        ToDoList toDoList;
        REQUIRE(toDoList.getTasks().isEmpty());
    }
}

TEST_CASE("getTasks()", "[ToDoList]") {
    SECTION("Dohvatanje tasks") {
        ToDoList toDoList;

        Task task1("Task 1");
        Task task2("Task 2");

        toDoList.addTask(task1);
        toDoList.addTask(task2);

        QVector<Task> retrievedTasks = toDoList.getTasks();
        QVector<Task> expectedTasks = {task1, task2};

        REQUIRE(retrievedTasks.size() == expectedTasks.size());
    }
}

TEST_CASE("setTasks()", "[ToDoList]") {
    SECTION("Namestanje taskova") {
        ToDoList toDoList;

        Task task1("Task 1");
        Task task2("Task 2");

        QVector<Task> tasks;
        tasks.append(task1);
        tasks.append(task2);

        toDoList.setTasks(tasks);

        QVector<Task> retrievedTasks = toDoList.getTasks();

        REQUIRE(retrievedTasks.size() == tasks.size());
    }
}

TEST_CASE("addTask()", "[ToDoList]") {
    SECTION("Dodavanje taskova") {
        ToDoList toDoList;

        Task task1("Task 1");
        Task task2("Task 2");

        toDoList.addTask(task1);
        toDoList.addTask(task2);

        QVector<Task> addedTasks = toDoList.getTasks();
        QVector<Task> expectedTasks = {task1, task2};

        REQUIRE(addedTasks.size() == expectedTasks.size());
    }
}

TEST_CASE("removeTask()", "[ToDoList]") {
    SECTION("Uklanjanje taskova") {
        ToDoList toDoList;

        Task task1("Task 1");
        Task task2("Task 2");

        toDoList.addTask(task1);
        toDoList.addTask(task2);

        QVector<Task> initialTasks = toDoList.getTasks();
        REQUIRE(initialTasks.size() == 2);

        toDoList.removeTask(0);

        QVector<Task> remainingTasks = toDoList.getTasks();
        REQUIRE(remainingTasks.size() == 1);
    }
}

TEST_CASE("getTask(int index)", "[ToDoList]") {
    SECTION("Dohvatanje specificnog taska") {
        ToDoList toDoList;

        Task task1("Task 1");
        Task task2("Task 2");

        toDoList.addTask(task1);
        toDoList.addTask(task2);

        Task* retrievedTask1 = toDoList.getTask(0);
        Task* retrievedTask2 = toDoList.getTask(1);

        QString name1 = retrievedTask1->getName();
        QString name2 = retrievedTask2->getName();

        REQUIRE(name1 == toDoList.getTasks()[0].getName());
        REQUIRE(name2 == toDoList.getTasks()[1].getName());
    }
}

TEST_CASE("toString()", "[ToDoList]") {
    SECTION("Konvertovanje taska u string") {
        ToDoList toDoList;

        Task task1("Task 1");
        Task task2("Task 2");

        toDoList.addTask(task1);
        toDoList.addTask(task2);

        QString expectedString = "Task 1\nTask 2";
        QString actualString = toDoList.toString();
        REQUIRE(actualString == expectedString);
    }
}
