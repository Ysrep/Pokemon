#include "BattleScreen.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cstring>
#define TRAINER_ANIM_RECT                                                                                                        \
    {                                                                                                                            \
        sf::IntRect(0, 0, 178, 200), sf::IntRect(178, 0, 180, 200), sf::IntRect(358, 0, 180, 200), sf::IntRect(528, 0, 180, 200), sf::IntRect(698,0,180,200) \
    }
#define POKEBALL_ANIM_RECT                                                                                                        \
    {                                                                                                                            \
        sf::IntRect(3, 3, 16, 16), sf::IntRect(19, 3, 16, 16), sf::IntRect(35, 3, 16, 16), sf::IntRect(51, 3, 16, 16), sf::IntRect(67,3,16,16), sf::IntRect(83, 3, 16, 16), sf::IntRect(99, 3, 16, 16), sf::IntRect(115, 3, 16, 16), sf::IntRect(131, 3, 16, 16) \
    }
BattleScreen::BattleScreen() {

	this->window = NULL;
	this->EnemyPokemon = NULL;
	this->AllyPokemon = NULL;
	this->BattleGround = NULL;
	this->BattlePhase = NULL;
	this->BackgroundTexture;
	this->BackGround;
	this->RunAttempt = NULL;
	this->AllyPokemonActualHealth = NULL;
	this->EnemyPokemonActualHealth = NULL;
	this->AllyPokemonName = "";
	this->EnemyPokemonName = "";
	this->AllyPokemonCapacity;
	this->EnemyPokemonCapacity;
	this->capacityUsed;
}


