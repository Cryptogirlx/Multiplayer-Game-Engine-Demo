cmake_minimum_required(VERSION 3.10)
project(Multiplayer-Game-Engine-Demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set minimum SFML version to 3.0
set(SFML_MIN_VERSION "3.0.0")

set(SOURCES
    src/main.cpp
    src/Engine/Engine.cpp
    src/Game/Game.cpp
    src/Game/Player.cpp
    src/Game/Obstacle.cpp
)

include_directories(src)

add_executable(Multiplayer-Game-Engine-Demo ${SOURCES})

# Find SFML 3 with version requirement
find_package(SFML ${SFML_MIN_VERSION} REQUIRED COMPONENTS System Window Graphics)

target_link_libraries(Multiplayer-Game-Engine-Demo sfml-system sfml-window sfml-graphics)
