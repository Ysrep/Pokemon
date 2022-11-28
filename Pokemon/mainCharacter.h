#pragma once
#include <vector>
#include <SFML/Graphics.hpp>


class mainCharacter {
public :
	void InitChar();
	mainCharacter(sf::RenderWindow* window);
	sf::RenderWindow* window;
	sf::Sprite mainCharSprite;

	int charDirection;
	int charPosX;
	int charPosY;
};