BattleScreen::BattleScreen(sf::RenderWindow* window, int BattleGround) {
	this->window = window;
	this->EnemyPokemon = NULL;
	this->AllyPokemon = NULL;
	this->BattleGround = BattleGround;
	this->BattlePhase = -1;
	this->BackgroundTexture;
	this->BackGround;
	this->font;
	this->RunAttempt = 1;
	this->AllyPokemonActualHealth = NULL;
	this->EnemyPokemonActualHealth = NULL;
	this->AllyPokemonName = "";
	this->EnemyPokemonName = "";
	this->AllyPokemonCapacity;
	this->EnemyPokemonCapacity;
	this->capacityUsed;

	sf::Texture pokemonTexture;
	this->PokemonTexture = pokemonTexture;
	this->PokemonTexture.loadFromFile("Textures/Entity/pokemon/Rattata.png");

	this->AllyPokemonSprite.setTexture(this->PokemonTexture);
	this->AllyPokemonSprite.setOrigin((double)AllyPokemonSprite.getTextureRect().width / 2, (double)AllyPokemonSprite.getTextureRect().height / 2);
	this->AllyPokemonSprite.setScale(1, 1);

	this->EnemyPokemonSprite.setTexture(this->PokemonTexture);
	this->EnemyPokemonSprite.setOrigin((double)EnemyPokemonSprite.getTextureRect().width / 2, (double)EnemyPokemonSprite.getTextureRect().height / 2);
	this->EnemyPokemonSprite.setPosition((this->window->getSize().x - EnemyPokemonSprite.getLocalBounds().width), 220);
	this->EnemyPokemonSprite.setScale(1, 1);

	sf::Font FontNumber;
	this->FontNumber = FontNumber;
	this->FontNumber.loadFromFile("Fonts/lemon_milk/LEMONMILK-Light.otf");


	this->font.loadFromFile("Fonts/Unown/Unown.ttf");

	this->RectangleText;
	RectangleText.setSize(sf::Vector2f(this->window->getSize().x - 20, 200));
	RectangleText.setPosition(10, this->window->getSize().y - 210);
	RectangleText.setOutlineThickness(10);
	RectangleText.setOutlineColor(sf::Color(250, 150, 100));

	sf::Text Attacktext;
	Attacktext.setFont(this->font);
	Attacktext.setString("Attack");
	Attacktext.setCharacterSize(30);
	Attacktext.setFillColor(sf::Color::Black);
	Attacktext.setOrigin((double)Attacktext.getLocalBounds().width / 2, (double)Attacktext.getLocalBounds().height / 2);

	sf::Text Bagtext;
	Bagtext.setFont(this->font);
	Bagtext.setString("Bag");
	Bagtext.setCharacterSize(30);
	Bagtext.setFillColor(sf::Color::Black);
	Bagtext.setOrigin((double)Bagtext.getLocalBounds().width / 2, (double)Bagtext.getLocalBounds().height / 2);

	sf::Text Runtext;
	Runtext.setFont(this->font);
	Runtext.setString("Run");
	Runtext.setCharacterSize(30);
	Runtext.setFillColor(sf::Color::Black);
	Runtext.setOrigin((double)Runtext.getLocalBounds().width / 2, (double)Runtext.getLocalBounds().height / 2);

	sf::Text Pokemontext;
	Pokemontext.setFont(this->font);
	Pokemontext.setString("Pokemon");
	Pokemontext.setCharacterSize(25);
	Pokemontext.setFillColor(sf::Color::Black);
	Pokemontext.setOrigin((double)Pokemontext.getLocalBounds().width / 2, (double)Pokemontext.getLocalBounds().height / 2);

	sf::RectangleShape attack;
	attack.setSize(sf::Vector2f(150, 75));
	attack.setPosition(this->window->getSize().x / 1.65, this->window->getSize().y / 1.40);
	attack.setFillColor(sf::Color::Red);
	attack.setOutlineThickness(2);
	attack.setOutlineColor(sf::Color::Black);

	Attacktext.setPosition(attack.getPosition().x + (attack.getSize().x / 2) - 10, attack.getPosition().y + (attack.getSize().y / 2) - 10);

	sf::CircleShape roundedAttack((double)attack.getSize().y / 2);
	roundedAttack.setOrigin((double)roundedAttack.getTextureRect().width / 2, (double)roundedAttack.getTextureRect().height / 2);
	roundedAttack.setPosition((attack.getPosition().x) - roundedAttack.getRadius(), (attack.getPosition().y));
	roundedAttack.setFillColor(sf::Color::Red);
	roundedAttack.setOutlineThickness(2);
	roundedAttack.setOutlineColor(sf::Color::Black);

	sf::RectangleShape bag;
	bag.setSize(sf::Vector2f(150, 75));
	bag.setPosition((attack.getPosition().x + attack.getSize().x + 10), attack.getPosition().y);
	bag.setFillColor(sf::Color::Yellow);
	bag.setOutlineThickness(2);
	bag.setOutlineColor(sf::Color::Black);

	Bagtext.setPosition(bag.getPosition().x + (bag.getSize().x / 2), bag.getPosition().y + (bag.getSize().y / 2) - 10);

	sf::CircleShape roundedBag((double)bag.getSize().y / 2);
	roundedBag.setOrigin((double)roundedBag.getTextureRect().width / 2, (double)roundedBag.getTextureRect().height / 2);
	roundedBag.setPosition((bag.getPosition().x) + bag.getSize().x - roundedBag.getRadius(), (bag.getPosition().y));
	roundedBag.setFillColor(sf::Color::Yellow);
	roundedBag.setOutlineThickness(2);
	roundedBag.setOutlineColor(sf::Color::Black);

	sf::RectangleShape run;
	run.setSize(sf::Vector2f(150, 75));
	run.setPosition((bag.getPosition().x), (bag.getPosition().y + bag.getSize().y + 10));
	run.setFillColor(sf::Color::Blue);
	run.setOutlineThickness(2);
	run.setOutlineColor(sf::Color::Black);

	Runtext.setPosition(run.getPosition().x + (run.getSize().x / 2), run.getPosition().y + (run.getSize().y / 2) - 10);

	sf::CircleShape roundedRun((double)run.getSize().y / 2);
	roundedRun.setOrigin((double)roundedRun.getTextureRect().width / 2, (double)roundedRun.getTextureRect().height / 2);
	roundedRun.setPosition((run.getPosition().x) + run.getSize().x - roundedRun.getRadius(), (run.getPosition().y));
	roundedRun.setFillColor(sf::Color::Blue);
	roundedRun.setOutlineThickness(2);
	roundedRun.setOutlineColor(sf::Color::Black);

	sf::RectangleShape pokemon;
	pokemon.setSize(sf::Vector2f(150, 75));
	pokemon.setPosition((attack.getPosition().x), (attack.getPosition().y + attack.getSize().y + 10));
	pokemon.setFillColor(sf::Color::Green);
	pokemon.setOutlineThickness(2);
	pokemon.setOutlineColor(sf::Color::Black);

	Pokemontext.setPosition(pokemon.getPosition().x + (pokemon.getSize().x / 2) - 10, pokemon.getPosition().y + (pokemon.getSize().y / 2) - 10);

	sf::CircleShape roundedPokemon((double)pokemon.getSize().y / 2);
	roundedPokemon.setOrigin((double)roundedPokemon.getTextureRect().width / 2, (double)roundedPokemon.getTextureRect().height / 2);
	roundedPokemon.setPosition((attack.getPosition().x) - roundedPokemon.getRadius(), (attack.getPosition().y + attack.getSize().y + 10));
	roundedPokemon.setFillColor(sf::Color::Green);
	roundedPokemon.setOutlineThickness(2);
	roundedPokemon.setOutlineColor(sf::Color::Black);

	sf::Text Attack1;
	Attack1.setFont(this->font);
	Attack1.setCharacterSize(25);
	Attack1.setFillColor(sf::Color::Black);
	Attack1.setOrigin((double)Attack1.getLocalBounds().width / 2, (double)Attack1.getLocalBounds().height / 2);

	sf::Text Attack2;
	Attack2.setFont(this->font);
	Attack2.setCharacterSize(25);
	Attack2.setFillColor(sf::Color::Black);
	Attack2.setOrigin((double)Attack2.getLocalBounds().width / 2, (double)Attack2.getLocalBounds().height / 2);

	sf::Text Attack3;
	Attack3.setFont(this->font);
	Attack3.setCharacterSize(25);
	Attack3.setFillColor(sf::Color::Black);
	Attack3.setOrigin((double)Attack3.getLocalBounds().width / 2, (double)Attack3.getLocalBounds().height / 2);

	sf::Text Attack4;
	Attack4.setFont(this->font);
	Attack4.setCharacterSize(25);
	Attack4.setFillColor(sf::Color::Black);
	Attack4.setOrigin((double)Attack4.getLocalBounds().width / 2, (double)Attack4.getLocalBounds().height / 2);

	this->Button["TopLeft"] = attack;
	this->Button["BottomLeft"] = pokemon;
	this->Button["BottomRight"] = run;
	this->Button["TopRight"] = bag;

	this->CircleButton["TopLeft"] = roundedAttack;
	this->CircleButton["BottomLeft"] = roundedPokemon;
	this->CircleButton["BottomRight"] = roundedRun;
	this->CircleButton["TopRight"] = roundedBag;

	this->TextButton["ChooseActionTopLeft"] = Attacktext;
	this->TextButton["ChooseActionBottomLeft"] = Pokemontext;
	this->TextButton["ChooseActionBottomRight"] = Runtext;
	this->TextButton["ChooseActionTopRight"] = Bagtext;

	this->TextButton["TopLeft"] = Attack1;
	this->TextButton["BottomLeft"] = Attack2;
	this->TextButton["BottomRight"] = Attack3;
	this->TextButton["TopRight"] = Attack4;

};

BattleScreen::~BattleScreen() {
	this->window = NULL;
	this->EnemyPokemon = NULL;
	this->AllyPokemon = NULL;
	this->BattleGround = NULL;
	this->BattlePhase = NULL;
	this->BackgroundTexture;
	this->BackGround;
	this->font;
	this->RunAttempt = NULL;
	this->RectangleText;
	this->Button;
	this->CircleButton;
	this->TextButton;
}





