#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::Texture texture;
    sf::Sprite Chochodile;
    Chochodile.scale(sf::Vector2f(0.7, 0.7));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!texture.loadFromFile("Texture/chochodile.png"))
        {
            // erreur...
            return -1;
        }
        Chochodile.setTexture(texture);
        Chochodile.setPosition(sf::Vector2f(400, 400));
        Chochodile.rotate(10);
        window.clear();
        window.draw(Chochodile);
        window.display();
    }

    return 0;
}