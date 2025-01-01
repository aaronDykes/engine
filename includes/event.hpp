#ifndef EVENT_H
#define EVENT_H

#include "common.h"

namespace ykes
{

	class Event
	{
	    private:
	    public:
		Event();
		~Event();
		virtual int eventHandler(Event *e);
	};

} // namespace ykes

#endif