void BattleScreen::StartNewBattle(Pokemon* wild, Pokemon* Trainer) {
	this->BattlePhase = 1;
	this->RunAttempt = 1;
	this->AllyPokemon = Trainer;
	this->EnemyPokemon = wild;
	this->AllyPokemonActualHealth = this->AllyPokemon->hp;
	this->EnemyPokemonActualHealth = this->EnemyPokemon->hp;
	this->AllyPokemonName = this->AllyPokemon->name;
	this->EnemyPokemonName = this->EnemyPokemon->name;
	this->AllyPokemonCapacity = this->AllyPokemon->capacity;
	this->EnemyPokemonCapacity = this->EnemyPokemon->capacity;
}

// Start Battle

void BattleScreen::BattleAnimation(sf::Event event) {

}

void BattleScreen::StartBattle(sf::Event event) {
	sf::Sprite background;
	sf::Texture backgroundTexture;
	sf::Texture trainer;
	sf::Sprite TrainerSprite;
	sf::Texture Pokeball;
	sf::Sprite PokeballSprite;

	this->BackgroundTexture = backgroundTexture;
	this->BackGround = background;

	std::vector<sf::IntRect> trainer_anim = TRAINER_ANIM_RECT;
	std::vector<sf::IntRect> pokeball_anim = POKEBALL_ANIM_RECT;

	this->BackgroundTexture.loadFromFile("Textures/Battle/grass2_map.png");
	trainer.loadFromFile("Textures/Battle/startBattle.png");
	Pokeball.loadFromFile("Textures/Battle/Pokeball.png");

	trainer.setSmooth(true);
	this->BackgroundTexture.setSmooth(true);

	this->BackGround.setTexture(this->BackgroundTexture);
	this->BackGround.scale(sf::Vector2f(1, 1));
	double scaleX = (double)this->window->getSize().x / this->BackGround.getTextureRect().width;
	double scaleY = (double)this->window->getSize().y / this->BackGround.getTextureRect().height;
	this->BackGround.scale(sf::Vector2f(scaleX, scaleY));

	this->BackGround.setOrigin((double)this->BackGround.getTextureRect().width / 2, (double)this->BackGround.getTextureRect().height / 2);
	this->BackGround.setPosition(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));
	int count = 0;
	int count_Pokeball = 0;
	int anim_count = 0;
	int Pokeball_anim_count = -1;

	TrainerSprite.setTexture(trainer);
	TrainerSprite.setTextureRect(trainer_anim[anim_count]);
	TrainerSprite.setScale(this->window->getSize().x / 500, this->window->getSize().y / 500);
	TrainerSprite.setOrigin((double)TrainerSprite.getTextureRect().width / 2, (double)TrainerSprite.getTextureRect().height / 2);
	TrainerSprite.setPosition(sf::Vector2f(this->window->getSize().x / 6, this->RectangleText.getPosition().y - 100));

	sf::RectangleShape EnnemyPokemonInfo;
	EnnemyPokemonInfo.setSize(sf::Vector2f(175, 50));
	EnnemyPokemonInfo.setPosition(0, EnnemyPokemonInfo.getLocalBounds().height);
	EnnemyPokemonInfo.setOutlineThickness(2);
	EnnemyPokemonInfo.setOutlineColor(sf::Color::Black);

	sf::Text EnnemyLevel;
	EnnemyLevel.setFont(FontNumber);
	EnnemyLevel.setString("N." + to_string(this->EnemyPokemon->lvl));
	EnnemyLevel.setCharacterSize(15);
	EnnemyLevel.setFillColor(sf::Color::Black);
	EnnemyLevel.setPosition((EnnemyPokemonInfo.getPosition().x + 120), (EnnemyPokemonInfo.getPosition().y + 7));

	sf::Text EnnemyPokemonName;
	EnnemyPokemonName.setFont(this->font);
	EnnemyPokemonName.setString(this->EnemyPokemonName);
	EnnemyPokemonName.setCharacterSize(20);
	EnnemyPokemonName.setFillColor(sf::Color::Black);
	EnnemyPokemonName.setPosition((EnnemyPokemonInfo.getPosition().x + 5), (EnnemyPokemonInfo.getPosition().y));

	sf::Text EnnemyHealth;
	EnnemyHealth.setFont(FontNumber);
	EnnemyHealth.setString(to_string(this->EnemyPokemonActualHealth) + "/" + to_string(this->EnemyPokemon->hp));
	EnnemyHealth.setCharacterSize(15);
	EnnemyHealth.setFillColor(sf::Color::Black);
	EnnemyHealth.setPosition((EnnemyPokemonInfo.getPosition().x + 5), (EnnemyPokemonInfo.getPosition().y + 30));

	sf::Text Text;
	Text.setFont(this->font);
	Text.setString("A wild " + this->EnemyPokemonName + " appeared");
	Text.setCharacterSize(50);
	Text.setFillColor(sf::Color::Black);
	Text.setOrigin((double)Text.getLocalBounds().width / 2, (double)Text.getLocalBounds().height / 2);
	Text.setPosition(this->RectangleText.getPosition().x + Text.getLocalBounds().width, this->RectangleText.getPosition().y + Text.getLocalBounds().height);
	
	this->AllyPokemonSprite.setTexture(this->PokemonTexture);
	this->EnemyPokemonSprite.setTexture(this->PokemonTexture);

	this->AllyPokemonSprite.setScale(0.5, 0.5);
	this->EnemyPokemonSprite.setScale(0.5, 0.5);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		Text.setString("Go " + this->AllyPokemonName);
		this->window->draw(Text);
		while (this->BattlePhase == 1) {
			while (this->window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					this->window->close();
					this->BattlePhase = -1;
				}
			}

			this->window->clear();
			this->window->draw(this->BackGround);

			if (count % 13 == 0) {

				anim_count++;

				if (anim_count >= 3) {
					if (Pokeball_anim_count == 0) {
						PokeballSprite.setTexture(Pokeball);
						PokeballSprite.setScale(this->window->getSize().x / 500, this->window->getSize().y / 500);
						PokeballSprite.setTextureRect(pokeball_anim[anim_count]);
						PokeballSprite.setPosition(sf::Vector2f(TrainerSprite.getPosition().x + 150, TrainerSprite.getPosition().y - 20));
					}

					if (anim_count >= trainer_anim.size()) {
						anim_count = trainer_anim.size() - 1;
					}

					if (count_Pokeball % 6 == 0) {
						Pokeball_anim_count++;
						if (Pokeball_anim_count >= pokeball_anim.size()) {
							this->AllyPokemonSprite.setPosition(PokeballSprite.getPosition().x, PokeballSprite.getPosition().y);
							this->BattlePhase = 2;
							break;
						}
						PokeballSprite.setTextureRect(pokeball_anim[Pokeball_anim_count]);
						count_Pokeball = 0;


					}

				}
				TrainerSprite.setTextureRect(trainer_anim[anim_count]);

				count = 0;
			}
			if (count % 2 == 0) {
				if (anim_count != 0) {
					TrainerSprite.setPosition(TrainerSprite.getPosition().x - 10, TrainerSprite.getPosition().y);
				}
				if (Pokeball_anim_count != 0) {
					if (Pokeball_anim_count <= 3) {
						PokeballSprite.setPosition(PokeballSprite.getPosition().x + 5, PokeballSprite.getPosition().y - 7);
					}
					else if (Pokeball_anim_count > 3 && Pokeball_anim_count < pokeball_anim.size() - 1) {
						PokeballSprite.setPosition(PokeballSprite.getPosition().x + 5, PokeballSprite.getPosition().y + 7);
					}
				}

			}


			count++;
			this->window->draw(PokeballSprite);
			this->window->draw(TrainerSprite);
			this->window->draw(this->RectangleText);
			this->window->draw(Text);
			this->window->draw(EnnemyPokemonInfo);
			this->window->draw(EnnemyLevel);
			this->window->draw(EnnemyPokemonName);
			this->window->draw(EnnemyHealth);
			this->window->draw(this->EnemyPokemonSprite);
			this->window->display();
		}
	}
	else {
		this->window->draw(this->BackGround);
		this->window->draw(TrainerSprite);
		this->window->draw(this->RectangleText);
		this->window->draw(Text);
		this->window->draw(EnnemyPokemonInfo);
		this->window->draw(EnnemyLevel);
		this->window->draw(EnnemyPokemonName);
		this->window->draw(EnnemyHealth);
		this->window->draw(this->EnemyPokemonSprite);
		this->window->display();
	}

};

