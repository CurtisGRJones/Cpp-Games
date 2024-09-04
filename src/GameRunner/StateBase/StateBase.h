#pragma once

#include <SDL2/SDL.h>
#include "../window/window.h"

class GameRunner;

class StateBase
{
protected:
    GameRunner *m_game;
public:
    StateBase(GameRunner *m_game);
    ~StateBase();
    virtual void eventHandler(SDL_Event *event) {};
    virtual void tick() {};
    virtual void draw(Window* window) {};
};