#include "Game.h"
#include "Config.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
#include "mainCharacter.h"



int main() { // MAIN ULYSS
	Game g;
	int count = 0;
	int e = 0;

	//sf::SoundBuffer whodapokemon;

	//if (!whodapokemon.loadFromFile("Audio/whodapokemon.wav"))
	//{
	//	std::cout << "Error" << std::endl;
	//}
	//sf::Sound whodispokemon;
	//whodispokemon.setBuffer(whodapokemon);
	//whodispokemon.setVolume(90);

	//sf::SoundBuffer backgroundMusic;

	/*if (!backgroundMusic.loadFromFile("Audio/Mouettes.wav"))
	{
		std::cout << "Error" << std::endl;
	}
	sf::Sound Mouettes;
	Mouettes.setBuffer(backgroundMusic);
	Mouettes.setVolume(90);*/

	while (g.isOpen())
	{

		switch (e)
		{
		case 0:
			g.clear();
			g.handleEvents();
			//whodispokemon.play();
			//Mouettes.play();
			g.drawBackground();
			g.drawPokeball();
			g.drawTitle();
			g.drawEnterText(/*deltatime*/);
			g.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				e = 1;
				g.clear();
			}
			break;

		case 1:

			g.clear();

			g.handleEvents();
			g.drawBackground();

			g.goeliseTravel();
			sf::Vector2f position = g.movingWingull.getPosition();
			std::cout << position.x << " : " << position.y << std::endl;

			g.drawPokeball();
			g.drawTitle();

			g.goeliseTravel2();
			sf::Vector2f position2 = g.movingWingull2.getPosition();
			std::cout << position2.x << " : " << position2.y << std::endl;


			g.displayPlayButton();
			g.displaySettingsButton();
			g.displayQuitButton();

			g.display();

		}
	}

	return 0;
}

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