void BattleScreen::ChooseBattleAction(bool click, const char* buttonName) {

	this->window->clear();
	this->window->draw(this->BackGround);
	this->window->draw(this->RectangleText);

	sf::RectangleShape AllyPokemonInfo;
	AllyPokemonInfo.setSize(sf::Vector2f(175, 50));
	AllyPokemonInfo.setPosition((this->window->getSize().x - AllyPokemonInfo.getLocalBounds().width - 2), (this->window->getSize().y - this->RectangleText.getLocalBounds().height - AllyPokemonInfo.getLocalBounds().height - 30));
	AllyPokemonInfo.setOutlineThickness(2);
	AllyPokemonInfo.setOutlineColor(sf::Color::Black);

	sf::Text Level;
	Level.setFont(FontNumber);
	Level.setString("N." + to_string(this->AllyPokemon->lvl));
	Level.setCharacterSize(15);
	Level.setFillColor(sf::Color::Black);
	Level.setPosition((AllyPokemonInfo.getPosition().x + 120), (AllyPokemonInfo.getPosition().y + 7));

	sf::Text PokemonName;
	PokemonName.setFont(this->font);
	PokemonName.setString(this->AllyPokemonName);
	PokemonName.setCharacterSize(25);
	PokemonName.setFillColor(sf::Color::Black);
	PokemonName.setPosition((AllyPokemonInfo.getPosition().x + 5), (AllyPokemonInfo.getPosition().y));

	sf::Text Health;
	Health.setFont(FontNumber);
	Health.setString(to_string(this->AllyPokemonActualHealth) + "/" + to_string(this->AllyPokemon->hp));
	Health.setCharacterSize(15);
	Health.setFillColor(sf::Color::Black);
	Health.setPosition((AllyPokemonInfo.getPosition().x + 5), (AllyPokemonInfo.getPosition().y + 30));

	this->window->draw(AllyPokemonInfo);
	this->window->draw(Level);
	this->window->draw(PokemonName);
	this->window->draw(Health);

	sf::RectangleShape EnnemyPokemonInfo;
	EnnemyPokemonInfo.setSize(sf::Vector2f(175, 50));
	EnnemyPokemonInfo.setPosition(0, EnnemyPokemonInfo.getLocalBounds().height);
	EnnemyPokemonInfo.setOutlineThickness(2);
	EnnemyPokemonInfo.setOutlineColor(sf::Color::Black);

	sf::Text EnnemyLevel;
	EnnemyLevel.setFont(FontNumber);
	EnnemyLevel.setString("N." + to_string(this->EnemyPokemon->lvl));
	EnnemyLevel.setCharacterSize(15);
	EnnemyLevel.setFillColor(sf::Color::Black);
	EnnemyLevel.setPosition((EnnemyPokemonInfo.getPosition().x + 120), (EnnemyPokemonInfo.getPosition().y + 7));

	sf::Text EnnemyPokemonName;
	EnnemyPokemonName.setFont(this->font);
	EnnemyPokemonName.setString(this->EnemyPokemonName);
	EnnemyPokemonName.setCharacterSize(20);
	EnnemyPokemonName.setFillColor(sf::Color::Black);
	EnnemyPokemonName.setPosition((EnnemyPokemonInfo.getPosition().x + 5), (EnnemyPokemonInfo.getPosition().y));

	sf::Text EnnemyHealth;
	EnnemyHealth.setFont(FontNumber);
	EnnemyHealth.setString(to_string(this->EnemyPokemonActualHealth) + "/" + to_string(this->EnemyPokemon->hp));
	EnnemyHealth.setCharacterSize(15);
	EnnemyHealth.setFillColor(sf::Color::Black);
	EnnemyHealth.setPosition((EnnemyPokemonInfo.getPosition().x + 5), (EnnemyPokemonInfo.getPosition().y + 30));

	this->window->draw(EnnemyPokemonInfo);
	this->window->draw(EnnemyLevel);
	this->window->draw(EnnemyPokemonName);
	this->window->draw(EnnemyHealth);
	this->window->draw(this->EnemyPokemonSprite);
	this->window->draw(this->AllyPokemonSprite);

	for (auto const& i : this->CircleButton) {
		this->window->draw(i.second);
	}
	for (auto const& i : this->Button) {
		this->window->draw(i.second);
		if (i.first == "TopLeft" || i.first == "BottomLeft") {
			sf::RectangleShape line(sf::Vector2f(i.second.getSize().y, 2));
			line.rotate(90);
			line.setFillColor(i.second.getFillColor());
			line.setPosition(sf::Vector2f(i.second.getPosition().x, i.second.getPosition().y));
			this->window->draw(line);
		}
		else {
			sf::RectangleShape line(sf::Vector2f(i.second.getSize().y, 2));
			line.rotate(90);
			line.setFillColor(i.second.getFillColor());
			line.setPosition(sf::Vector2f(i.second.getPosition().x + i.second.getSize().x + 2, i.second.getPosition().y));
			this->window->draw(line);
		}

	}
	for (auto const& i : this->TextButton) {
		if (i.first == "ChooseActionTopLeft" || i.first == "ChooseActionBottomLeft" || i.first == "ChooseActionBottomRight" || i.first == "ChooseActionTopRight")
		{
			this->TextButton[i.first].setFont(this->font);
			this->window->draw(i.second);
		}
	}
	this->window->display();
	if (click == true && buttonName == "TopLeft") {
		this->BattlePhase = 3;

	}
	else if (click == true && buttonName == "BottomRight") {
		this->BattlePhase = 6;

	}
	else if (click == true && buttonName == "TopRight") {
		this->BattlePhase = 5;

	}
	else if (click == true && buttonName == "BottomLeft") {
		this->BattlePhase = 7;

	}
}

