#pragma once

#include <SDL2/SDL.h>

#include "../window/window.h"

class State
{
private:
public:
    virtual void eventHandler(SDL_Event *event) {};
    virtual void tick() {};
    virtual void draw(Window* window) {};
};