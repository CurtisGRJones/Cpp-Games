#ifndef GAMERUNNER_H
#define GAMERUNNER_H

#include "GameRunner.h"

GameRunenr::GameRunenr()
{
}

GameRunenr::~GameRunenr()
{
}

void GameRunenr::tick()
{
    SDL_Delay(16);
}

void GameRunenr::eventHandler()
{
    while (SDL_PollEvent(&this->m_event))
    {
        switch (this->m_event.type)
        {
        case SDL_QUIT:
            this->quitGame();
            break;
        default:
            this->m_currentGame->eventHandler(&(this->m_event));
        }
    }
}

bool GameRunenr::isRunning()
{
    return this->m_running;
}

void GameRunenr::quitGame()
{
    SDL_Quit();
    this->m_running = false;
}

#endif
