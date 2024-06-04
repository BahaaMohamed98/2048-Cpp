cmake_minimum_required(VERSION 3.28)
project(2048Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(2048 src/main.cpp
        src/Menu.cpp
        src/Game.cpp
        src/MoveHandler.cpp
        src/helpers.cpp
        src/GameTime.cpp
)

target_compile_options(2048 PRIVATE -static-libstdc++)

target_compile_options(2048 PRIVATE -static-libgcc)

target_compile_options(2048 PRIVATE -static)

target_include_directories(2048 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/headers/)

add_executable(test test/test.cpp
        src/Menu.cpp
        src/Game.cpp
        src/MoveHandler.cpp
        src/helpers.cpp
        src/GameTime.cpp
)

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/headers/)
