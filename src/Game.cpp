#include "Game.h"



Game::Game()
	:evnt(), window(sf::VideoMode(640, 480), "Snake", sf::Style::Close)
{
	
}

void Game::runGame() {
	

	window.setFramerateLimit(10);
	
	while (window.isOpen()) {

		pollEvent();
		snake.move();
		display();

	}

}
void Game::pollEvent() {
	
	while (window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::Closed)
		{
			window.close();
		}

		
	}
}
void Game::display() {
	window.clear();
	
	snake.draw(window);

	window.display();
}


