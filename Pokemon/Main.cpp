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
}



//#include "mainCharacter.h"
//#include "Map.h"
//
//using namespace std;
//
//
//        g.display();
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
//    mainCharacter mainCharMap(&window);
//    
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        window.clear();
//        mainCharMap.InitChar();
//        window.display();
//    }
//
//    return 0;
//}