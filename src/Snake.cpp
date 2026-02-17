#include "Snake.h"





Snake::Snake() {
	head.setSize(sf::Vector2f(25, 25));
	head.setFillColor(sf::Color::Green);
	head.setPosition(sf::Vector2f(325, 250));
	velocity = { 0, 0 };
	count = 0;
	apple.setFillColor(sf::Color::Red);
	apple.setSize(sf::Vector2f(25, 25));
	srand(time(NULL));
	x = rand() % 620;
	y = rand() % 460;


	x = std::round(x / 25.f) * 25.f;
	y = std::round(y / 25.f) * 25.f;
	apple.setPosition(x, y);
}


void Snake::move() {
	srand(time(NULL));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)  && velocity.y <= 0)
	{ 
		velocity = { 0, -1 };

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && velocity.y >= 0)
	{
		velocity = { 0, 1 };

	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && velocity.x <= 0)
	{
		velocity = { -1, 0 };

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && velocity.x >= 0)
	{
		velocity = { 1, 0 };

	}
	if (head.getPosition() == apple.getPosition()) {
		
		count++;

		x = rand() % 620;
		y = rand() % 460;


		x = std::round(x / 25.f) * 25.f;
		y = std::round(y / 25.f) * 25.f;
		apple.setPosition(x, y);
		 

		
		
		
	}

	
	//printf("head pos: %.2f %.2f\n", head.getPosition().x, head.getPosition().y);
	printf("apple pos: %.2f %.2f\n", apple.getPosition().x, apple.getPosition().y);
		body.emplace_back(sf::Vector2f(head.getPosition().x , head.getPosition().y));
		for (sf::Vector2f b : body) {
			std::cout << (b.x, b.y) << std::endl;
		}
		if (body.size() > count) {
			body.erase(body.begin());

		}
		
		killIt();
		if (head.getPosition().x < 0 || head.getPosition().x > 620 || (head.getPosition().y < 0 || head.getPosition().y > 460)) {
			printf("Am i dead\n");
			body.clear();
			count = 0;
			head.setPosition(sf::Vector2f(325, 250));
		}

	

	head.move(velocity.x*25, velocity.y*25);

}
void Snake::draw(sf::RenderWindow &window) {
	window.draw(head);
	sf::RectangleShape bodyShape;
	bodyShape.setSize(sf::Vector2f(25, 25));
	bodyShape.setFillColor(sf::Color::Green);
	for (const sf::Vector2f &b : body) {
		bodyShape.setPosition(b);
		window.draw(bodyShape);
		
	}
	window.draw(apple);
}
void Snake::killIt() {
	if (!body.empty()) {

		for (int i = 0; i < body.size() - 1; i++) {
			if (head.getPosition() == body[i]) {
				std::cout << "i'm dead" << std::endl;
				body.clear();
				count = 0;
				break;
			}
		}


	}

}



