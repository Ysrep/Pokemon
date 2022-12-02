#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "capacity.h"
#include "nature.h"
#include "type.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Pokemon {
private :
	

public :
	Pokemon();
	void initPokemon();

	sf::Sprite PokeSprite;
	string name = "Rattata";
	int lvl = 50;
	int hp = 105;
	int attack = 118;
	int defense = 56;
	int attack_spe = 40;
	int defense_spe = 55;
	int speed = 124;
	Type type;
	int ev[6];
	int iv[6];
	Nature nature;
	//Talent talent;
	vector<Capacity> capacity;
};