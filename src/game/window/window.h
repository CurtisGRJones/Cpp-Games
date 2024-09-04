#pragma once

#include <SDL2/SDL.h>
#include <memory>

// TODO use error codes of SDL

class Window
{
public:
    Window();
    ~Window();

    bool setBackgroundColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    bool setDrawColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    bool drawFillRect(int x, int y, int w, int h);
    bool drawFillRect(SDL_Rect *rect);

    bool drawX(int x, int y, int w);
    bool drawO(int x, int y, int w);

    bool pushRenderToWindow();

    bool clear();
private:
    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEIGHT = 700;

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
};