#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameState.h"
#include "../../game.h"

#include <iostream>

GameState::GameState(Game *game)
    : State(game),
      m_ai(Ai(
          [this](std::array<uint8_t, 9> *boardState)
          {
              return this->checkBoardForWin(boardState);
          },
          [this](std::array<uint8_t, 9> *boardState)
          {
              return this->checkBoardIsFull(boardState);
          })),
      m_resetButton(
          Button(
              25, 25, 100, 50,
              [this]()
              {
                  this->reset();
              },
              [](Window *window, SDL_Rect *rect)
              {
                  window->setDrawColour(255, 255, 0, 255);
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
    this->m_spaceButtons->reserve(9);
    for (Uint8 i = 0; i < this->m_SPACES_COUNT; i++)
    {
        int x = (i % 3);
        int y = int(i / 3);
        this->m_spaceButtons->push_back(Button(
            borderWidth + (spacing * x),
            borderWidth + topOffset + (spacing * y),
            spacing,
            spacing,
            [this, i]()
            {
                if (!this->m_endGame && !(this->m_useAi && this->m_aiTurn == this->m_player) && this->m_boardState[i] == 0)
                {
                    this->m_boardState[i] = int(this->m_player) + 1;
                    this->m_player = !this->m_player;
                }
            }));
    }
}

GameState::~GameState()
{
}

std::array<uint8_t, 9> GameState::copyBoardState()
{
    Uint8 size = 9;
    std::array<uint8_t, 9> newBoardState = {0};
    std::copy(this->m_boardState.begin(), this->m_boardState.end(), newBoardState.begin());
    return newBoardState;
}

Uint8 GameState::checkBoardForWin()
{
    return this->checkBoardForWin(&this->m_boardState);
}

Uint8 GameState::checkBoardForWin(std::array<uint8_t, 9> *boardState)
{
    for (int i = 0; i < 3; i++)
    {
        if (boardState->at(i * 3) != 0 &&
            boardState->at(i * 3) == boardState->at(i * 3 + 1) &&
            boardState->at(i * 3) == boardState->at(i * 3 + 2))
        {
            return boardState->at(i * 3);
        }

        if (boardState->at(i) != 0 &&
            boardState->at(i) == boardState->at(i + 3) &&
            boardState->at(i) == boardState->at(i + 6))
        {
            return boardState->at(i);
        }
    }

    if (boardState->at(0) != 0 &&
        boardState->at(0) == boardState->at(4) &&
        boardState->at(0) == boardState->at(8))
    {
        return boardState->at(0);
    }
    if (boardState->at(2) != 0 &&
        boardState->at(2) == boardState->at(4) &&
        boardState->at(2) == boardState->at(6))
    {
        return boardState->at(2);
    }


    return 0;
}

bool GameState::checkBoardIsFull()
{
    return this->checkBoardIsFull(&this->m_boardState);
}

bool GameState::checkBoardIsFull(std::array<uint8_t, 9> *boardState)
{
    for (int i = 0; i < 9; i++)
    {
        if (boardState->at(i) == 0)
        {
            return false;
        }
    }
    return true;
}

void GameState::checkBoardForEndGame()
{
    this->m_endGame =
        this->checkBoardForWin() != 0 ||
        this->checkBoardIsFull();
}

void GameState::draw(Window *window)
{
    window->clear();
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

void GameState::tick()
{
    this->checkBoardForEndGame();
    if (this->m_useAi && this->m_aiTurn == this->m_player && !this->m_endGame)
    {
        auto duplicateBoardState = this->copyBoardState();
        const Uint8 move = m_ai.getMove(&duplicateBoardState, this->m_aiTurn);
        if (move >= 0 && move < 9 && this->m_boardState[move] == 0)
        {
            this->m_boardState[move] = int(this->m_aiTurn) + 1;
            this->m_player = !this->m_player;
        }
    }
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
        if (this->m_menuButton.handleMouseButtonEvent(&(event->button)))
        {
            break;
        }
        for (Uint8 i = 0; i < this->m_SPACES_COUNT; i++)
        {
            if (this->m_spaceButtons->at(i).handleMouseButtonEvent(&(event->button)))
            {
                break;
            }
        }
    }
}

void GameState::reset()
{
    this->m_player = false;
    for (Uint8 i = 0; i < this->m_SPACES_COUNT; i++)
    {
        this->m_boardState[i] = 0;
    }
}

#endif