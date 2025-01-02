
#include "event.hpp"

ykes::Event::Event()
{
}
ykes::Event::~Event()
{
}

int ykes::Event::eventHandler(Event *e)
{
	return 0;
}

std::string ykes::Event::getType(void) const
{
	return event_type;
}
void ykes::Event::setType(std::string type)
{
	event_type = type;
}