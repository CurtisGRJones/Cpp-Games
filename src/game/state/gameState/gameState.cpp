#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameState.h"
#include "../../game.h"

GameState::GameState(Game *game)
    : State(game),
    m_resetButton(
          Button(
              25, 25, 100, 50,
              [this]()
              {
                  this->reset();
              },
              [](Window *window, SDL_Rect *rect)
              {
                  window->setDrawColour(255, 0, 0, 255);
                  window->drawFillRect(rect->x, rect->y, rect->w, rect->h);
              })),
    m_menuButton(
          Button(
              475, 25, 100, 50,
              [this]()
              {
                  this->m_game->changeState(StateKey::MENU);
              },
              [](Window *window, SDL_Rect *rect)
              {
                  window->setDrawColour(0, 255, 0, 255);
                  window->drawFillRect(rect->x, rect->y, rect->w, rect->h);
              }))
{
    this->reset();

    for (Uint8 i = 0; i < this->m_SPACES_COUNT; i++)
    {
        int x = (i % 3);
        int y = int(i / 3);
        this->m_spaceButtons[i] = std::make_unique<Button>(
            borderWidth + (spacing * x),
            borderWidth + topOffset + (spacing * y),
            spacing,
            spacing,
            [this, i]()
            {
                if (this->m_boardState[i] == 0)
                {
                    this->m_boardState[i] = int(this->player) + 1;
                    this->player = !this->player;
                }
            });
    }
}

GameState::~GameState()
{
}

void GameState::draw(Window *window)
{
    window->setDrawColour(0, 0, 0, 255);
    window->setBackgroundColour(255, 255, 255, 255);

    window->drawFillRect(l, borderWidth + topOffset, lineWidth, lineLength);
    window->drawFillRect(r, borderWidth + topOffset, lineWidth, lineLength);
    window->drawFillRect(borderWidth, l + topOffset, lineLength, lineWidth);
    window->drawFillRect(borderWidth, r + topOffset, lineLength, lineWidth);

    for (Uint8 i = 0; i < this->m_SPACES_COUNT; i++)
    {
        int x, y;
        switch (this->m_boardState[i])
        {
        case 1:
            x = (i % 3);
            y = int(i / 3);
            window->drawX(
                borderWidth + (spacing * x),
                borderWidth + topOffset + (spacing * y),
                spacing);
            break;
        case 2:
            x = (i % 3);
            y = int(i / 3);
            window->drawO(
                borderWidth + (spacing * x),
                borderWidth + topOffset + (spacing * y),
                spacing);
            break;
        }
    }

    this->m_resetButton.draw(window);
    this->m_menuButton.draw(window);
}

void GameState::eventHandler(SDL_Event *event)
{
    // TODO find a way to automaticallt register when a button is pressed
    switch (event->type)
    {
    case SDL_MOUSEBUTTONDOWN:
        if (this->m_resetButton.handleMouseButtonEvent(&(event->button)))
        {
            break;
        }
        for (Uint8 i = 0; i < this->m_SPACES_COUNT; i++)
        {
            if (this->m_spaceButtons[i]->handleMouseButtonEvent(&(event->button)))
            {
                break;
            }
        }
    }
}

void GameState::reset()
{
    this->player = false;
    for (Uint8 i = 0; i < this->m_SPACES_COUNT; i++)
    {
        this->m_boardState[i] = 0;
    }
}

#endif