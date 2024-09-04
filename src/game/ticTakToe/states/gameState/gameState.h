#pragma once

#include "../../../state/state.h"
#include "../../gui/button/button.h"
#include "../../ai/ai.h"

#include <vector>

class GameState : public State
{
private:
    const Uint8 m_SPACES_COUNT = 9;

    // TODO compress to use logical expreessions to represent this
    std::array<uint8_t, 9> m_boardState;

    std::vector<Button> m_spaceButtons[9];
    Button m_resetButton;
    Button m_menuButton;

    Ai m_ai;

    bool m_player = false;
    bool m_useAi = true;
    bool m_aiTurn = false;
    bool m_endGame = false;

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

private:
    std::array<uint8_t, 9> copyBoardState();
    Uint8 checkBoardForWin();
    Uint8 checkBoardForWin(std::array<uint8_t, 9> *boardState);
    bool checkBoardIsFull();
    bool checkBoardIsFull(std::array<uint8_t, 9> *boardState);
    void checkBoardForEndGame();

public:
    GameState(Game *game);
    ~GameState();

    void eventHandler(SDL_Event *event);
    void draw(Window *window);
    void tick();

    void reset();
};
