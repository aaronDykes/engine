#include "display_manager.hpp"
#include "event_step.hpp"
#include "game_manager.hpp"
// #include <SFML/Graphics.hpp>

static ykes::WorldManager   &wm  = ykes::WorldManager::get_instance();
static ykes::LogManager     &log = ykes::LogManager::get_instance();
static ykes::DisplayManager &dm  = ykes::DisplayManager::get_instance();

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

int ykes::GameManager::start(void)
{
	wm.start();
	log.start();
	dm.start();
	return 0;
}
void ykes::GameManager::shut(void)
{
	wm.shut();
	dm.shut();
	log.shut();
	this->end_game(true);
}

int ykes::GameManager::run()
{

	ykes::Clock c = ykes::Clock();

	this->start();

	while (1)
	{

		c.start();

		log.init_flush(true);

		wm.update();
		wm.draw();

		dm.swap_buffers();

		log.message("Elapsed time (ms): %ld\n", c.elapsed_ms());
	}
	log.message("Ending game...\n");
	this->shut();
	return 0;
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
	Manager::onEvent(&e);
}

int ykes::Manager::onEvent(Event *event) const
{
	size_t i;

	List list = wm.getObjectList();

	for (i = 0; i < list.count; i++)
		(*(list.list + i))->eventHandler(event);

	return i;
}