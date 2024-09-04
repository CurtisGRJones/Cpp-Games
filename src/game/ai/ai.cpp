#ifndef AI_H
#define AI_H

#include "ai.h"

Ai::Ai()
{
}

Ai::~Ai()
{
}

int Ai::getMove(std::unique_ptr<uint8_t[]> boardState) {
    // TODO build this better
    for ( uint8_t i = 0; i < 9; i++ ) {
        if( boardState[i] == 0 ) {
            return i;
        }
    }
}

#endif
