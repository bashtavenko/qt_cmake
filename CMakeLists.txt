cmake_minimum_required(VERSION 3.30)
project(qt_cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Charts Core Gui Qml Quick)

add_executable(qt_cmake main.cpp resources.qrc)
target_link_libraries(qt_cmake
        Qt::Charts
        Qt::Core
        Qt::Gui
        Qt::Qml
        Qt::Quick
)

set(resources_resource_files
        "main.qml"
)
