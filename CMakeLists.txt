# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2022 Pedro López-Cabanillas <plcl@users.sourceforge.net>

cmake_minimum_required(VERSION 3.5)

project(forbidden-screenshot VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6SvgWidgets)
else()
    find_package(Qt5Svg)
endif()

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(forbidden-screenshot
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(forbidden-screenshot
        ${PROJECT_SOURCES}
    )
endif()

set_target_properties(forbidden-screenshot PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(forbidden-screenshot PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    target_link_libraries(forbidden-screenshot PRIVATE Qt6::SvgWidgets)
else()
    target_link_libraries(forbidden-screenshot PRIVATE Qt5::Svg)
endif()

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(forbidden-screenshot)
endif()
