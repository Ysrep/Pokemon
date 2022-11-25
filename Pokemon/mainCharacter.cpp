#include "mainCharacter.h"


void mainCharacter::InitChar() {
	sf::Texture mainCharText;
	mainCharText.loadFromFile("Textures/Entity/mainChar/mainCharWalk.png");
	sf::Sprite mainCharSprite(mainCharText);
}