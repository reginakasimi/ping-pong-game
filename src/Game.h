#pragma once
#include "Collision.h"
#include "Ball.h"
#include "Player.h"
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
	;
private:
	Ball ball;
	Player player;
	Player player2;
	sf::Font font;
	sf::Text text;
	Collision collision;
	sf::Event evnt;
	sf::RenderWindow window;
};

