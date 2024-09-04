#pragma once

#include <iostream>

#include <memory>
#include <map>
#include <string>
#include <SDL2/SDL.h>

#include "state/state.h"

#include "window/window.h"

enum class StateKey
{
    GAME,
    WIN,
    MENU
};

class Game
{
public:
private:
    Window m_window;

    bool m_running = true;
    float m_lastTickTime = 0.0f;
    std::shared_ptr<State> m_currentState;

    std::map<StateKey, std::shared_ptr<State>> m_states;

    SDL_Event m_event;

public:
    Game();
    ~Game();

    void tick();
    void eventHandler();

    bool isRunning();
    // TODO add an exit status
    void quitGame();

    void changeState(StateKey key);
    void changeState(std::shared_ptr<State> newState);

private:
};