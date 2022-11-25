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


        g.display();
    }

    return 0;
}