// Choose Attack and Dommage function

void BattleScreen::ChooseAttack(bool click, const char* buttonName) {

	this->window->clear();
	this->window->draw(this->BackGround);
	this->window->draw(this->RectangleText);

	sf::RectangleShape AllyPokemonInfo;
	AllyPokemonInfo.setSize(sf::Vector2f(175, 50));
	AllyPokemonInfo.setPosition((this->window->getSize().x - AllyPokemonInfo.getLocalBounds().width - 2), (this->window->getSize().y - this->RectangleText.getLocalBounds().height - AllyPokemonInfo.getLocalBounds().height - 30));
	AllyPokemonInfo.setOutlineThickness(2);
	AllyPokemonInfo.setOutlineColor(sf::Color::Black);

	sf::Text Level;
	Level.setFont(FontNumber);
	Level.setString("N." + to_string(this->AllyPokemon->lvl));
	Level.setCharacterSize(15);
	Level.setFillColor(sf::Color::Black);
	Level.setPosition((AllyPokemonInfo.getPosition().x + 120), (AllyPokemonInfo.getPosition().y + 7));

	sf::Text PokemonName;
	PokemonName.setFont(this->font);
	PokemonName.setString(this->AllyPokemonName);
	PokemonName.setCharacterSize(25);
	PokemonName.setFillColor(sf::Color::Black);
	PokemonName.setPosition((AllyPokemonInfo.getPosition().x + 5), (AllyPokemonInfo.getPosition().y));

	sf::Text Health;
	Health.setFont(FontNumber);
	Health.setString(to_string(this->AllyPokemonActualHealth) + "/" + to_string(this->AllyPokemon->hp));
	Health.setCharacterSize(15);
	Health.setFillColor(sf::Color::Black);
	Health.setPosition((AllyPokemonInfo.getPosition().x + 5), (AllyPokemonInfo.getPosition().y + 30));

	this->window->draw(AllyPokemonInfo);
	this->window->draw(Level);
	this->window->draw(PokemonName);
	this->window->draw(Health);

	sf::RectangleShape EnnemyPokemonInfo;
	EnnemyPokemonInfo.setSize(sf::Vector2f(175, 50));
	EnnemyPokemonInfo.setPosition(0, EnnemyPokemonInfo.getLocalBounds().height);
	EnnemyPokemonInfo.setOutlineThickness(2);
	EnnemyPokemonInfo.setOutlineColor(sf::Color::Black);

	sf::Text EnnemyLevel;
	EnnemyLevel.setFont(FontNumber);
	EnnemyLevel.setString("N." + to_string(this->EnemyPokemon->lvl));
	EnnemyLevel.setCharacterSize(15);
	EnnemyLevel.setFillColor(sf::Color::Black);
	EnnemyLevel.setPosition((EnnemyPokemonInfo.getPosition().x + 120), (EnnemyPokemonInfo.getPosition().y + 7));

	sf::Text EnnemyPokemonName;
	EnnemyPokemonName.setFont(this->font);
	EnnemyPokemonName.setString(this->EnemyPokemonName);
	EnnemyPokemonName.setCharacterSize(20);
	EnnemyPokemonName.setFillColor(sf::Color::Black);
	EnnemyPokemonName.setPosition((EnnemyPokemonInfo.getPosition().x + 5), (EnnemyPokemonInfo.getPosition().y));

	sf::Text EnnemyHealth;
	EnnemyHealth.setFont(FontNumber);
	EnnemyHealth.setString(to_string(this->EnemyPokemonActualHealth) + "/" + to_string(this->EnemyPokemon->hp));
	EnnemyHealth.setCharacterSize(15);
	EnnemyHealth.setFillColor(sf::Color::Black);
	EnnemyHealth.setPosition((EnnemyPokemonInfo.getPosition().x + 5), (EnnemyPokemonInfo.getPosition().y + 30));

	this->window->draw(EnnemyPokemonInfo);
	this->window->draw(EnnemyLevel);
	this->window->draw(EnnemyPokemonName);
	this->window->draw(EnnemyHealth);
	this->window->draw(this->EnemyPokemonSprite);
	this->window->draw(this->AllyPokemonSprite);
	int iteration = 0;
	for (auto const& i : this->CircleButton) {
		this->window->draw(i.second);
	}
	for (auto const& i : this->Button) {
		this->window->draw(i.second);
		if (i.first == "TopLeft" || i.first == "BottomLeft") {
			sf::RectangleShape line(sf::Vector2f(i.second.getSize().y, 2));
			this->Button[i.first].setFillColor(sf::Color::White);
			this->CircleButton[i.first].setFillColor(sf::Color::White);
			line.rotate(90);
			line.setFillColor(i.second.getFillColor());
			line.setPosition(sf::Vector2f(i.second.getPosition().x, i.second.getPosition().y));
			this->window->draw(line);
		}
		else {
			sf::RectangleShape line(sf::Vector2f(i.second.getSize().y, 2));
			this->Button[i.first].setFillColor(sf::Color::White);
			this->CircleButton[i.first].setFillColor(sf::Color::White);
			line.rotate(90);
			line.setFillColor(i.second.getFillColor());
			line.setPosition(sf::Vector2f(i.second.getPosition().x + i.second.getSize().x + 2, i.second.getPosition().y));
			this->window->draw(line);
		}
	}
	for (auto const& i : this->TextButton) {
		if (i.first == "TopLeft" || i.first == "BottomLeft" || i.first == "BottomRight" || i.first == "TopRight")
		{
			this->TextButton[i.first].setFont(this->font);
			this->TextButton[i.first].setString(this->AllyPokemonCapacity[iteration].name);
			iteration++;
			if (i.first == "TopLeft") {
				this->TextButton[i.first].setPosition(this->Button[i.first].getPosition().x + (this->Button[i.first].getSize().x / 2) - 100, this->Button[i.first].getPosition().y + (this->Button[i.first].getSize().y / 2) - 20);
			}
			else if (i.first == "BottomLeft") {
				this->TextButton[i.first].setPosition(this->Button[i.first].getPosition().x + (this->Button[i.first].getSize().x / 2) - 85, this->Button[i.first].getPosition().y + (this->Button[i.first].getSize().y / 2) - 20);
			}
			else {
				this->TextButton[i.first].setPosition(this->Button[i.first].getPosition().x + (this->Button[i.first].getSize().x / 2) - 60, this->Button[i.first].getPosition().y + (this->Button[i.first].getSize().y / 2) - 20);
			}

			this->window->draw(i.second);
		}

	}
	this->window->display();

	if (click == true && buttonName == "TopLeft") {
		this->BattlePhase = 4;
		this->capacityUsed = this->AllyPokemonCapacity[1];
	}
	else if (click == true && buttonName == "BottomRight") {
		this->BattlePhase = 4;
		this->capacityUsed = this->AllyPokemonCapacity[3];
	}
	else if (click == true && buttonName == "TopRight") {
		this->BattlePhase = 4;
		this->capacityUsed = this->AllyPokemonCapacity[2];
	}
	else if (click == true && buttonName == "BottomLeft") {
		this->BattlePhase = 4;
		this->capacityUsed = this->AllyPokemonCapacity[4];
	}
}

