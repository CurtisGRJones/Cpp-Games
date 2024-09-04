#pragma once

#include <map>

class GameBase
{
private:
    
public:
    GameBase();
    ~GameBase();

    virtual void eventHandler(SDL_Event *event) {};
    virtual void tick() {};
};
