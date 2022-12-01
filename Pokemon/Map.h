#pragma once
#include <SFML/Graphics.hpp>

class Map
{
public:

	Map(sf::RenderWindow* window);
	sf::RenderWindow* window;
	void MappingTile();
	void movingMap();
	sf::Sprite map;
	int charPosX;
	int charPosY;
};

