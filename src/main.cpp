#include "game/game.h"

int main(int argc, char* argv[]) {
    Game game;

    while( game.isRunning() ) {
        game.tick();
    }

    return 0;
}