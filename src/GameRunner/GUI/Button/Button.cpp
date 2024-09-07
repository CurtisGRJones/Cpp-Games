#include "button.h"

Button::Button(int x, int y, int w, int h, std::function<void()> onClick)
    : m_onClick(onClick)
{
    this->setRect(x, y, w, h);
}

Button::Button(int x, int y, int w, int h, std::function<void()> onClick, std::function<void(Window *window, SDL_Rect *rect)> draw)
    : m_onClick(onClick), m_draw(draw)
{
    this->setRect(x, y, w, h);
}

Button::~Button()
{
}

void Button::setRect(int x, int y, int w, int h)
{
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = w;
    this->rect.h = h;
}

bool Button::handleMouseButtonEvent(SDL_MouseButtonEvent *event)
{

    if (
        event->x > this->rect.x &&
        event->x < this->rect.x + this->rect.w &&
        event->y > this->rect.y &&
        event->y < this->rect.y + this->rect.h)
    {
        if (this->m_onClick)
        {
            this->m_onClick();
            return true;
        }
    }
    return false;
}

void Button::draw(Window *window)
{
    if (this->m_draw)
    {
        // TODO save and revert draw colour
        this->m_draw(window, &this->rect);
    }
}
