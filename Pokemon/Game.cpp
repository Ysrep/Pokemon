#include "Game.h"

Game::Game() : _window(sf::VideoMode(1000, 650), "GROUDON")
{
    this->_window.setFramerateLimit(60);
}

bool Game::isOpen(void) const
{
    return this->_window.isOpen();
}

void Game::handleEvents(void)
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->_window.close();
    }
}

void Game::clear(void)
{
    this->_window.clear();
}

void Game::display(void)
{
    this->_window.display();
}

//MAIN MENU - Displaying the Images
void Game::drawBackground()
{
    sf::Texture arena;
    arena.setSmooth(true);
    sf::Sprite background;
    background.setScale(sf::Vector2f(1.5f, 2.f));

    if (!arena.loadFromFile("Textures/Mainmenu/arena.jpg"))
    {

    }
    background.setTexture(arena);

    this->_window.draw(background);
}

void Game::drawTitle()
{
    sf::Texture title;
    title.setSmooth(true);
    sf::Sprite titleText;
    titleText.setScale(sf::Vector2f(0.8f, 0.8f));

    if (!title.loadFromFile("Textures/Mainmenu/titlePokemon.png"))
    {

    }
    titleText.setTexture(title);
    titleText.setPosition(sf::Vector2f(225, 55)); // absolute position

    this->_window.draw(titleText);
}

void Game::drawPokeball() {

    sf::Texture ball;
    ball.setSmooth(true);
    sf::Sprite pokeBall;
    pokeBall.setScale(sf::Vector2f(0.4f, 0.4f));
    pokeBall.setPosition(sf::Vector2f(500.f, 50.f)); // absolute position


    if (!ball.loadFromFile("Textures/Mainmenu/Pokeball.png"))
    {

    }
    pokeBall.setTexture(ball);

    this->_window.draw(pokeBall);

}

void Game::drawEnterText() {

    sf::Font font;
    sf::Clock clock;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text MainmenuText;
    MainmenuText.setFont(font);
    MainmenuText.setString("Press enter");
    MainmenuText.setCharacterSize(50);
    MainmenuText.setFillColor(sf::Color(0,0,0,250));
    MainmenuText.setOrigin((double)MainmenuText.getLocalBounds().width / 2, (double)MainmenuText.getLocalBounds().height / 2);
    MainmenuText.setPosition(sf::Vector2f(550.f, 500.f));// absolute position

   if (clock.getElapsedTime().asSeconds() > 2.f)
    {
        MainmenuText.setFillColor(sf::Color(0, 0, 0, 100));
    }

   clock.restart();

    this->_window.draw(MainmenuText);
}