void BattleScreen::DommageStep() {
	this->window->clear();
	this->window->draw(this->BackGround);
	this->window->draw(this->RectangleText);

	sf::RectangleShape AllyPokemonInfo;
	AllyPokemonInfo.setSize(sf::Vector2f(175, 50));
	AllyPokemonInfo.setPosition((this->window->getSize().x - AllyPokemonInfo.getLocalBounds().width - 2), (this->window->getSize().y - this->RectangleText.getLocalBounds().height - AllyPokemonInfo.getLocalBounds().height - 30));
	AllyPokemonInfo.setOutlineThickness(2);
	AllyPokemonInfo.setOutlineColor(sf::Color::Black);

	sf::Text Level;
	Level.setFont(FontNumber);
	Level.setString("N." + to_string(this->AllyPokemon->lvl));
	Level.setCharacterSize(15);
	Level.setFillColor(sf::Color::Black);
	Level.setPosition((AllyPokemonInfo.getPosition().x + 120), (AllyPokemonInfo.getPosition().y + 7));

	sf::Text PokemonName;
	PokemonName.setFont(this->font);
	PokemonName.setString(this->AllyPokemonName);
	PokemonName.setCharacterSize(25);
	PokemonName.setFillColor(sf::Color::Black);
	PokemonName.setPosition((AllyPokemonInfo.getPosition().x + 5), (AllyPokemonInfo.getPosition().y));

	sf::Text Health;
	Health.setFont(FontNumber);
	Health.setString(to_string(this->AllyPokemonActualHealth) + "/" + to_string(this->AllyPokemon->hp));
	Health.setCharacterSize(15);
	Health.setFillColor(sf::Color::Black);
	Health.setPosition((AllyPokemonInfo.getPosition().x + 5), (AllyPokemonInfo.getPosition().y + 30));

	this->window->draw(AllyPokemonInfo);
	this->window->draw(Level);
	this->window->draw(PokemonName);
	this->window->draw(Health);

	sf::RectangleShape EnnemyPokemonInfo;
	EnnemyPokemonInfo.setSize(sf::Vector2f(175, 50));
	EnnemyPokemonInfo.setPosition(0, EnnemyPokemonInfo.getLocalBounds().height);
	EnnemyPokemonInfo.setOutlineThickness(2);
	EnnemyPokemonInfo.setOutlineColor(sf::Color::Black);

	sf::Text EnnemyLevel;
	EnnemyLevel.setFont(FontNumber);
	EnnemyLevel.setString("N." + to_string(this->EnemyPokemon->lvl));
	EnnemyLevel.setCharacterSize(15);
	EnnemyLevel.setFillColor(sf::Color::Black);
	EnnemyLevel.setPosition((EnnemyPokemonInfo.getPosition().x + 120), (EnnemyPokemonInfo.getPosition().y + 7));

	sf::Text EnnemyPokemonName;
	EnnemyPokemonName.setFont(this->font);
	EnnemyPokemonName.setString(this->EnemyPokemonName);
	EnnemyPokemonName.setCharacterSize(20);
	EnnemyPokemonName.setFillColor(sf::Color::Black);
	EnnemyPokemonName.setPosition((EnnemyPokemonInfo.getPosition().x + 5), (EnnemyPokemonInfo.getPosition().y));

	sf::Text EnnemyHealth;
	EnnemyHealth.setFont(FontNumber);
	EnnemyHealth.setString(to_string(this->EnemyPokemonActualHealth) + "/" + to_string(this->EnemyPokemon->hp));
	EnnemyHealth.setCharacterSize(15);
	EnnemyHealth.setFillColor(sf::Color::Black);
	EnnemyHealth.setPosition((EnnemyPokemonInfo.getPosition().x + 5), (EnnemyPokemonInfo.getPosition().y + 30));

	this->window->draw(EnnemyPokemonInfo);
	this->window->draw(EnnemyLevel);
	this->window->draw(EnnemyPokemonName);
	this->window->draw(EnnemyHealth);
	this->window->draw(this->EnemyPokemonSprite);
	this->window->draw(this->AllyPokemonSprite);
	int EnemyDommageTaken = 0;
	int AllyDommageTaken = 0;
	srand(time(0));
	int random = (rand() % 2);
	if (this->AllyPokemonActualHealth <= 0) {
		sf::Text text;
		text.setFont(this->font);
		text.setString("Your " + this->AllyPokemonName + " is fainted");
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Black);
		text.setOrigin((double)text.getLocalBounds().width / 2, (double)text.getLocalBounds().height / 2);
		text.setPosition(this->RectangleText.getPosition().x + text.getLocalBounds().width, this->RectangleText.getPosition().y + text.getLocalBounds().height);
		this->window->draw(text);
		this->window->draw(this->EnemyPokemonSprite);
		this->window->draw(this->AllyPokemonSprite);
		this->window->display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			this->BattlePhase = -1;
		}
	}
	else if (this->EnemyPokemonActualHealth <= 0) {
		sf::Text text;
		text.setFont(this->font);
		text.setString("The wild " + this->AllyPokemonName + " is fainted");
		text.setCharacterSize(50);
		text.setFillColor(sf::Color::Black);
		text.setOrigin((double)text.getLocalBounds().width / 2, (double)text.getLocalBounds().height / 2);
		text.setPosition(this->RectangleText.getPosition().x + text.getLocalBounds().width, this->RectangleText.getPosition().y + text.getLocalBounds().height);
		this->window->draw(text);
		this->window->draw(this->EnemyPokemonSprite);
		this->window->draw(this->AllyPokemonSprite);
		this->window->display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			this->BattlePhase = -1;
		}
	}
	else {
		if (random == 0) {
			if (this->capacityUsed.effect == "Physique") {
				EnemyDommageTaken = ((((this->AllyPokemon->lvl * 0.4 + 2) * this->AllyPokemon->attack * this->capacityUsed.power) / (this->EnemyPokemon->defense * 50)) + 2);
			}
			else if (this->capacityUsed.effect == "Special") {
				EnemyDommageTaken = ((((this->AllyPokemon->lvl * 0.4 + 2) * this->AllyPokemon->attack_spe * this->capacityUsed.power) / (this->EnemyPokemon->defense_spe * 50)) + 2);
			}
			this->EnemyPokemonActualHealth = this->EnemyPokemonActualHealth - EnemyDommageTaken;
			if (this->EnemyPokemonActualHealth <= 0) {
				this->EnemyPokemonActualHealth = 0;
			}
			else {
				EnnemyHealth.setString(to_string(this->EnemyPokemonActualHealth) + "/" + to_string(this->EnemyPokemon->hp));
				srand(time(0));
				int random = (rand() % 4);
				if (this->EnemyPokemonCapacity[random].effect == "Physique") {
					AllyDommageTaken = ((((this->EnemyPokemon->lvl * 0.4 + 2) * this->EnemyPokemon->attack * this->EnemyPokemonCapacity[random].power) / (this->AllyPokemon->defense * 50)) + 2);
				}
				else if (this->EnemyPokemonCapacity[random].effect == "Special") {
					AllyDommageTaken = ((((this->EnemyPokemon->lvl * 0.4 + 2) * this->EnemyPokemon->attack_spe * this->EnemyPokemonCapacity[random].power) / (this->AllyPokemon->defense_spe * 50)) + 2);
				}
				this->AllyPokemonActualHealth = this->AllyPokemonActualHealth - AllyDommageTaken;
				if (this->AllyPokemonActualHealth <= 0) {
					this->AllyPokemonActualHealth = 0;
				}
			}

		}
		else {
			srand(time(0));
			int random = (rand() % 4);

			if (this->EnemyPokemonCapacity[random].effect == "Physique") {
				AllyDommageTaken = ((((this->EnemyPokemon->lvl * 0.4 + 2) * this->EnemyPokemon->attack * this->EnemyPokemonCapacity[random].power) / (this->AllyPokemon->defense * 50)) + 2);
			}
			else if (this->EnemyPokemonCapacity[random].effect == "Special") {
				AllyDommageTaken = ((((this->EnemyPokemon->lvl * 0.4 + 2) * this->EnemyPokemon->attack_spe * this->EnemyPokemonCapacity[random].power) / (this->AllyPokemon->defense_spe * 50)) + 2);
			}

			this->AllyPokemonActualHealth = this->AllyPokemonActualHealth - AllyDommageTaken;
			if (this->AllyPokemonActualHealth <= 0) {
				this->AllyPokemonActualHealth = 0;
			}
			else {
				if (this->capacityUsed.effect == "Physique") {
					EnemyDommageTaken = ((((this->AllyPokemon->lvl * 0.4 + 2) * this->AllyPokemon->attack * this->capacityUsed.power) / (this->EnemyPokemon->defense * 50)) + 2);
				}
				else if (this->capacityUsed.effect == "Special") {
					EnemyDommageTaken = ((((this->AllyPokemon->lvl * 0.4 + 2) * this->AllyPokemon->attack_spe * this->capacityUsed.power) / (this->EnemyPokemon->defense_spe * 50)) + 2);
				}

				this->EnemyPokemonActualHealth = this->EnemyPokemonActualHealth - EnemyDommageTaken;
				if (this->EnemyPokemonActualHealth <= 0) {
					this->EnemyPokemonActualHealth = 0;
				}

				EnnemyHealth.setString(to_string(this->EnemyPokemonActualHealth) + "/" + to_string(this->EnemyPokemon->hp));
			}

		}

		if (this->AllyPokemonActualHealth > 0 && this->EnemyPokemonActualHealth > 0) {
			this->BattlePhase = 2;
			this->window->display();
		}
	}
}

