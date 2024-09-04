#ifndef STATE_H
#define STATE_H

#include "StateBase.h"
#include "../GameRunner.h"

StateBase::StateBase(GameRunner *game)
    : m_game(game)
{
}

StateBase::~StateBase()
{
}

#endif