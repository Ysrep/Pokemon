#pragma once
#include <SFML/Graphics.hpp>

class Map
{
	Map(sf::RenderWindow* window);
	sf::RenderWindow* window;
	void MappingTile();
};