//Run and After Run

void BattleScreen::RunStep() {
	srand(time(0));
	int oddsEscape = (((this->AllyPokemon->speed * 128) / 55) + this->EnemyPokemon->speed * this->RunAttempt) % 256;
	int random = (rand() % 256);

	this->window->clear();
	this->window->draw(this->BackGround);
	this->window->draw(this->RectangleText);
	if (random > oddsEscape) {
		sf::Text RunMessage;
		RunMessage.setFont(this->font);
		RunMessage.setString("You failed to run away");
		RunMessage.setCharacterSize(50);
		RunMessage.setFillColor(sf::Color::Black);
		RunMessage.setOrigin((double)RunMessage.getLocalBounds().width / 2, (double)RunMessage.getLocalBounds().height / 2);
		RunMessage.setPosition(this->RectangleText.getPosition().x + RunMessage.getLocalBounds().width, this->RectangleText.getPosition().y + RunMessage.getLocalBounds().height);
		this->window->draw(RunMessage);
		this->window->draw(this->EnemyPokemonSprite);
		this->window->draw(this->AllyPokemonSprite);
		this->window->display();

	}
	else if (random <= oddsEscape) {
		sf::Text RunMessage;
		RunMessage.setFont(this->font);
		RunMessage.setString("You got away safely");
		RunMessage.setCharacterSize(50);
		RunMessage.setFillColor(sf::Color::Black);
		RunMessage.setOrigin((double)RunMessage.getLocalBounds().width / 2, (double)RunMessage.getLocalBounds().height / 2);
		RunMessage.setPosition(this->RectangleText.getPosition().x + RunMessage.getLocalBounds().width, this->RectangleText.getPosition().y + RunMessage.getLocalBounds().height);
		this->window->draw(RunMessage);
		this->window->draw(this->EnemyPokemonSprite);
		this->window->draw(this->AllyPokemonSprite);
		this->window->display();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		if (random > oddsEscape) {
			this->BattlePhase = 8;
		}
		else {
			this->BattlePhase = -1;
		}
	}
}

