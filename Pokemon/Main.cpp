

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "mainCharacter.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(mainCharSprite);
        window.display();
    }

    return 0;
}