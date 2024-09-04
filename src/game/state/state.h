#pragma once

#include <SDL2/SDL.h>
#include "../window/window.h"

class Game;

class State
{
protected:
    Game *m_game;
public:
    State(Game *m_game);
    ~State();
    virtual void eventHandler(SDL_Event *event) {};
    virtual void tick() {};
    virtual void draw(Window* window) {};
};