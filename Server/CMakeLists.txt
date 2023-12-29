cmake_minimum_required(VERSION 3.14)

project(Server LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

set(PROJECT_SOURCES
        main.cpp
        server.cpp
        ../kOrganizify/src/calendar.cpp
        ../kOrganizify/src/event.cpp
        ../kOrganizify/src/saveload.cpp
        ../kOrganizify/src/basicevent.cpp
)

set(PROJECT_HEADERS
        server.h
        ../kOrganizify/src/calendar.h
        ../kOrganizify/src/event.h
        ../kOrganizify/src/basicevent.h
)

add_executable(Server
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
)
target_link_libraries(Server Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)

include(GNUInstallDirs)
install(TARGETS Server
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
