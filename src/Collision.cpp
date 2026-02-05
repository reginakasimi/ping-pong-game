#include "Collision.h"
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Player.h"
#include <iostream>

float Collision::clamp(float value, float min, float max) {
	return std::max(min, std::min(max, value));
}

bool Collision::checkCollision(sf::CircleShape* ball, sf::RectangleShape* player) {
	//printf("x = %.2f y = %.2f\n", ball->getPosition().x, ball->getPosition().y);


	sf::Vector2f AABBextends = { player->getSize().x / 2, player->getSize().y / 2 };
	sf::Vector2f AABBcenter = { player->getPosition().x + AABBextends.x, player->getPosition().y + AABBextends.y };




	sf::Vector2f center = { ball->getPosition().x + ball->getRadius(), ball->getPosition().y + ball->getRadius() };

	sf::Vector2f difference = center - AABBcenter;


	sf::Vector2f clamped = { clamp(difference.x, -AABBextends.x, AABBextends.x),clamp(difference.y, -AABBextends.y, AABBextends.y) };


	sf::Vector2f closestNokta = AABBcenter + clamped;


	sf::Vector2f differenceToClosestNokta = closestNokta - center;

	float length = std::sqrt((differenceToClosestNokta.x * differenceToClosestNokta.x) + (differenceToClosestNokta.y * differenceToClosestNokta.y));

	return length < ball->getRadius();

}
void Collision::doCollision(Ball* ball, Player* player) {

	if (checkCollision(ball->getShape(), player->getShape()))
	{
		
		ball->releaseMe();
		ball->changeDirection();
	}
}
