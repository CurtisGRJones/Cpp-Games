#include <SDL2/SDL.h>
#include <functional>


class Button
{
private:
    int m_x1, m_x2, m_y1, m_y2;

    std::function<void()> m_onClick;
    std::function<void()> m_draw;

public:
    Button(int x1, int y1, int x2, int y2, std::function<void()> onClick);
    Button(int x1, int y1, int x2, int y2, std::function<void()> onClick, std::function<void()> draw);
    ~Button();

    // TODO add resize
    void handleMouseButtonEvent(SDL_MouseButtonEvent *event);
    void draw();
};

Button::Button(int x1, int y1, int x2, int y2, std::function<void()> onClick)
    : m_x1(x1), m_x2(x2), m_y1(y1), m_y2(y2),
      m_onClick(onClick)
{
}

Button::Button(int x1, int y1, int x2, int y2, std::function<void()> onClick, std::function<void()> draw)
    : m_x1(x1), m_x2(x2), m_y1(y1), m_y2(y2),
      m_onClick(onClick), m_draw(draw)
{
}

Button::~Button()
{
}

void Button::handleMouseButtonEvent(SDL_MouseButtonEvent *event)
{
    if (
        event->x > this->m_x1 &&
        event->x < this->m_x2 &&
        event->y > this->m_y1 &&
        event->y < this->m_y2)
    {
        if (this->m_onClick)
        {
            this->m_onClick();
        }
    }
}

void Button::draw()
{
    if (this->m_draw)
    {
        this->draw();
    }
}
