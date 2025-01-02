#include "event_step.hpp"
#include "game_manager.hpp"
#include "log_manager.hpp"
#include <SFML/Graphics.hpp>

static ykes::WorldManager &wm  = ykes::WorldManager::get_instance();
static ykes::LogManager   &log = ykes::LogManager::get_instance();

ykes::GameManager::GameManager()
{
}
ykes::GameManager::GameManager(GameManager const &)
{
}
void ykes::GameManager::operator=(GameManager const &)
{
}
ykes::GameManager::~GameManager()
{
}

int ykes::GameManager::start(
    ykes::LogManager &log, ykes::Clock *c, ykes::WorldManager &wm
)
{
	wm.start();
	log.start();
	return 0;
}
void ykes::GameManager::shut(ykes::LogManager &log, ykes::WorldManager &wm)
{
	wm.shut();
	log.shut();
	this->end_game(true);
}
void ykes::GameManager::run(void)
{

	ykes::Clock c = ykes::Clock();

	this->start(log, &c, wm);

	Object *o  = new Object("Bullet");
	Object *o1 = new Object("Bullet");
	Object *o2 = new Object("Bullet");
	Object *o3 = new Object("Bullet");
	Object *o4 = new Object("Bullet");
	Object *o5 = new Object("Bullet");
	Object *o6 = new Object("Bullet");
	Object *o7 = new Object("Bullet");
	Object *o8 = new Object("Bullet");

	wm.markForDelete(o);
	wm.markForDelete(o1);
	wm.markForDelete(o2);
	wm.markForDelete(o3);
	wm.markForDelete(o4);
	wm.markForDelete(o5);
	wm.markForDelete(o6);
	wm.markForDelete(o7);
	wm.markForDelete(o8);

	wm.update();

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
void ykes::GameManager::end_game(bool over)
{
	this->game = over;
}
bool ykes::GameManager::get_game_state() const
{
	return this->game;
}
int ykes::GameManager::get_frame_time() const
{
	return this->frame_time;
}

ykes::Object::Object()
{
	wm.insertObject(this);
}

ykes::Object::Object(std::string type)
{
	this->type = type;
	wm.insertObject(this);
}
ykes::Object::~Object()
{
	wm.removeObject(this);
}

void ykes::GameManager::broadcastEvents(void)
{
	EventStep e;
	onEvent(&e);
}

int ykes::Manager::onEvent(Event *event) const
{
	size_t i;

	List list = wm.getObjectList();

	for (i = 0; i < list.count; i++)
		(*(list.list + i))->eventHandler(event);

	return i;
}