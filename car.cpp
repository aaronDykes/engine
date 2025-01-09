#include "car.hpp"

ykes::Car::Car(
    std::string car_type, std::string trim, int door_count, sf::Color finish
)
{
	this->manufacturer = car_type;
	this->trim         = trim;
	this->door_count   = door_count;
	this->finish       = finish;
	setType("ykes::Car");
}

ykes::Car::~Car()
{
}

std::string ykes::Car::getManufacturer(void) const
{
	return manufacturer;
}
void ykes::Car::setManufacturer(std::string car_type)
{
	this->manufacturer = car_type;
}

std::string ykes::Car::getTrim(void) const
{
}
void ykes::Car::setTrim(std::string trim)
{
}

int ykes::Car::getDoorCount(void) const
{
}
void ykes::Car::setDoorCount(int doorCount)
{
}

sf::Color ykes::Car::getFinish(void) const
{
}
void ykes::Car::setFinish(sf::Color finish) const
{
}

int ykes::Car::eventHandler(Event *e)
{

	std::string type = e->getType();

	if (type == "collision")
		return 1;

	return 0;
}

int ykes::Car::draw()
{
	return 0;
}