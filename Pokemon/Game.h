#pragma once
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"

class Game
{
private:
    sf::RenderWindow _window;
    float opacity;

public:
    Game(void);

    //Global display
    bool isOpen(void) const;
    void handleEvents(void);
    void update();
    void clear(void);
    void display(void);
    void drawTitle();
    void drawPokeball();

    //MainMenu display
    void audioMainMenu();
    void drawBackground();
    void drawEnterText();

    //BigMainMenu display
    void displayPlayButton();
    void displaySettingsButton();
    void displayQuitButton();
};