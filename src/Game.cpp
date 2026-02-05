#include "Game.h"



Game::Game()
	:player(true),player2(false),evnt(), window(sf::VideoMode(640, 480), "PingPong", sf::Style::Close)
{
	initFonts();
	initText();
}
void Game::update() {
	if (!ball.isGameOver) {
		ball.move();

		collision.doCollision(&ball, &player);
		collision.doCollision(&ball, &player2);
	}
	
	

}
void Game::runGame() {
	std::cout << "Hi" << std::endl;

	window.setFramerateLimit(60);
	//players();
	while (window.isOpen()) {

		pollEvent();
		playersMove();
		update();


		ballAndPlayers();

	}

}
void Game::pollEvent() {
	while (window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed)
		{
			window.close();
		}
		if (ball.isGameOver && evnt.type == sf::Event::KeyPressed) {
			if (evnt.key.code == sf::Keyboard::Enter) {
				ball.scores();
				ball.reset();
			}
		}
	}
}
void Game::players() {
	Player player(true);
	Player player2(false);
}
void Game::playersMove() {
	player.move();
	player2.move();
}
void Game::ballAndPlayers() {
	window.clear(sf::Color::Black);
	if (ball.isGameOver) {
		ball.draw(window);
	}
	else {
		
		player.draw(window);
		player2.draw(window);
		ball.draw(window);
	}
	
	
	window.display();
}
void Game::initFonts() {
	if (!font.loadFromFile("PingPong.otf")) {
		std::cout << "Error. Failed to load font!" << "\n";
	}
}
void Game::initText() {
	text.setFont(font);
	text.setCharacterSize(16);
	text.setFillColor(sf::Color::White);
}
