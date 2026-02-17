#pragma once
#include "Snake.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class Game
{
public:
	Game();
	void move();
	void update();
	void runGame();
	void pollEvent();
	void ballAndPlayers();
	void players();
	void initFonts();
	void initText();
	void playersMove();
	void display();
private:
	
	
	Snake snake;
	sf::Event evnt;
	sf::RenderWindow window;
};

