#include "Map.h"
#include<SFML/Graphics.hpp>

Map::Map(sf::RenderWindow* window){
	this->window = window;
	this->map;
	this->map.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
	map.scale(sf::Vector2f(2.5, 2.5));
	charPosX = 0;
	charPosY = 0;
}

void Map::MappingTile() {
	sf::Texture MapTex;

	MapTex.loadFromFile("Textures/map/pokemonMap.png");
	map.setTexture(MapTex);

	map.setOrigin((double)map.getTextureRect().width / 2, (double)map.getTextureRect().height / 2);
	this->window->draw(map);
}

void Map::movingMap() {

	int count = 0;

	if (count % 1250 == 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			charPosX -= 1;
			map.setPosition(map.getPosition().x - 1, map.getPosition().y);
			while (charPosX % 64 != 0) {
				charPosX -= 1;
				map.setPosition(map.getPosition().x - 1, map.getPosition().y);
				this->window->clear();
				this->window->draw(map);
				window->display();
			}
		}
	}

	if (count % 1250 == 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			charPosY -= 1;
			map.setPosition(map.getPosition().x, map.getPosition().y - 1);
			while (charPosY % 64 != 0) {
				charPosY -= 1;
				map.setPosition(map.getPosition().x, map.getPosition().y - 1);
				this->window->clear();
				this->window->draw(map);
				window->display();
			}
		}
	}

	if (count % 1250 == 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			charPosX += 1;
			map.setPosition(map.getPosition().x + 1, map.getPosition().y);
			while (charPosX % 64 != 0) {
				charPosX += 1;
				map.setPosition(map.getPosition().x + 1, map.getPosition().y);
				this->window->clear();
				this->window->draw(map);
				window->display();
			}
		}
	}

	if (count % 1250 == 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			charPosY += 1;
			map.setPosition(map.getPosition().x + 1, map.getPosition().y + 1);
			while (charPosY % 64 != 0) {
				charPosY += 1;
				map.setPosition(map.getPosition().x + 4, map.getPosition().y);
				this->window->clear();
				this->window->draw(map);
				window->display();
			}
		}
	}
}
