#include "Player.h"

Player::Player(bool isPlayer1) {
	this->isPlayer1 = isPlayer1;
	if (isPlayer1) {
		player.setSize(sf::Vector2f((int)20, (int)100));
		player.setFillColor(sf::Color::White);
		player.setPosition(sf::Vector2f((int)0, (int)230));
	}
	else {
		player.setSize(sf::Vector2f((int)20, (int)100));
		player.setFillColor(sf::Color::White);
		player.setPosition(sf::Vector2f((int)620, (int)230));
	}

}

void Player::move() {
	if (isPlayer1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.getPosition().y > 0)
		{
			player.move(0, -5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player.getPosition().y < 380)
		{
			player.move(0, 5);
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.getPosition().y > 0)
		{
			player.move(0, -5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.getPosition().y < 380)
		{
			player.move(0, 5);
		}
	}

}
void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}
sf::RectangleShape* Player::getShape() {
	return &player;
}


