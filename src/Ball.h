#pragma once
#include "SFML/Graphics.hpp"
class Ball
{
public:
	Ball();
	void setPosition();
	void setFillColor();
	void setRadius();
	void draw(sf::RenderWindow& window);
	void move();
	void reset();
	sf::CircleShape* getShape();
	void changeDirection();
	float getSpeedX();
	void releaseMe();
	void scores();
	bool isGameOver = false;


private:
	sf::CircleShape ball;
	
	float speedY;
	float speedX;
	
	int player1Score;
	int player2Score;
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Text won1;
	sf::Text won2;
	sf::RenderWindow window;
};

