#pragma once

#include <vector>

#include "../../../state/state.h"
#include "../../gui/button/button.h"

class MenuState : public State
{
private:
    std::vector<Button> buttons;
public:
    MenuState(Game *game);
    ~MenuState();

    void eventHandler(SDL_Event *event);
    void draw(Window *window);

};
