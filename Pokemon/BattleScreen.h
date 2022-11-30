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

	void ChooseBattleAction(bool click, const char* buttonName, sf::Event event);

	void ChooseAttack(sf::Event event);

	void DommageStep(sf::Event event);

	void FailedRunDommageStep(sf::Event event);

	void ChoosePokemon();

	void BagStep(sf::Event event);

	void RunStep(sf::Event event);
	int BattlePhase;
	std::unordered_map<const char*, sf::RectangleShape> Button;
	std::unordered_map<const char*, sf::Text> Text;
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