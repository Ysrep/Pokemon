#include "Map.h"
#include<SFML/Graphics.hpp>

Map::Map(sf::RenderWindow* window) {
	this->window = window;
}
void Map::MappingTile() {

	sf::RectangleShape rectangle(sf::Vector2f(120, 50));

	rectangle.setFillColor(sf::Color(255, 255, 255));
	rectangle.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	this->window->draw(rectangle);
}
