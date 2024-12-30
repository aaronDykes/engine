#include "log.hpp"
#include <SFML/Graphics.hpp>

int main()
{

	static ykes::LogManager &log = ykes::LogManager::get_instance();

	log.start();
	log.logMessage("%d\n", 69420);
	log.shut();

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape  shape(100.0);
	shape.setFillColor(sf::Color::Green);

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

	return 0;
}
