#ifndef EVENT_H
#define EVENT_H

#include "common.h"
#include <string>

namespace ykes
{

	const std::string undefined_event = "ykes::undefined";
	class Event
	{
	    private:
		std::string event_type;

	    public:
		Event();
		virtual ~Event();
		virtual int eventHandler(Event *e);

		std::string getType(void) const;
		void        setType(std::string type);
	};

} // namespace ykes

#endif
