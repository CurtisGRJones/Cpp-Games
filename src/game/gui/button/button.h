#pragma once

#include <SDL2/SDL.h>
#include <functional>

#include "../../window/window.h"

class Button
{
private:
    SDL_Rect rect;

    std::function<void()> m_onClick;
    std::function<void(Window *window, SDL_Rect *rect)> m_draw;

private:
    void setRect(int x, int y, int w, int h);

public:
    Button(int x, int y, int w, int h, std::function<void()> onClick);
    Button(int x, int y, int w, int h, std::function<void()> onClick, std::function<void(Window *window, SDL_Rect *rect)> draw);
    ~Button();

    // TODO add resize
    bool handleMouseButtonEvent(SDL_MouseButtonEvent *event);
    void draw(Window *window);
};