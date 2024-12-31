#include "object.hpp"
ykes::Object::Object()
{
}
ykes::Object::~Object()
{
}

int ykes::Object::getId(void) const
{
	return id;
}
std::string ykes::Object::getType(void) const
{
	return type;
}
ykes::Vector ykes::Object::getPosition(void) const
{
	return position;
}

void ykes::Object::setId(int o_id)
{
	this->id = o_id;
}
void ykes::Object::setType(std::string type)
{
	this->type = type;
}
void ykes::Object::setPosition(ykes::Vector o_position)
{
	this->position = o_position;
}