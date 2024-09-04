#ifndef STATE_H
#define STATE_H

#include "state.h"
#include "../game.h"

State::State(Game *game)
    : m_game(game)
{
}

State::~State()
{
}

#endif