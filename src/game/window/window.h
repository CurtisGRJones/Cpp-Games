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

Window::Window()
    : m_window(nullptr, SDL_DestroyWindow),
    m_renderer(nullptr, SDL_DestroyRenderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("Failed to initialize SDL: " + std::string(SDL_GetError()));
    }

    SDL_Window* window = SDL_CreateWindow(
        "Tik Tak Toe",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->SCREEN_WIDTH,
        this->SCREEN_HEIGHT,
        0
    );

    if (!window) {
        SDL_Quit();
        throw std::runtime_error("Failed to create SDL window: " + std::string(SDL_GetError()));
    }

    m_window.reset(window);

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        0
    );

    if (!renderer) {
        throw std::runtime_error("Failed to create SDL_Renderer: " + std::string(SDL_GetError()));
    }

    m_renderer.reset(renderer);
}

Window::~Window()
{
    SDL_Quit();
}

bool Window::setBackgroundColour(
    Uint8 r,
    Uint8 g,
    Uint8 b,
    Uint8 a
) {
    Uint8 oR, oG, oB, oA;
    SDL_GetRenderDrawColor(
        this->m_renderer.get(),
        &oR, &oG, &oB, &oA
    );
    this->setDrawColour(r, g, b, a);
    this->drawFillRect(0, 0, this->SCREEN_WIDTH, this->SCREEN_HEIGHT);
    this->setDrawColour(oR, oG, oB, oA);
    return true;
}

bool Window::setDrawColour(
    Uint8 r,
    Uint8 g,
    Uint8 b,
    Uint8 a
) {
    SDL_SetRenderDrawColor(
        this->m_renderer.get(),
        r, g, b, a
    );

    return true;
}

bool Window::drawFillRect(
    int x, 
    int y, 
    int w, 
    int h
) {
    // TODO test for valid cords
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_RenderFillRect(
        this->m_renderer.get(),
        &rect
    );

    return true;
}

bool Window::drawX(int x, int y, int w) {
    SDL_Renderer *renderer = this->m_renderer.get();

    int border = int(w / 10);

    SDL_RenderDrawLine(renderer, x+border, y+border, x+w-border, y+w-border);
    SDL_RenderDrawLine(renderer, x+border, y+w-border, x+w-border, y+border);

    return true;
}

bool Window::drawO(int x, int y, int w) {
    SDL_Renderer *renderer = this->m_renderer.get();

    int radius = int(w * 8 / 20);
    int x0 = x + w/2;
    int y0 = y + w/2;
    int f = 1 - radius;
    int ddF_x = 1;
    int ddF_y = -2 * radius;
    int x1 = 0;
    int y1 = radius;

    SDL_RenderDrawPoint(renderer, x0, y0 + radius);
    SDL_RenderDrawPoint(renderer, x0, y0 - radius);
    SDL_RenderDrawPoint(renderer, x0 + radius, y0);
    SDL_RenderDrawPoint(renderer, x0 - radius, y0);

    while (x1 < y1) {
        if (f >= 0) {
            y1--;
            ddF_y += 2;
            f += ddF_y;
        }
        x1++;
        ddF_x += 2;
        f += ddF_x;
        SDL_RenderDrawPoint(renderer, x0 + x1, y0 + y1);
        SDL_RenderDrawPoint(renderer, x0 - x1, y0 + y1);
        SDL_RenderDrawPoint(renderer, x0 + x1, y0 - y1);
        SDL_RenderDrawPoint(renderer, x0 - x1, y0 - y1);
        SDL_RenderDrawPoint(renderer, x0 + y1, y0 + x1);
        SDL_RenderDrawPoint(renderer, x0 - y1, y0 + x1);
        SDL_RenderDrawPoint(renderer, x0 + y1, y0 - x1);
        SDL_RenderDrawPoint(renderer, x0 - y1, y0 - x1);
    }

    return true;
}

bool Window::pushRenderToWindow() {
    SDL_RenderPresent(this->m_renderer.get());
    return true;
}

bool Window::clear() {
    SDL_RenderClear(this->m_renderer.get());
    return true;
}