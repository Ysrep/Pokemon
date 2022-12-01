#pragma once
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "BattleScreen.h"

class Game
{
private:
    sf::RenderWindow _window;
    
    float opacity;
    BattleScreen Battle;

public:
    bool GoeliseTravel;

    sf::Sprite movingWingull;
    sf::Sprite movingWingull2;

    sf::Sprite background;
    sf::Texture arena;

    Game(void);

    //Global display
    bool isOpen(void) const;
    void handleEvents(void);
    void update();
    void clear(void);
    void display(void);
    void drawTitle();
    void drawPokeball();
    void goeliseTravel();
    void goeliseTravel2();


    //MainMenu display
    void drawBackground();
    void drawBackgroundSettings();
    
    void drawEnterText();

    //BigMainMenu display
    void displayPlayButton();
    void displaySettingsButton();
    void displayQuitButton();

    //battle window
    void GameBattleScreen();
    void WildPokemon();
    BattleScreen getBattle();

    //getwindow
    sf::RenderWindow& GetWindow();
};