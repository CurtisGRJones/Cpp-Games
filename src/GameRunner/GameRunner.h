#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>

#include "Window/Window.h"
#include "GameBase/GameBase.h"

enum class GameKey
{
    MAIN_MENU,
    TIC_TAC_TOE,
    GOBBLET,
};

class GameRunner
{
public:
private:
    Window m_window;

    bool m_running = true;
    float m_lastTickTime = 0.0f;
    SDL_Event m_event;
    
    std::unordered_map<GameKey, std::shared_ptr<GameBase>> m_games;
    std::shared_ptr<GameBase> m_currentGame;

    // TODO add main menu screen
public:
    GameRunner();
    ~GameRunner();

    void tick();
    void eventHandler();

    bool isRunning();
    // TODO add an exit status
    void quitGame();

    void setGame(GameKey gameKey);
    void setGame(std::shared_ptr<GameBase> game);
private:
};