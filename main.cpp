#include "clock.hpp"
#include "game_manager.hpp"
#include "log.hpp"
#include <SFML/Graphics.hpp>
#include <time.h>

int main()
{

	CLOCK clock = CLOCK();

	static GM &game = GM::get_instance();
	static LM &log  = LM::get_instance();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape  shape(100.0);
	shape.setFillColor(sf::Color::Green);

	clock.start();

	game.start(log);

	log.message("Testing 123\n");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	log.message("Ending game...\n");

	game.shut(log);

	return 0;
}
