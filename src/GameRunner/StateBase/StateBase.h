#pragma once

#include <SDL2/SDL.h>
#include "../window/window.h"

class GameRunenr;

class StateBase
{
protected:
    GameRunenr *m_game;
public:
    StateBase(GameRunenr *m_game);
    ~StateBase();
    virtual void eventHandler(SDL_Event *event) {};
    virtual void tick() {};
    virtual void draw(Window* window) {};
};