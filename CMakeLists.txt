cmake_minimum_required(VERSION 3.28)
project(2048Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(main src/main.cpp
        src/Menu.cpp
        src/Game.cpp
        src/MoveHandler.cpp
        src/helpers.cpp
        src/Time.cpp
        src/headers/Time.h
)

add_executable(test test/test.cpp)