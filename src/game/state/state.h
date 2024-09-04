#pragma once

#include <SDL2/SDL.h>

#include "../game.h"
#include "../window/window.h"
class State
{
public:
    State();
    ~State();
    virtual void eventHandler(SDL_Event *event) {};
    virtual void tick() {};
    virtual void draw(Window* window) {};
};