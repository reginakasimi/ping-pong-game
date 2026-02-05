#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"
class Collision
{
public:
	float clamp(float value, float max, float min);
	bool checkCollision(sf::CircleShape* ball, sf::RectangleShape* player);
	void doCollision(Ball*, Player*);


};

