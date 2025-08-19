cmake_minimum_required(VERSION 3.10)
project(Multiplayer-Game-Engine-Demo)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/Engine/Engine.cpp
    src/Game/Game.cpp
)

include_directories(src)

add_executable(Multiplayer-Game-Engine-Demo ${SOURCES})
