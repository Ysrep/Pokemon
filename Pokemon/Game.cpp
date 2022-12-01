#include "Game.h"
#include <iostream>
#include "BattleScreen.h"
#include "SFML/Audio.hpp"


//std::vector<sf::IntRect> mainChar_anim_left = MAIN_CHAR_ANIM_RECT_LEFT;
//
//
//
//
//mainCharSprite.setTextureRect(mainChar_anim_left[count]);

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
    this->Battle;
    BattleScreen Battle(&this->_window, 0);
    this->Battle = Battle;
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


//_________________________________________________________________________________________________

//________________________________________1ST PAGE DISPLAY_________________________________________

//_________________________________________________________________________________________________

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
    MainmenuText.setString("PRESS ENTER TO PLAY");
    MainmenuText.setCharacterSize(50);
    MainmenuText.setFillColor(sf::Color(0,0,0,opacity));
    MainmenuText.setOrigin((double)MainmenuText.getLocalBounds().width / 2, (double)MainmenuText.getLocalBounds().height / 2);
    MainmenuText.setPosition(sf::Vector2f(530.f, 530.f));// absolute position

   clock.restart();

    opacity += 6.0f /* * deltatime */;

    this->_window.draw(MainmenuText);
}

//_________________________________________________________________________________________________

//________________________________________MAIN MENU DISPLAY________________________________________

//_________________________________________________________________________________________________


// Display - Play Button

void Game::displayPlayButton() {


    sf::Font font;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text Play;
    Play.setFont(font);
    Play.setString("PLAY");
    Play.setCharacterSize(50);
    Play.setFillColor(sf::Color(0, 0, 0, 255));
    Play.setOrigin((double)Play.getLocalBounds().width / 2, (double)Play.getLocalBounds().height / 2);
    Play.setPosition(sf::Vector2f(250.f, 400.f));// absolute position


    if (sf::Mouse::getPosition(_window).x > 200.f && sf::Mouse::getPosition(_window).x < 300.f && sf::Mouse::getPosition(_window).y > 400.f && sf::Mouse::getPosition(_window).y < 450.f)
    {
        Play.setFillColor(sf::Color(255, 0, 0, 255));
    }


    this->_window.draw(Play);
}

 // Display - Settings Button

void Game::displaySettingsButton() {

    sf::Font font;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text Settings;
    Settings.setFont(font);
    Settings.setString("Settings");
    Settings.setCharacterSize(50);
    Settings.setFillColor(sf::Color(0, 0, 0, 255));
    Settings.setOrigin((double)Settings.getLocalBounds().width / 2, (double)Settings.getLocalBounds().height / 2);
    Settings.setPosition(sf::Vector2f(500.f, 400.f));// absolute position

    if (sf::Mouse::getPosition(_window).x > 400.f && sf::Mouse::getPosition(_window).x < 600.f && sf::Mouse::getPosition(_window).y > 400.f && sf::Mouse::getPosition(_window).y < 450.f)
    {
        Settings.setFillColor(sf::Color(0, 255, 0, 255));
    }

    this->_window.draw(Settings);
}

// Display - Quit Button

