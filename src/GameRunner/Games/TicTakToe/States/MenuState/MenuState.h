#pragma once

#include <vector>

#include "../../../state/state.h"
#include "../../gui/button/button.h"

class MenuState : public StateBase
{
private:
    std::vector<Button> buttons;
public:
    MenuState(GameRunenr *game);
    ~MenuState();

    void eventHandler(SDL_Event *event);
    void draw(Window *window);

};
