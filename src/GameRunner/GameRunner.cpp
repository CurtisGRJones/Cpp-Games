#include "GameRunner.h"

GameRunner::GameRunner()
{
    this->m_games[GameKey::TIC_TAC_TOE] = TicTacToe 
    this->m_currentGame = this->m_games[GameKey::MAIN_MENU];
}

GameRunner::~GameRunner()
{
}

void GameRunner::tick()
{
    SDL_Delay(16);
}

void GameRunner::eventHandler()
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

bool GameRunner::isRunning()
{
    return this->m_running;
}

void GameRunner::quitGame()
{
    SDL_Quit();
    this->m_running = false;
}

void GameRunner::setGame(GameKey gameKey) {
    this->setGame(this->m_games[gameKey]);
}

void GameRunner::setGame(std::shared_ptr<GameBase> game){
    this->m_currentGame = game;
}
