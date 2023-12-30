cmake_minimum_required(VERSION 3.14)

project(Test LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Test
  main.cpp
  catch.hpp
  taskTest.cpp
  ../kOrganizify/src/task.cpp
  settingsTest.cpp
  ../kOrganizify/src/settings.cpp
  ../kOrganizify/src/saveload.cpp
  calendarTest.cpp
  ../kOrganizify/src/calendar.cpp
  ../kOrganizify/src/event.cpp
  ../kOrganizify/src/basicevent.cpp
  eventTest.cpp
  ../kOrganizify/src/event.cpp
  ../kOrganizify/src/basicevent.cpp
)
target_link_libraries(Test Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Test
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
