<<<<<<< HEAD
#include "Game.h"
#include "Groudon.h"
#include "Config.h"

int main(void)
{
    Game g;

    sf::Texture texture;
    if (!texture.loadFromFile(GROUDON_TEXTURE_PATH))
=======


#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "mainCharacter.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    
    while (window.isOpen())
>>>>>>> 10f93526d42f58382ee07724ae041038f4ef16f2
    {
        // error...
    }

    Groudon groudon = Groudon(texture);

    int count = 0;
    while (g.isOpen())
    {
        g.clear();
        g.handleEvents();
        if (count % 20 == 0)
        {
            groudon.nextAnimation();
            count = 0;
        }
<<<<<<< HEAD
        count++;
        g.drawEntity(groudon);
        g.display();
=======
        window.clear();
        window.draw(mainCharSprite);
        window.display();
>>>>>>> 10f93526d42f58382ee07724ae041038f4ef16f2
    }

    return 0;
}