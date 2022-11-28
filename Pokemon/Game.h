#pragma once
#include <SFML/Window.hpp>

#include "Entity.h"

class Game
{
private:
    sf::RenderWindow _window;

public:
    Game(void);

    //
    bool isOpen(void) const;
    void handleEvents(void);
    void update();
    void clear(void);
    void display(void);

    //
    void drawBackground();
    void drawTitle();
    void drawPokeball();
    void drawEnterText();
};