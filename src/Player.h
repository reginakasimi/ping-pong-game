#pragma once
#include <SFML/Graphics.hpp>
class Player
{


public:

	Player(bool isPlayer1);
	void setPosition();
	void setSize();
	void move();
	void draw(sf::RenderWindow& window);
	void setFillColor();
	sf::RectangleShape* getShape();

private:
	bool  isPlayer1;
	sf::RectangleShape player;

};

