#include "Game.h"
#include "Pokemon.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
#include "mainCharacter.h"



int main() { // MAIN ULYSS
	Game g;
	int count = 0;
	int e = 0;

	sf::Vector2f position;
	sf::Vector2f position2;

	if (!g.arena.loadFromFile("Textures/Mainmenu/arena.jpg"))
	{
	}

	sf::SoundBuffer whodapokemon;

	if (!whodapokemon.loadFromFile("Audio/whodapokemon.wav")) //Second menu's audio
	{
		std::cout << "Error" << std::endl;
	}
	sf::Sound whodispokemon;
	whodispokemon.setBuffer(whodapokemon);
	whodispokemon.setVolume(90);

	sf::SoundBuffer backgroundMusic;

	if (!backgroundMusic.loadFromFile("Audio/Mouettes.wav")) //Second menu music
	{
		std::cout << "Error" << std::endl;
	}
	sf::Sound Mouettes;
	Mouettes.setBuffer(backgroundMusic);
	Mouettes.setVolume(90);

	while (g.isOpen()) // Main loop
	{

		switch (e) // Switch pages
		{
		case 0: //Initial menu
			g.clear();
			g.handleEvents();
			g.drawBackground();
			g.drawPokeball();
			g.drawTitle();
			g.drawEnterText();
			g.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				whodispokemon.play();
				Mouettes.play();
				e = 1;
				g.clear();
			}
			break;

		case 1: //Second menu when enter is pressed

			g.clear();

			g.handleEvents();
			g.drawBackground();
			if (!g.arena.loadFromFile("Textures/Mainmenu/arena.jpg"))
			{
			}
			g.background.setTexture(g.arena);

			g.goeliseTravel();
			position = g.movingWingull.getPosition();
			std::cout << position.x << " : " << position.y << std::endl;

			g.drawPokeball();
			g.drawTitle();

			g.goeliseTravel2();
			position2 = g.movingWingull2.getPosition();
			std::cout << position2.x << " : " << position2.y << std::endl;

			g.displayPlayButton();

			g.displaySettingsButton();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (sf::Mouse::getPosition(g.GetWindow()).x > 450.f && sf::Mouse::getPosition(g.GetWindow()).x < 600.f && sf::Mouse::getPosition(g.GetWindow()).y > 400.f && sf::Mouse::getPosition(g.GetWindow()).y < 450.f)
				{
					e = 2;
				}
				else if (sf::Mouse::getPosition(g.GetWindow()).x > 200.f && sf::Mouse::getPosition(g.GetWindow()).x < 300.f && sf::Mouse::getPosition(g.GetWindow()).y > 400.f && sf::Mouse::getPosition(g.GetWindow()).y < 450.f)
				{
					whodispokemon.stop();
					Mouettes.stop();
					e = 4;
				}
			}

			g.displayQuitButton();

			g.display();

			break;

		case 2:

			g.clear();
			g.handleEvents();
			g.drawBackgroundSettings();
			g.drawSettingsTitle();
			g.audioManageText();
			Mouettes.play();
			g.backToMainMenuText();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				e = 1;
				g.clear();
			}


			g.display();

			break;

		case 4:
			if (g.getBattle().BattlePhase == -1) {
				Pokemon wild;
				Pokemon Trainer;
				g.WildPokemon(&wild, &Trainer);
			}
			g.GameBattleScreen();
			if (g.getBattle().BattlePhase == -1) {
				e = 1;
			}
		}

	}

	return 0;
}



//int main() { //MAIN TITOUAN
//
//	sf::RenderWindow window(sf::VideoMode(640, 640), "Pokemon Salty");
//	mainCharacter mainCharMap(&window);
//	Map mapTile(&window);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		window.clear();
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		mapTile.MappingTile();
//		mainCharMap.InitChar();
//		window.display();
//	}
//}

//int main() { //MAIN TITOUAN
//
//	sf::RenderWindow window(sf::VideoMode(640, 640), "SFML works!");
//	mainCharacter mainCharMap(&window);
//	Map mapTile(&window);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		window.clear();
//		mapTile.MappingTile();
//		mainCharMap.InitChar();
//		window.display();
//	}
//}