#pragma once

#include "event.hpp"
#include "vector.hpp"
#include <string>
/* #ifndef __cplusplus
extern "C"
{
#endif

#ifndef __cplusplus
}
#endif
 */

namespace ykes
{

	class Object : public Event
	{
	    private:
		int         id;
		int         altitude;
		std::string type;
		Vector      position;

	    public:
		Object();
		Object(std::string type);
		virtual ~Object();

		int  getAltitude(void) const;
		void setAltitude(int alt);

		int  getId(void) const;
		void setId(int o_id);

		std::string getType(void) const;
		void        setType(std::string type);

		Vector getPosition(void) const;
		void   setPosition(Vector o_position);

		virtual int draw();
		virtual int eventHandler(Event *e);

		bool operator==(const Object &obj) const;
		void operator=(Object const &obj);
	};
} // namespace ykes
