cmake_minimum_required(VERSION 3.16)
project(Games)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL2_INCLUDE_DIR "/usr/include/SDL2")
set(SDL2_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2.so")

find_package(SDL2 REQUIRED)

add_executable(Games 
    src/main.cpp

    # GameRunner
    src/GameRunner/GameBase/GameBase.cpp
    src/GameRunner/GameBase/GameBase.h
    src/GameRunner/GameRunner.cpp
    src/GameRunner/GameRunner.h

    # GUI
    src/GameRunner/GUI/Button/Button.cpp
    src/GameRunner/GUI/Button/Button.h

    # StateBase
    src/GameRunner/StateBase/mainMenu/mainMenu.cpp
    src/GameRunner/StateBase/mainMenu/mainMenu.h
    src/GameRunner/StateBase/StateBase.cpp
    src/GameRunner/StateBase/StateBase.h

    # Window
    src/GameRunner/Window/Window.cpp
    src/GameRunner/Window/Window.h

    # TicTacToe
    src/GameRunner/Games/TicTakToe/TicTacToe.cpp
    src/GameRunner/Games/TicTakToe/TicTacToe.h
    src/GameRunner/Games/TicTakToe/Ai/Ai.cpp
    src/GameRunner/Games/TicTakToe/Ai/Ai.h
    src/GameRunner/Games/TicTakToe/States/GameState/GameState.cpp
    src/GameRunner/Games/TicTakToe/States/GameState/GameState.h
    src/GameRunner/Games/TicTakToe/States/MenuState/MenuState.cpp
    src/GameRunner/Games/TicTakToe/States/MenuState/MenuState.h

    # Gobblet
    src/GameRunner/Games/Gobblet/Gobblet.cpp
    src/GameRunner/Games/Gobblet/Gobblet.h
)

target_include_directories(Games PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(Games ${SDL2_LIBRARIES})