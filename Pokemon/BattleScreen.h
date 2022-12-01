#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Pokemon.h"
#include <unordered_map>

class BattleScreen {
public:
	BattleScreen();
	BattleScreen(sf::RenderWindow* window, int BattleGround);
	~BattleScreen();
	void ShowBattleScreen(bool click, const char* buttonName, sf::Event event);
	void StartBattle(sf::Event event);

	void BattleAnimation(sf::Event event);

	void StartNewBattle();

	void ChooseBattleAction(bool click, const char* buttonName);

	void ChooseAttack();

	void DommageStep();

	void FailedRunDommageStep();

	void ChoosePokemon();

	void BagStep();

	void RunStep();

	int BattlePhase;
	std::unordered_map<const char*, sf::RectangleShape> Button;
	std::unordered_map<const char*, sf::Text> TextButton;
	std::unordered_map<const char*, sf::CircleShape> CircleButton;
protected:

	int RunAttempt;
	sf::RectangleShape RectangleText;
	sf::Font font;
	sf::Sprite BackGround;
	sf::Texture BackgroundTexture;
	sf::RenderWindow* window;
	Pokemon* EnemyPokemon;
	Pokemon* AllyPokemon;
	int BattleGround;

};