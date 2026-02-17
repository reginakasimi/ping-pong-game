#pragma once
#include "SFML/Graphics.hpp"
#include "time.h"
#include <iostream>
class Snake
{

public:
	Snake();
	void move();
	void moveBody();
	void draw(sf::RenderWindow &window);
	void killIt();
private:
	sf::RectangleShape head;
	std::vector<sf::Vector2f> body;
	sf::Vector2f velocity;
	int count;
	sf::RectangleShape apple;
	int x, y;

};

