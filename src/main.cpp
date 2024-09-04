#include "game/game.h"

#include <random>
#include <chrono>

int main(int argc, char* argv[]) {
    Game game;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    while( game.isRunning() ) {
        game.tick();
    }

    return 0;
}