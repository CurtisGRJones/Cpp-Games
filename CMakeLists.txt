cmake_minimum_required(VERSION 3.16)
project(TikTakToe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL2_INCLUDE_DIR "/usr/include/SDL2")
set(SDL2_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2.so")

find_package(SDL2 REQUIRED)

set(SOURCE_FILES
    src/main.cpp
    src/game/game.cpp
    src/game/state/gameState/gameState.cpp
    src/game/gui/button/button.cpp
    src/game/window/window.cpp
    # Add other source files as needed
)

set(HEADER_FILES
    src/game/game.h
    src/game/state/gameState/gameState.h
    src/game/state/state.h
    src/game/gui/button/button.h
    src/game/window/window.h
    # Add other header files as needed
)

add_executable(TikTakToe src/main.cpp)

target_include_directories(TikTakToe PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(TikTakToe ${SDL2_LIBRARIES})

target_include_directories(TikTakToe PUBLIC
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/game
    ${CMAKE_SOURCE_DIR}/src/game/state
    ${CMAKE_SOURCE_DIR}/src/game/state/gameState
    ${CMAKE_SOURCE_DIR}/src/game/gui/button
    ${CMAKE_SOURCE_DIR}/src/game/window
)