#include "Game.h"
#include "Groudon.h"
#include "Config.h"

int main(void)
{
    Game g;

    sf::Texture texture;
    if (!texture.loadFromFile(GROUDON_TEXTURE_PATH))
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
        count++;
        g.drawEntity(groudon);
        g.display();
    }

    return 0;
}