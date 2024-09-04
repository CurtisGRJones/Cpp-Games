cmake_minimum_required(VERSION 3.16)
project(TicTakToe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL2_INCLUDE_DIR "/usr/include/SDL2")
set(SDL2_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2.so")

find_package(SDL2 REQUIRED)

add_executable(TicTakToe 
    src/main.cpp
    src/game/game.cpp
    src/game/game.h
    src/game/ai/ai.cpp
    src/game/ai/ai.h
    src/game/gui/button/button.cpp
    src/game/gui/button/button.h
    src/game/state/gameState/gameState.cpp
    src/game/state/gameState/gameState.h
    src/game/state/menuState/menuState.cpp
    src/game/state/menuState/menuState.h
    src/game/state/state.h
    src/game/state/state.cpp
    src/game/window/window.cpp
    src/game/window/window.h
)

target_include_directories(TicTakToe PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(TicTakToe ${SDL2_LIBRARIES})