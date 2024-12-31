#include "object.hpp"
ykes::Object::Object()
{
}
ykes::Object::Object(std::string type)
{
	this->type = type;
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

bool ykes::Object::operator==(const Object &obj) const
{
	return obj.type == this->type;
}

void ykes::Object::operator=(Object const &obj)
{
	this->type     = obj.type;
	this->position = obj.position;
	this->id       = obj.id;
}