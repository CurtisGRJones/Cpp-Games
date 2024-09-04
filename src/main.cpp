#include "GameRunner/GameRunner.h"

#include <random>
#include <chrono>

int main(int argc, char* argv[]) {
    GameRunner runner;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    while( runner.isRunning() ) {
        runner.tick();
    }

    return 0;
}