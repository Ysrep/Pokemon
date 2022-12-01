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
	attack.setSize(sf::Vector2f(100, 45));
	attack.setPosition(this->window->getSize().x / 1.38, this->window->getSize().y / 1.30);
	attack.setFillColor(sf::Color::Red);
	attack.setOutlineThickness(2);
	attack.setOutlineColor(sf::Color::Black);

	Attacktext.setPosition(attack.getPosition().x + (attack.getSize().x / 2) - 10, attack.getPosition().y + (attack.getSize().y / 2) - 10);

	sf::CircleShape roundedAttack((double)attack.getSize().y / 2);
	roundedAttack.setOrigin((double)roundedAttack.getTextureRect().width / 2, (double)roundedAttack.getTextureRect().height / 2);
	roundedAttack.setPosition((this->window->getSize().x / 1.38) - roundedAttack.getRadius(), (this->window->getSize().y / 1.30));
	roundedAttack.setFillColor(sf::Color::Red);
	roundedAttack.setOutlineThickness(2);
	roundedAttack.setOutlineColor(sf::Color::Black);

	sf::RectangleShape bag;
	bag.setSize(sf::Vector2f(100, 45));
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
	run.setSize(sf::Vector2f(100, 45));
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
	pokemon.setSize(sf::Vector2f(100, 45));
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





void BattleScreen::StartNewBattle() {
	this->EnemyPokemon = NULL;
	this->AllyPokemon = NULL;
	this->BattlePhase = 1;
	this->RunAttempt = 1;
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
		this->window->display();
	}
};

void BattleScreen::ChooseBattleAction(bool click, const char* buttonName) {
	this->window->clear();
	this->window->draw(this->BackGround);
	this->window->draw(this->RectangleText);

	sf::RectangleShape AllyPokemonInfo;
	AllyPokemonInfo.setSize(sf::Vector2f(175, 50));
	AllyPokemonInfo.setPosition((this->window->getSize().x- AllyPokemonInfo.getLocalBounds().width-2), (this->window->getSize().y-this->RectangleText.getLocalBounds().height - AllyPokemonInfo.getLocalBounds().height - 30));
	AllyPokemonInfo.setOutlineThickness(2);
	AllyPokemonInfo.setOutlineColor(sf::Color::Black);

	sf::Text Level;
	Level.setFont(this->font);
	Level.setString("N." + to_string(10));
	Level.setCharacterSize(20);
	Level.setFillColor(sf::Color::Black);
	Level.setPosition((AllyPokemonInfo.getPosition().x+100), (AllyPokemonInfo.getPosition().y));

	sf::Text PokemonName;
	PokemonName.setFont(this->font);
	PokemonName.setString("Rattata");
	PokemonName.setCharacterSize(20);
	PokemonName.setFillColor(sf::Color::Black);
	PokemonName.setPosition((AllyPokemonInfo.getPosition().x), (AllyPokemonInfo.getPosition().y));

	sf::Text Health;
	Health.setFont(this->font);
	Health.setString(to_string(100) + "/" + to_string(100));
	Health.setCharacterSize(20);
	Health.setFillColor(sf::Color::Black);
	Health.setPosition((AllyPokemonInfo.getPosition().x), (AllyPokemonInfo.getPosition().y+20));

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
	EnnemyLevel.setFont(this->font);
	EnnemyLevel.setString("N." + to_string(10));
	EnnemyLevel.setCharacterSize(20);
	EnnemyLevel.setFillColor(sf::Color::Black);
	EnnemyLevel.setPosition((EnnemyPokemonInfo.getPosition().x + 100), (EnnemyPokemonInfo.getPosition().y));

	sf::Text EnnemyPokemonName;
	EnnemyPokemonName.setFont(this->font);
	EnnemyPokemonName.setString("Rattata");
	EnnemyPokemonName.setCharacterSize(20);
	EnnemyPokemonName.setFillColor(sf::Color::Black);
	EnnemyPokemonName.setPosition((EnnemyPokemonInfo.getPosition().x), (EnnemyPokemonInfo.getPosition().y));

	sf::Text EnnemyHealth;
	EnnemyHealth.setFont(this->font);
	EnnemyHealth.setString(to_string(100) + "/" + to_string(100));
	EnnemyHealth.setCharacterSize(20);
	EnnemyHealth.setFillColor(sf::Color::Black);
	EnnemyHealth.setPosition((EnnemyPokemonInfo.getPosition().x), (EnnemyPokemonInfo.getPosition().y + 20));

	this->window->draw(EnnemyPokemonInfo);
	this->window->draw(EnnemyLevel);
	this->window->draw(EnnemyPokemonName);
	this->window->draw(EnnemyHealth);

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
		if (i.first == "ChooseActionTopLeft" || i.first == "ChooseActionBottomLeft" || i.first == "ChooseActionBottomRight" || i.first == "ChooseActionTopRight") {
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

void BattleScreen::ChooseAttack() {
	this->window->clear();
	this->window->draw(this->BackGround);
	this->window->draw(this->RectangleText);
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
		if (i.first == "ChooseAttackTopLeft" || i.first == "ChooseAttackBottomLeft" || i.first == "ChooseAttackBottomRight" || i.first == "ChooseAttackTopRight")
		{
			this->TextButton[i.first].setFont(this->font);
			this->window->draw(i.second);
		}
	}
	this->window->display();
}

void BattleScreen::DommageStep() {
	this->window->clear();
	this->window->draw(this->BackGround);
	this->window->draw(this->RectangleText);
	this->window->display();
}

//Run and After Run

void BattleScreen::RunStep() {
	srand(time(0));
	int oddsEscape = (((75 * 128) / 55) + 30 * this->RunAttempt) % 256;
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
		this->ChooseAttack();
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
