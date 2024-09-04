#ifndef STATE_H
#define STATE_H

#include "StateBase.h"
#include "../GameRunner.h"

StateBase::StateBase(GameRunenr *game)
    : m_game(game)
{
}

StateBase::~StateBase()
{
}

#endif