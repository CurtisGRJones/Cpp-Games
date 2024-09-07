#include "menuState.h"
#include "../../game.h"

MenuState::MenuState(Game *game)
    : State(game)
{
    buttons.reserve(10);
    buttons.push_back(
        Button(
            50, 50, 100, 50,
            [this]() {
                this->m_game->changeState(StateKey::GAME);
            },
            [](Window* window, SDL_Rect *rect) {
                window->setDrawColour(0, 0, 255, 255);
                window->drawFillRect(rect->x, rect->y, rect->w, rect->h);
            }
        )
    );

    buttons.push_back(
        Button(
            450, 50, 100, 50,
            [this]() {
                this->m_game->quitGame();
            },
            [](Window* window, SDL_Rect *rect) {
                window->setDrawColour(255, 0, 0, 255);
                window->drawFillRect(rect->x, rect->y, rect->w, rect->h);
            }
        )
    );
}

MenuState::~MenuState() {

}

void MenuState::eventHandler(SDL_Event *event) {
    switch (event->type)
    {
        case SDL_MOUSEBUTTONDOWN:
            for(Button& i : this->buttons) 
                if(i.handleMouseButtonEvent(&event->button)) {
                    break;
                };
    }
}

void MenuState::draw(Window *window) {
    window->clear();
    window->setDrawColour(0, 0, 0, 255);
    window->setBackgroundColour(255, 255, 255, 255);

    for(Button& i : this->buttons) 
        i.draw(window);
}