#pragma once

#include <memory>
#include <map>
#include <string>
#include <SDL2/SDL.h>

#include "Window/Window.h"
#include "GameBase/GameBase.h"

enum class GameKey
{
    TIC_TAC_TOE,
    GOBBLET,
};

class GameRunenr
{
public:
private:
    Window m_window;

    bool m_running = true;
    float m_lastTickTime = 0.0f;
    SDL_Event m_event;
    
    std::map<GameKey, std::shared_ptr<GameBase>> m_gameMap;
    std::shared_ptr<GameBase> m_currentGame;

public:
    GameRunenr();
    ~GameRunenr();

    void tick();
    void eventHandler();

    bool isRunning();
    // TODO add an exit status
    void quitGame();

    void changeGame(GameKey gameKey);
    void changeGame(std::shared_ptr<GameBase> game);
private:
};