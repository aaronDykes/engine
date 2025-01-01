#ifndef _OBJECT_H
#define _OBJECT_H

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
		std::string type;
		Vector      position;

	    public:
		Object();
		Object(std::string type);
		~Object();

		int         getId(void) const;
		std::string getType(void) const;
		Vector      getPosition(void) const;

		virtual int eventHandler(Event *e);
		void        setId(int o_id);
		void        setType(std::string type);
		void        setPosition(Vector o_position);
		bool        operator==(const Object &obj) const;
		void        operator=(Object const &obj);
	};
} // namespace ykes

#endif
