#include <iostream>
#include "pokemon.h"
#include "capacity.h"
#include "nature.h"
#include <string>

using namespace std;

Pokemon::Pokemon() {
	type = Type::Type("Normal");
	for (int i = 0; i < 6; i++) {
		iv[i] = 31;
	}
	this->ev[1] = 252;
	this->ev[5] = 252;
	this->ev[2] = 4;
	this->nature = Nature::Nature("Rigide", "+Att,-Att_spe");
	string Type1 = "Normal";
	string Type2 = "Tenebre";
	string Type3 = "Glace";
	string Type4 = "Electrique";
	string Name1 = "Croc de Mort";
	string Name2 = "Machouille";
	string Name3 = "Laser glace";
	string Name4 = "Fatal foudre";
	string effect1 = "Physique";
	string effect2 = "Special";
	this->capacity.push_back(Capacity::Capacity(Type::Type(Type1), 80, 90, Name1, effect1));
	this->capacity.push_back(Capacity::Capacity(Type::Type(Type2), 80, 100, Name2, effect1));
	this->capacity.push_back(Capacity::Capacity(Type::Type(Type3), 90, 100, Name3, effect2));
	this->capacity.push_back(Capacity::Capacity(Type::Type(Type4), 110, 70, Name4, effect2));
}

void Pokemon::initPokemon() {
	sf::Texture mainCharText;
	mainCharText.loadFromFile("Textures/Entity/pokemon/Rattata.png");
	this->PokeSprite.setTexture(mainCharText);


}
