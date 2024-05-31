cmake_minimum_required(VERSION 3.28)
project(2048Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(main src/main.cpp
        src/Menu/Menu.h
        src/Menu/menu.cpp
        src/Game/Game.h
        src/Game/Game.cpp
        src/Game/MoveHandler/MoveHandler.cpp
        src/Game/MoveHandler/MoveHandler.h
)

add_executable(test test/test.cpp)