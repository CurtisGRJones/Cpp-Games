#pragma once

#include "../state.h"
#include "../../gui/button/button.h"

class GameState : public State
{
private:
    const Uint8 m_SPACES_COUNT = 9;

    // TODO compress to use logical expreessions to represent this
    Uint8 m_boardState[9];

    std::unique_ptr<Button> m_spaceButtons[9];
    Button m_resetButton;
    Button m_menuButton;

    bool player;

    // TODO fix this madness
    int screenWidth = 600;
    int screenHeight = 600;

    int topOffset = 100;

    int borderWidth = 60;
    int width = screenWidth - (2 * borderWidth);
    int height = screenHeight - (2 * borderWidth);

    int lineWidth = 10;
    int lineLength = std::min(width, height);

    int spacing = int(lineLength / 3);

    int l = borderWidth + spacing - int(lineWidth / 2);
    int r = l + spacing;

public:
    GameState(Game *game);
    ~GameState();

    void eventHandler(SDL_Event *event);
    void draw(Window *window);

    void reset();
};
