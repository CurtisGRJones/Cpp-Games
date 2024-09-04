#pragma once

#include "../state.h"
#include "../../gui/button/button.h"

class GameState: public State
{
private:
    const Uint8 m_SPACES_COUNT = 9;

    // TODO compress to use logical expreessions to represent this
    Uint8 m_boardState[9];

    std::unique_ptr<Button> m_spaceButtons[9];

    bool player = false;

    // TODO fix this madness
    int screenWidth = 600;
    int screenHeight = 600;
    int borderWidth = 60;
    int width = screenWidth - (2 * borderWidth);
    int height = screenHeight - (2 * borderWidth);

    int lineWidth = 10;
    int lineLength = std::min(width, height);

    int spacing = int(lineLength / 3);

    int l = borderWidth + spacing - int(lineWidth / 2);
    int r = l + spacing;

public:
    GameState();
    ~GameState();

    void eventHandler(SDL_Event *event);
    void draw(Window *window);

    void refresh();
};

GameState::GameState()
{
    this->refresh();

    for ( Uint8 i = 0; i < this->m_SPACES_COUNT; i++ ) {
        int x = (i % 3);
        int y = int(i / 3);
        this->m_spaceButtons[i] = std::make_unique<Button>(
            borderWidth + ( spacing * x ), 
            borderWidth + ( spacing * y ), 
            borderWidth + ( spacing * (x + 1) ), 
            borderWidth + ( spacing * (y + 1) ),
            [this, i]() {
                if (this->m_boardState[i] == 0) {
                    this->m_boardState[i] = int(this->player) + 1;
                    this->player = !this->player;
                }
            } 
        );
    } 
}

GameState::~GameState()
{
}

void GameState::draw(Window* window) {
    window->setDrawColour(0, 0, 0, 255);
    window->setBackgroundColour(255, 255, 255, 255);

    window->drawFillRect(l, borderWidth, lineWidth, lineLength);
    window->drawFillRect(r, borderWidth, lineWidth, lineLength);
    window->drawFillRect(borderWidth, l, lineLength, lineWidth);
    window->drawFillRect(borderWidth, r, lineLength, lineWidth);

    for ( Uint8 i = 0; i < this->m_SPACES_COUNT; i++ ) {
        int x, y;
        switch( this->m_boardState[i] ){
            case 1:
                x = (i % 3);
                y = int(i / 3);
                window->drawX(
                    borderWidth + ( spacing * x ), 
                    borderWidth + ( spacing * y ), 
                    spacing
                );
                break;
            case 2:
                x = (i % 3);
                y = int(i / 3);
                window->drawO(
                    borderWidth + ( spacing * x ), 
                    borderWidth + ( spacing * y ), 
                    spacing
                );
                break;
        }
    } 
}

void GameState::eventHandler(SDL_Event *event) {
    switch (event->type) {
        case SDL_MOUSEBUTTONDOWN:
            for( Uint8 i = 0; i < this->m_SPACES_COUNT; i++ ) {
                this->m_spaceButtons[i]->handleMouseButtonEvent(&(event->button));
            }
    }
}

void GameState::refresh() {
    for ( Uint8 i = 0; i < this->m_SPACES_COUNT; i++ ) {
        this->m_boardState[i] = 0;
    } 
}
