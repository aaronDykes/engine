#pragma once

#include "object.hpp"
#include <SFML/Graphics.hpp>
#include <string>

#define INIT_CONDITION 5
#define DEF_DOOR       4

namespace ykes
{
	class Car : public Object
	{
	    private:
		std::string manufacturer;
		std::string trim;
		int         door_count;
		sf::Color   finish;

	    public:
		Car()
		    : manufacturer("toyota"), trim("trd por"), door_count(DEF_DOOR),
			finish(sf::Color::Red) {};

		Car(std::string car_type, std::string trim, int door_count,
		    sf::Color finish);
		~Car();

		std::string getManufacturer(void) const;
		void        setManufacturer(std::string car_type);

		std::string getTrim(void) const;
		void        setTrim(std::string trim);

		int  getDoorCount(void) const;
		void setDoorCount(int doorCount);

		sf::Color getFinish(void) const;
		void      setFinish(sf::Color finish) const;

		int eventHandler(Event *e);
		int draw();
	};
} // namespace ykes