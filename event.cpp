
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
	return "fuck shit";
}
void ykes::Event::setType(std::string type)
{
}