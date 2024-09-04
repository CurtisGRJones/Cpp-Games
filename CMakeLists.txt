cmake_minimum_required(VERSION 3.16)
project(Games)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL2_INCLUDE_DIR "/usr/include/SDL2")
set(SDL2_LIBRARIES "/usr/lib/x86_64-linux-gnu/libSDL2.so")

find_package(SDL2 REQUIRED)

add_executable(Games 
    src/main.cpp
    src/game/gui/button/button.cpp
    src/game/gui/button/button.h
    src/game/window/window.cpp
    src/game/window/window.h
    src/game/game.cpp
    src/game/game.h
    src/game/state/mainMenu/mainMenu.cpp
    src/game/state/mainMenu/mainMenu.h
    src/game/state/state.h
    src/game/state/state.cpp

    #Tic Tac Toe
    src/game/ticTakToe/ticTacToe.cpp
    src/game/ticTakToe/ticTacToe.h
    src/game/ticTakToe/ai/ai.cpp
    src/game/ticTakToe/ai/ai.h
    src/game/ticTakToe/states/gameState/gameState.cpp
    src/game/ticTakToe/states/gameState/gameState.h
    src/game/ticTakToe/states/menuState/menuState.cpp
    src/game/ticTakToe/states/menuState/menuState.h
    
    
    # Gobblet

)

target_include_directories(Games PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(Games ${SDL2_LIBRARIES})