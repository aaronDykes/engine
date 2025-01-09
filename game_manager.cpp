#include "car.hpp"
#include "display_manager.hpp"
#include "event_step.hpp"
#include "game_manager.hpp"
#include "input_manager.hpp"
// #include <SFML/Graphics.hpp>

static ykes::WorldManager   &wm  = ykes::WorldManager::get_instance();
static ykes::LogManager     &log = ykes::LogManager::get_instance();
static ykes::DisplayManager &DM  = ykes::DisplayManager::get_instance();
static ykes::InputManager   &IM  = ykes::InputManager::get_instance();

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
	DM.start();
	return 0;
}
void ykes::GameManager::shut(void)
{
	wm.shut();
	DM.shut();
	IM.shut();
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

		Object *obj = new Object("ykes::Car");
		Car    *car = dynamic_cast<Car *>(obj);

		// wm.markForDelete(car);
		broadcastEvents();

		wm.update();
		wm.draw();

		int res = 0;
		while (DM.getWindow()->isOpen())
		{

			if ((res = IM.get_input()) == -1)
			{
				shut();
				return 0;
			}
			if (res == 1)
				return res;

			DM.drawString(
			    Vector(10, 10), "*****", JUSTIFIED_CENTER, sf::Color::Red
			);
			DM.swap_buffers();
		}

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
	altitude = HALF_MAX_ALTITUDE;
	wm.insertObject(this);
}

ykes::Object::Object(std::string type)
{
	this->type     = type;
	this->altitude = HALF_MAX_ALTITUDE;
	wm.insertObject(this);
}
ykes::Object::~Object()
{
	wm.removeObject(this);
}

#ifdef CAR_TST_DBG
void ykes::GameManager::broadcastEvents(void)
{
	EventStep e;
	e.setType("collision");
	onEvent(&e);
}
#endif

int ykes::Manager::onEvent(Event *event) const
{
	size_t i;

	int  res  = 0;
	List list = wm.getObjectList();

	for (i = 0; i < list.count; i++)
		if ((res = (*(list.list + i))->eventHandler(event)) == 1)
			wm.markForDelete(*(list.list + i));

	return i;
}

int ykes::InputManager::start(void)
{
	sf::RenderWindow *win = NULL;
	win                   = DM.getWindow();

	if (!win)
		return 1;

	win->setKeyRepeatEnabled(false);

	return Manager::start();
}

void ykes::InputManager::shut(void)
{
	sf::RenderWindow *win = NULL;
	win                   = DM.getWindow();

	if (!win)
		return;

	win->setKeyRepeatEnabled(true);
	Manager::shut();
}

int ykes::InputManager::get_input(void) const
{
	sf::RenderWindow *win = NULL;
	win                   = DM.getWindow();

	sf::Event event;

	if (!win)
		return 1;

	while (win->pollEvent(event))
	{

		if (event.type == sf::Event::Closed ||
		    (event.type == sf::Event::KeyPressed &&
		     (event.key.code == sf::Keyboard::Q)))
		{
			return -1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			;

		switch (event.type)
		{

		case sf::Event::KeyReleased:
		case sf::Event::MouseMoved:
			switch (event.mouseButton.button)
			{
			case sf::Mouse::Button::Left:
			case sf::Mouse::Button::Right:
			case sf::Mouse::Button::Middle:
			default:
			}

		case sf::Event::MouseButtonPressed:

		default:
		}
	}
	return 0;
}
