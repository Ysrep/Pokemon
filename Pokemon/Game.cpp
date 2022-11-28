#include "Game.h"
#include <iostream>
#include "SFML/Audio.hpp"

Game::Game() : _window(sf::VideoMode(1000, 650), "Pokemon Salty")
{
    this->_window.setFramerateLimit(60);
    opacity = 0;

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
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
        std::cout << "Button " << event.mouseButton.button << " @ "
            << sf::Mouse::getPosition(_window).x << ", "
            << sf::Mouse::getPosition(_window).y << "\n";
        break;

    default:
        break;
    }

}

void Game::update() {
    bool Hover = false;

    if (Hover = true)
    {
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

    if (opacity >= 255)
    {
        opacity = 255;
    }
    sf::Font font;
    sf::Clock clock;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text MainmenuText;
    MainmenuText.setFont(font);
    MainmenuText.setString("Press enter");
    MainmenuText.setCharacterSize(50);
    MainmenuText.setFillColor(sf::Color(0,0,0,opacity));
    MainmenuText.setOrigin((double)MainmenuText.getLocalBounds().width / 2, (double)MainmenuText.getLocalBounds().height / 2);
    MainmenuText.setPosition(sf::Vector2f(530.f, 500.f));// absolute position

   clock.restart();

    opacity += 6.0f /* * deltatime */;

    this->_window.draw(MainmenuText);
}

//2nd MAINMENU - Display

void Game::displayPlayButton() {

    if (opacity >= 255)
    {
        opacity = 255;
    }
    sf::Font font;
    sf::Clock clock;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text Play;
    Play.setFont(font);
    Play.setString("PLAY");
    Play.setCharacterSize(50);
    Play.setFillColor(sf::Color(255, 255, 255, opacity));
    Play.setOrigin((double)Play.getLocalBounds().width / 2, (double)Play.getLocalBounds().height / 2);
    Play.setPosition(sf::Vector2f(250.f, 500.f));// absolute position

    clock.restart();

    opacity += 6.0f /* * deltatime */;
    //if(sf::Mouse::getPosition(_window).x)
           this->_window.draw(Play);
}

void Game::displaySettingsButton() {

    if (opacity >= 255)
    {
        opacity = 255;
    }
    sf::Font font;
    sf::Clock clock;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text Settings;
    Settings.setFont(font);
    Settings.setString("Settings");
    Settings.setCharacterSize(50);
    Settings.setFillColor(sf::Color(255, 255, 255, opacity));
    Settings.setOrigin((double)Settings.getLocalBounds().width / 2, (double)Settings.getLocalBounds().height / 2);
    Settings.setPosition(sf::Vector2f(500.f, 500.f));// absolute position

    clock.restart();

    opacity += 6.0f /* * deltatime */;

    this->_window.draw(Settings);
}

void Game::displayQuitButton() {

    if (opacity >= 255)
    {
        opacity = 255;
    }
    sf::Font font;
    sf::Clock clock;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text Quit;
    Quit.setFont(font);
    Quit.setString("Quit");
    Quit.setCharacterSize(50);
    Quit.setFillColor(sf::Color(255, 255, 255, opacity));
    Quit.setOrigin((double)Quit.getLocalBounds().width / 2, (double)Quit.getLocalBounds().height / 2);
    Quit.setPosition(sf::Vector2f(750.f, 500.f));// absolute position

    clock.restart();

    opacity += 6.0f /* * deltatime */;

   if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (sf::Mouse::getPosition(_window).x > 700.f && sf::Mouse::getPosition(_window).x < 800.f && sf::Mouse::getPosition(_window).y > 500.f && sf::Mouse::getPosition(_window).y < 550.f)
        {
            this->_window.close();
        }
    }

    this->_window.draw(Quit);
}

void Game::audioMainMenu() {
    sf::SoundBuffer whodapokemon;

    if (!whodapokemon.loadFromFile("Audio/whodapokemon.wav"))
    {
        std::cout << "Error" << std::endl;
    }
    sf::Sound whodispokemon;
    whodispokemon.setBuffer(whodapokemon);
    whodispokemon.setVolume(90);
    whodispokemon.play();

}