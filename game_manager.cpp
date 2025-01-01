#include "game_manager.hpp"
#include "log.hpp"
#include <SFML/Graphics.hpp>

GM::GameManager()
{
}
GM::GameManager(GameManager const &)
{
}
void GM::operator=(GameManager const &)
{
}
GM::~GameManager()
{
}

int GM::start(LM &log, CLOCK *c, WM &wm)
{
	wm.start();
	log.start();
	return 0;
}
void GM::shut(LM &log, WM &wm)
{
	log.shut();
	wm.shut();
	this->end_game(true);
}
void GM::run(void)
{

	LM   &log = LM::get_instance();
	WM   &wm  = WM::get_instance();
	CLOCK c   = CLOCK();

	this->start(log, &c, wm);

	while (1)
	{

		c.start();
		sf::RenderWindow window(
		    sf::VideoMode(200, 200),
		    "I love stupid fucking games that make me want to kill "
		    "myself!!!! hahaha"
		);
		sf::CircleShape shape(100.0);
		shape.setFillColor(sf::Color::Green);

		log.init_flush(true);

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

		log.message("Elapsed time (ms): %ld\n", c.elapsed_ms());
	}
	log.message("Ending game...\n");

	this->shut(log, wm);
}
void GM::end_game(bool over)
{
	this->game = over;
}
bool GM::get_game_state() const
{
	return this->game;
}
int GM::get_frame_time() const
{
	return this->frame_time;
}