void BattleScreen::FailedRunDommageStep() {

}

// Change Pokemon


void BattleScreen::ChoosePokemon() {
	this->window->clear();
	this->window->draw(this->BackGround);
	this->window->draw(this->RectangleText);
	sf::Text WorkInProgress;
	WorkInProgress.setFont(this->font);
	WorkInProgress.setString("Work In Progress");
	WorkInProgress.setCharacterSize(50);
	WorkInProgress.setFillColor(sf::Color::Black);
	WorkInProgress.setOrigin((double)WorkInProgress.getLocalBounds().width / 2, (double)WorkInProgress.getLocalBounds().height / 2);
	WorkInProgress.setPosition(this->RectangleText.getPosition().x + WorkInProgress.getLocalBounds().width, this->RectangleText.getPosition().y + WorkInProgress.getLocalBounds().height);
	this->window->draw(WorkInProgress);
	this->window->display();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		this->BattlePhase = 2;
	}
}

// Open the bag

void BattleScreen::BagStep() {
	this->window->clear();
	this->window->draw(this->BackGround);
	this->window->draw(this->RectangleText);
	sf::Text WorkInProgress;
	WorkInProgress.setFont(this->font);
	WorkInProgress.setString("Work In Progress");
	WorkInProgress.setCharacterSize(50);
	WorkInProgress.setFillColor(sf::Color::Black);
	WorkInProgress.setOrigin((double)WorkInProgress.getLocalBounds().width / 2, (double)WorkInProgress.getLocalBounds().height / 2);
	WorkInProgress.setPosition(this->RectangleText.getPosition().x + WorkInProgress.getLocalBounds().width, this->RectangleText.getPosition().y + WorkInProgress.getLocalBounds().height);
	this->window->draw(WorkInProgress);
	this->window->display();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		this->BattlePhase = 2;
	}
}


void BattleScreen::ShowBattleScreen(bool click, const char* buttonName, sf::Event event) {
	if (this->BattlePhase == 0)
		this->BattleAnimation(event);
	else if (this->BattlePhase == 1)
		this->StartBattle(event);
	else if (this->BattlePhase == 2)
		this->ChooseBattleAction(click, buttonName);
	else if (this->BattlePhase == 3)
		this->ChooseAttack(click, buttonName);
	else if (this->BattlePhase == 4)
		this->DommageStep();
	else if (this->BattlePhase == 5)
		this->BagStep();
	else if (this->BattlePhase == 6)
		this->RunStep();
	else if (this->BattlePhase == 7)
		this->ChoosePokemon();
	else if (this->BattlePhase == 8)
		this->FailedRunDommageStep();

};
