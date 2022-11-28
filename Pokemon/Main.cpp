#include "Game.h"
#include "Groudon.h"
#include "Config.h"

int main(void)
{
    Game g;
   
    int count = 0;
    while (g.isOpen())
    {
        g.clear();
        g.handleEvents();

        //MainMenu Displaying
        g.drawBackground();
        g.drawPokeball();
        g.drawTitle();
        g.drawEnterText();
#include "mainCharacter.h"
#include "Map.h"

using namespace std;


        g.display();
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    mainCharacter mainCharMap(&window);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        mainCharMap.InitChar();
        window.display();
    }

    return 0;
}