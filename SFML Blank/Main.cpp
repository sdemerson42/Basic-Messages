#include "SFML\Graphics.hpp"
#include "World.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	const double GAME_SPEED = 15.0;

	sf::RenderWindow window(sf::VideoMode(640, 640), "Systems Test 1");
	sf::Clock game_clock;

	World* world = new World;

	game_clock.restart();

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		if (game_clock.getElapsedTime().asMilliseconds() >= GAME_SPEED)
		{
			world->update();
			game_clock.restart();
		}

		window.clear(sf::Color::Black);
		window.draw(*world);
		window.display();
	}

	delete world;

	return 0;
}