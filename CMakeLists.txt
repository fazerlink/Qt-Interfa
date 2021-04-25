cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Threads REQUIRED)




  add_executable(test
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    timer.cpp timer.h
    functions.cpp functions.h
    stdafx.h
  )


target_link_libraries(test PRIVATE Qt5::Widgets Threads::Threads)
