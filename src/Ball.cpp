#include "Ball.h"
#include "Collision.h"
#include "Player.h"
#include "SFML/Graphics.hpp"

Ball::Ball() {
	reset();
	move();
	
	
	player1Score = 0;
	player2Score = 0;
	font.loadFromFile("PingPong.otf");
	text1.setFont(font);
	text1.setCharacterSize(40);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(300.f, 20.f);
	text2.setFont(font);
	text2.setCharacterSize(40);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(350.f, 20.f);

	won1.setFont(font);
	won1.setCharacterSize(40);
	won1.setFillColor(sf::Color::White);
	
	won2.setFont(font);
	won2.setCharacterSize(40);
	won2.setFillColor(sf::Color::White);
	
	
	
}
void Ball::draw(sf::RenderWindow& window) {
	if (isGameOver) {
		window.clear(sf::Color::Black);
			if (player1Score == 5) {
				window.draw(won1);
			}
			if (player2Score == 5) {
				window.draw(won2);
			}
		
	}
	else {
		window.draw(ball);
		window.draw(text1);
		window.draw(text2);
	}
	
	
	
}

void Ball::move() {
	text1.setString(std::to_string(player1Score));
	
	text2.setString(std::to_string(player2Score));

	if (ball.getPosition().y > 440 || ball.getPosition().y < 0) {
		speedY *= -1;


	}

	
	if (ball.getPosition().x > 640) {
		reset();
		++player1Score;

		
	}
	if (ball.getPosition().x < 0) {
		reset();
		++player2Score;
	}
	if (player1Score == 5) {
		
		isGameOver = true;
		won1.setString("Player 1 won");
		
		
	}
	else if (player2Score == 5) {

		
		isGameOver = true;
		won2.setString("Player 2 won");
		
	
	}
	
	

		
	ball.move(speedX, speedY);

}

sf::CircleShape* Ball::getShape()
{
	return &ball;
}
void Ball::changeDirection() {
	speedX *= -1;
}
void Ball::reset() {
	ball.setRadius(20);
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(300, 220);
	speedY = 5;
	speedX = 5;

}
float Ball::getSpeedX() {
	return speedX;
}


void Ball::releaseMe()
{
	if (speedX > 0)
		ball.move(-20.f, 0);
	else
		ball.move(20.f, 0);

}
void Ball::scores() {
	player1Score = 0;
	player2Score = 0;
	isGameOver = false;
}
