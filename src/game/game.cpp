#include "game.h"

Game::Game()
{
    this->m_states.insert(
        std::pair<StateKey, std::shared_ptr<GameState>>(
            StateKey::GAME, std::make_shared<GameState>(this)));

    this->m_currentState = this->m_states[StateKey::GAME];
}

Game::~Game()
{
}

void Game::tick()
{
    // TODO throttle delay
    this->eventHandler();
    this->m_currentState->tick();
    this->m_currentState->draw(&(this->m_window));
    this->m_window.pushRenderToWindow();

    // 16
    SDL_Delay(16);
}

void Game::eventHandler()
{
    while (SDL_PollEvent(&this->m_event))
    {
        switch (this->m_event.type)
        {
        case SDL_QUIT:
            this->quitGame();
            break;
        default:
            this->m_currentState->eventHandler(&(this->m_event));
        }
    }
}

bool Game::isRunning()
{
    return this->m_running;
}

void Game::quitGame()
{
    SDL_Quit();
    this->m_running = false;
}

void Game::changeState(StateKey key)
{
    this->m_currentState = this->m_states[key];
}

void Game::changeState(std::shared_ptr<State> newState)
{
    this->m_currentState = newState;
}