void Game::displayQuitButton() {


    sf::Font font;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text Quit;
    Quit.setFont(font);
    Quit.setString("Quit");
    Quit.setCharacterSize(50);
    Quit.setFillColor(sf::Color(0, 0, 0, 255));
    Quit.setOrigin((double)Quit.getLocalBounds().width / 2, (double)Quit.getLocalBounds().height / 2);
    Quit.setPosition(sf::Vector2f(750.f, 400.f));// absolute position

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

// 3rd plan Wingull travel + motion

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

 // 1st plan Wingull Travel + motion

void Game::goeliseTravel2() {

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
//________________________________________________________________________________________________

//________________________________________SETTINGS DISPLAY________________________________________

//________________________________________________________________________________________________

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

// Display Settings Title

void Game::drawSettingsTitle() {

    if (opacity >= 255)
    {
        opacity = 255;
    }
    sf::Font font;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text settingsText;
    settingsText.setFont(font);
    settingsText.setString("Settings");
    settingsText.setCharacterSize(150);
    settingsText.setFillColor(sf::Color(0, 0, 0, 255));
    settingsText.setOrigin((double)settingsText.getLocalBounds().width / 2, (double)settingsText.getLocalBounds().height / 2);
    settingsText.setPosition(sf::Vector2f(500.f, 50.f));// absolute position

    opacity += 6.0f /* * deltatime */;

    this->_window.draw(settingsText);
}

//Back to main menu Text

void Game::backToMainMenuText() {

    sf::Font font;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    sf::Text MainmenuText;
    MainmenuText.setFont(font);
    MainmenuText.setString("Press escape to go back to main menu");
    MainmenuText.setCharacterSize(50);
    MainmenuText.setFillColor(sf::Color(0, 0, 0, 255));
    MainmenuText.setOrigin((double)MainmenuText.getLocalBounds().width / 2, (double)MainmenuText.getLocalBounds().height / 2);
    MainmenuText.setPosition(sf::Vector2f(500.f, 570.f));// absolute position

    this->_window.draw(MainmenuText);
}

// Display Audio Text

void Game::audioManageText() {

    sf::Font font;
    if (!font.loadFromFile("Fonts/Unown/Unown.ttf"))
    {
    }
    this->audioManage.setFont(font);
    this->audioManage.setString("Audio sounds");
    this->audioManage.setCharacterSize(50);
    this->audioManage.setFillColor(sf::Color(0, 0, 0, 255));
    this->audioManage.setOrigin((double)this->audioManage.getLocalBounds().width / 2, (double)this->audioManage.getLocalBounds().height / 2);
    this->audioManage.setPosition(sf::Vector2f(470.f, 250.f));// absolute position



    this->_window.draw(this->audioManage);
}

// Display Audio Checkbox



//________________________________________________________________________________________________

//________________________________________BATTLE DISPLAY________________________________________

//________________________________________________________________________________________________

// Battle Screen

void::Game::GameBattleScreen() {
    sf::Event event;
    while (this->Battle.BattlePhase > -1) {
        while (this->_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->_window.close();
                this->Battle.BattlePhase = -1;
            }
        }
        this->Battle.ShowBattleScreen(false, "Nothing", event);
        if (this->Battle.BattlePhase == 2 || this->Battle.BattlePhase == 3) {
            this->Battle.ShowBattleScreen(false, "noting", event);
            if ((this->_window.hasFocus() && sf::Mouse::getPosition(this->_window).x > 0 || sf::Mouse::getPosition(this->_window).x < 800) && (sf::Mouse::getPosition(this->_window).y > 0 || sf::Mouse::getPosition(this->_window).y < 800) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (sf::Mouse::getPosition(this->_window).x >= this->Battle.CircleButton["BottomLeft"].getPosition().x && sf::Mouse::getPosition(this->_window).x <= this->Battle.CircleButton["BottomLeft"].getPosition().x + (this->Battle.CircleButton["BottomLeft"].getRadius() / 2) + this->Battle.Button["BottomLeft"].getSize().x && sf::Mouse::getPosition(this->_window).y >= this->Battle.Button["BottomLeft"].getPosition().y && sf::Mouse::getPosition(this->_window).y <= this->Battle.Button["BottomLeft"].getPosition().y + this->Battle.Button["BottomLeft"].getSize().y) {
                    this->Battle.ShowBattleScreen(true, "BottomLeft", event);
                }
                else if (sf::Mouse::getPosition(this->_window).x >= this->Battle.Button["BottomRight"].getPosition().x && sf::Mouse::getPosition(this->_window).x <= this->Battle.CircleButton["BottomRight"].getPosition().x + (this->Battle.CircleButton["BottomRight"].getRadius() / 2) + this->Battle.Button["BottomRight"].getSize().x && sf::Mouse::getPosition(this->_window).y >= this->Battle.Button["BottomRight"].getPosition().y && sf::Mouse::getPosition(this->_window).y <= this->Battle.Button["BottomRight"].getPosition().y + this->Battle.Button["BottomRight"].getSize().y) {
                    this->Battle.ShowBattleScreen(true, "BottomRight", event);
                }
                else if (sf::Mouse::getPosition(this->_window).x >= this->Battle.CircleButton["TopLeft"].getPosition().x && sf::Mouse::getPosition(this->_window).x <= this->Battle.CircleButton["TopLeft"].getPosition().x + (this->Battle.CircleButton["TopLeft"].getRadius() / 2) + this->Battle.Button["TopLeft"].getSize().x && sf::Mouse::getPosition(this->_window).y >= this->Battle.Button["TopLeft"].getPosition().y && sf::Mouse::getPosition(this->_window).y <= this->Battle.Button["TopLeft"].getPosition().y + this->Battle.Button["TopLeft"].getSize().y) {
                    this->Battle.ShowBattleScreen(true, "TopLeft", event);
                }
                else if (sf::Mouse::getPosition(this->_window).x >= this->Battle.Button["TopRight"].getPosition().x && sf::Mouse::getPosition(this->_window).x <= this->Battle.CircleButton["TopRight"].getPosition().x + (this->Battle.CircleButton["TopRight"].getRadius() / 2) + this->Battle.Button["TopRight"].getSize().x && sf::Mouse::getPosition(this->_window).y >= this->Battle.Button["TopRight"].getPosition().y && sf::Mouse::getPosition(this->_window).y <= this->Battle.Button["TopRight"].getPosition().y + this->Battle.Button["TopRight"].getSize().y) {
                    this->Battle.ShowBattleScreen(true, "TopRight", event);
                }
                else {
                    this->Battle.ShowBattleScreen(false, "noting", event);
                }
            }
        }
    }
}

void Game::WildPokemon(Pokemon* wild, Pokemon* Trainer) {
    this->Battle.StartNewBattle(wild, Trainer);
}

BattleScreen Game::getBattle()
{
    return this->Battle;
}
