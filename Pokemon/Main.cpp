#include "Game.h"
#include "Groudon.h"
#include "Config.h"
#include "SFML/Audio.hpp"

int main(void)
{
    Game g;
    
    int count = 0;
    int e = 0;
    while (g.isOpen())
    {
        switch (e)
        {
        case 0:
            g.clear();
            g.handleEvents();
            g.drawBackground();
            g.drawPokeball();
            g.drawTitle();
            g.audioMainMenu();
            g.drawEnterText(/*deltatime*/);
            g.display();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                e = 1;
                g.clear();
            }
            break;


        case 1:
            g.clear();
            g.handleEvents();
            g.drawPokeball();
            g.drawTitle();

            g.displayPlayButton();
            g.displaySettingsButton();
            g.displayQuitButton();

            g.display();
         default:
            break;
        }
    }

    return 0;
}