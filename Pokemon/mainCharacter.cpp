#include "mainCharacter.h"
#include <SFML/Graphics.hpp>
#define MAIN_CHAR_ANIM_RECT_LEFT                                                                                                        \
    {                                                                                                                                   \
        sf::IntRect(0, 64, 64, 64), sf::IntRect(64, 64, 64, 64), sf::IntRect(128, 64, 64, 64), sf::IntRect(192, 64, 64, 64)       \
    }
#define MAIN_CHAR_ANIM_RECT_DOWN                                                                                                       \
    {                                                                                                                                   \
        sf::IntRect(0, 0, 64, 64), sf::IntRect(64, 0, 64, 64), sf::IntRect(128, 0, 64, 64), sf::IntRect(192, 0, 64, 64)       \
    }
#define MAIN_CHAR_ANIM_RECT_RIGHT                                                                                                       \
    {                                                                                                                                   \
        sf::IntRect(0, 128, 64, 64), sf::IntRect(64, 128, 64, 64), sf::IntRect(128, 128, 64, 64), sf::IntRect(192, 128, 64, 64)       \
    }
#define MAIN_CHAR_ANIM_RECT_UP                                                                                                       \
    {                                                                                                                                   \
        sf::IntRect(0, 192, 64, 64), sf::IntRect(64, 192, 64, 64), sf::IntRect(128, 192, 64, 64), sf::IntRect(192, 192, 64, 64)       \
    }

mainCharacter::mainCharacter(sf::RenderWindow* window) {
	this->window = window;
    this->charDirection = 0;
    int charPosX = 0;
    int charPosY = 0;
    this->mainCharSprite;
    this->mainCharSprite.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
}

void mainCharacter::InitChar() {
	sf::Texture mainCharText;
	int count = 0;
	int anim_count = 0;
	std::vector<sf::IntRect> mainChar_anim_left = MAIN_CHAR_ANIM_RECT_LEFT;
    std::vector<sf::IntRect> mainChar_anim_down = MAIN_CHAR_ANIM_RECT_DOWN;
    std::vector<sf::IntRect> mainChar_anim_right = MAIN_CHAR_ANIM_RECT_RIGHT;
    std::vector<sf::IntRect> mainChar_anim_up = MAIN_CHAR_ANIM_RECT_UP;

	mainCharText.loadFromFile("Textures/Entity/mainChar/mainCharWalk.png");
	mainCharSprite.setTexture(mainCharText);
	mainCharSprite.scale(sf::Vector2f(1, 1));
	mainCharSprite.setTextureRect(mainChar_anim_left[count]);
    mainCharSprite.setOrigin((double)mainCharSprite.getTextureRect().width / 2, (double)mainCharSprite.getTextureRect().height / 2);

    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

        if (count % 1250 == 0) {

            anim_count++;
            charPosX - 4;
            mainCharSprite.setPosition(mainCharSprite.getPosition().x - 4, mainCharSprite.getPosition().y);
            while (charPosX % 64 != 0) {
                mainCharSprite.setPosition(mainCharSprite.getPosition().x - 4, mainCharSprite.getPosition().y);
            }

            if (anim_count >= mainChar_anim_left.size()) {
                break;

            }
            mainCharSprite.setTextureRect(mainChar_anim_left[anim_count]);
            count = 0;
        }

        charDirection = 1;
        count++;

        this->window->draw(mainCharSprite);
        this->window->display();
    }

    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

        if (count % 2500 == 0) {

            anim_count++;
            charPosY - 8;
            mainCharSprite.setPosition(mainCharSprite.getPosition().x, mainCharSprite.getPosition().y + 8);
            while (charPosY % 64 != 0) {
                mainCharSprite.setPosition(mainCharSprite.getPosition().x, mainCharSprite.getPosition().y + 8);
            }

            if (anim_count >= mainChar_anim_left.size()) {
                break;

            }
            mainCharSprite.setTextureRect(mainChar_anim_down[anim_count]);
            count = 0;
        }

        charDirection = 0;
        count++;

        this->window->draw(mainCharSprite);
        this->window->display();
    }

    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        if (count % 2500 == 0) {

            anim_count++;
            mainCharSprite.setPosition(mainCharSprite.getPosition().x + 8, mainCharSprite.getPosition().y);
            while (charPosX % 64 != 0) {
                mainCharSprite.setPosition(mainCharSprite.getPosition().x + 8, mainCharSprite.getPosition().y);
            }

            if (anim_count >= mainChar_anim_left.size()) {
                break;

            }
            mainCharSprite.setTextureRect(mainChar_anim_right[anim_count]);
            count = 0;
        }

        charDirection = 3;
        count++;

        this->window->draw(mainCharSprite);
        this->window->display();
    }

    while (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

        
        if (count % 2500 == 0) {
            anim_count++;
            mainCharSprite.setPosition(mainCharSprite.getPosition().x, mainCharSprite.getPosition().y - 8);
            while (charPosY % 64 != 0) {
                mainCharSprite.setPosition(mainCharSprite.getPosition().x, mainCharSprite.getPosition().y - 8);
            }

            if (anim_count >= mainChar_anim_left.size()) {
                break;

            }
            mainCharSprite.setTextureRect(mainChar_anim_up[anim_count]);
            count = 0;
        }

        charDirection = 2;
        count++;

        this->window->draw(mainCharSprite);
        this->window->display();
    }

    switch (charDirection)
    {
    case 0:
        mainCharSprite.setTextureRect(mainChar_anim_down[0]);
        break;

    case 1:
        mainCharSprite.setTextureRect(mainChar_anim_left[0]);
        break;

    case 2:
        mainCharSprite.setTextureRect(mainChar_anim_up[0]);
        break;

    case 3:
        mainCharSprite.setTextureRect(mainChar_anim_right[0]);
        break;

    }
	this->window->draw(mainCharSprite);
}
