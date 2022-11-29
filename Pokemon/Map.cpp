#include "Map.h"
#include<SFML/Graphics.hpp>

Map::Map(sf::RenderWindow* window){
	this->window = window;
}

void Map::MappingTile() {
	int count = 0;
	int anim_count = 0;

	sf::RectangleShape rectangle(sf::Vector2f(64, 64));

	rectangle.setFillColor(sf::Color(255, 255, 255));
	rectangle.setSize(sf::Vector2f(64, 64));
	rectangle.setPosition(0, 0);
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	this->window->draw(rectangle);

	for (int i = 0; i < 10; i++) {
		for (int i = 0; i < 10; i++) {
			this->window->draw(rectangle);
			rectangle.setPosition(rectangle.getPosition().x + 64 * 2, rectangle.getPosition().y);
		}
		rectangle.setPosition(64, rectangle.getPosition().y + 64);
		for (int i = 0; i < 10; i++) {
			this->window->draw(rectangle);
			rectangle.setPosition(rectangle.getPosition().x + 64 * 2, rectangle.getPosition().y);
		}
		rectangle.setPosition(0, rectangle.getPosition().y + 64);
	}
}

void Map::movingMap() {
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

	}
}
