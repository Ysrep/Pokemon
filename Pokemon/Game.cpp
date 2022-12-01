#include "Game.h"
#include <iostream>
#include "SFML/Audio.hpp"

Game::Game() : _window(sf::VideoMode(1000, 650), "Pokemon Salty")
{
    this->movingWingull;
    this->movingWingull.setPosition(sf::Vector2f(650.f, 20.f)); // absolute position
    this->movingWingull2;
    this->movingWingull2.setPosition(sf::Vector2f(950.f, 420.f)); // absolute position

    this->_window.setVerticalSyncEnabled(true);
    this->_window.setFramerateLimit(60);
    this->_window.getSize();
    opacity = 0;
    this->GoeliseTravel = true;
}


sf::RenderWindow& Game::GetWindow() {
    return this->_window;
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

    case sf::Event::Resized:
    {
        std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "new width: " << event.size.width << std::endl;
        std::cout << "new height: " << event.size.height << std::endl;
        this->_window.setSize(sf::Vector2u(event.size.width, event.size.height));
    }

    default:
        break;
    }
}

void Game::update() {
}

void Game::clear(void)
{
    this->_window.clear();
}

void Game::display(void)
{
    this->_window.display();
}

//Display - Background

void Game::drawBackground()
{
    sf::Texture arena;
    //arena.setSmooth(true);
    sf::Sprite background;

    if (!arena.loadFromFile("Textures/Mainmenu/arena.jpg"))
    {

    }
    background.setTexture(arena);
    double ScaleX = (double)this->_window.getSize().x / background.getTextureRect().width;
    double ScaleY = (double)this->_window.getSize().y / background.getTextureRect().height;
    background.scale(sf::Vector2f(ScaleX, ScaleY));
    background.setOrigin(sf::Vector2f((double)background.getTextureRect().width / 2, (double)background.getTextureRect().height / 2));
    background.setPosition(sf::Vector2f((double)this->_window.getSize().x / 2, (double)this->_window.getSize().y / 2));
    this->_window.draw(background);
}

//Display Settings BG

void Game::drawBackgroundSettings()
{
    sf::Texture settings;
    settings.setSmooth(true);
    sf::Sprite backgroundsettings;

    backgroundsettings.setScale(sf::Vector2f(1.2f, 1.f));
    if (!settings.loadFromFile("Textures/Mainmenu/Settings.jpg"))
    {

    }

    backgroundsettings.setTexture(settings);

    this->_window.draw(backgroundsettings);
}

// Display - Title Image

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

// Display - Pokeball

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

// Display - Press Enter

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
    MainmenuText.setPosition(sf::Vector2f(530.f, 400.f));// absolute position

   clock.restart();

    opacity += 6.0f /* * deltatime */;

    this->_window.draw(MainmenuText);
}

// Display - Play Button

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
    Play.setFillColor(sf::Color(0, 0, 0, opacity));
    Play.setOrigin((double)Play.getLocalBounds().width / 2, (double)Play.getLocalBounds().height / 2);
    Play.setPosition(sf::Vector2f(250.f, 400.f));// absolute position

    clock.restart();

    opacity += 6.0f /* * deltatime */;


    if (sf::Mouse::getPosition(_window).x > 200.f && sf::Mouse::getPosition(_window).x < 300.f && sf::Mouse::getPosition(_window).y > 400.f && sf::Mouse::getPosition(_window).y < 450.f)
    {
        Play.setFillColor(sf::Color(255, 0, 0, 255));
    }

    this->_window.draw(Play);
}

 // Display - Settings Button

void Game::displaySettingsButton() {

    if (opacity >= 255)
    {
        opacity = 255;
    }
    sf::Font font;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text Settings;
    Settings.setFont(font);
    Settings.setString("Settings");
    Settings.setCharacterSize(50);
    Settings.setFillColor(sf::Color(0, 0, 0, opacity));
    Settings.setOrigin((double)Settings.getLocalBounds().width / 2, (double)Settings.getLocalBounds().height / 2);
    Settings.setPosition(sf::Vector2f(500.f, 400.f));// absolute position

    opacity += 6.0f /* * deltatime */;

   

    if (sf::Mouse::getPosition(_window).x > 400.f && sf::Mouse::getPosition(_window).x < 600.f && sf::Mouse::getPosition(_window).y > 400.f && sf::Mouse::getPosition(_window).y < 450.f)
    {
        Settings.setFillColor(sf::Color(0, 255, 0, 255));
    }

    this->_window.draw(Settings);
}

// Display - Quit Button

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
    Quit.setFillColor(sf::Color(0, 0, 0, opacity));
    Quit.setOrigin((double)Quit.getLocalBounds().width / 2, (double)Quit.getLocalBounds().height / 2);
    Quit.setPosition(sf::Vector2f(750.f, 400.f));// absolute position

    clock.restart();

    opacity += 6.0f /* * deltatime */;

   if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (sf::Mouse::getPosition(_window).x > 700.f && sf::Mouse::getPosition(_window).x < 800.f && sf::Mouse::getPosition(_window).y > 400.f && sf::Mouse::getPosition(_window).y < 450.f)
        {
            this->_window.close();
        }
    }

   if (sf::Mouse::getPosition(_window).x > 700.f && sf::Mouse::getPosition(_window).x < 800.f && sf::Mouse::getPosition(_window).y > 400.f && sf::Mouse::getPosition(_window).y < 450.f)
   {
       Quit.setFillColor(sf::Color(0, 0, 255, 255));
   }

    this->_window.draw(Quit);
}


void Game::goeliseTravel() {
    std::cout << this->GoeliseTravel << std::endl;

    sf::Texture wingull;
    wingull.setSmooth(true);
 
    this->movingWingull.setScale(sf::Vector2f(0.4f, 0.4f));

    if (!wingull.loadFromFile("Textures/Mainmenu/wingull.png"))
    {

    }
   
    this->movingWingull.setTexture(wingull);
    this->movingWingull.setRotation(10);
    this->movingWingull.setPosition(sf::Vector2f(this->movingWingull.getPosition().x - 1.f, this->movingWingull.getPosition().y)); // absolute position
    this->_window.draw(this->movingWingull);

    if (this->movingWingull.getPosition().x == -100)
    {
        this->GoeliseTravel = false;
    }
    if (this->GoeliseTravel == false)
    {
        this->movingWingull.setPosition(sf::Vector2f(1000.f, 150.f));
        this->GoeliseTravel = true;

    }
}

void Game::goeliseTravel2() {
    std::cout << this->GoeliseTravel << std::endl;

    sf::Texture wingull2;
    wingull2.setSmooth(true);

    this->movingWingull2.setScale(sf::Vector2f(0.6f, 0.6f));

    if (!wingull2.loadFromFile("Textures/Mainmenu/wingull.png"))
    {

    }

    this->movingWingull2.setTexture(wingull2);
    this->movingWingull2.setRotation(10);
    this->movingWingull2.setPosition(sf::Vector2f(this->movingWingull2.getPosition().x - 1.f, this->movingWingull2.getPosition().y)); // absolute position
    this->_window.draw(this->movingWingull2);

    if (this->movingWingull2.getPosition().x == -200)
    {
        this->GoeliseTravel = false;
    }
    if (this->GoeliseTravel == false)
    {
        this->movingWingull2.setPosition(sf::Vector2f(1000.f, 420.f));
        this->GoeliseTravel = true;
    }
}
