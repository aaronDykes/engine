#ifndef _CLOCK_H
#define _CLOCK_H
#include "utillity.hpp"
#include <time.h>

#define TARGET_TIME 0.00000033

#define CLOCK ykes::Clock

namespace ykes
{
	class Clock
	{
	    public:
		Clock();
		~Clock();

		timespec before;
		timespec after;
		timespec sleep;

		void start(void);
		void _sleep(Long N);

		Long elapsed_ns(void);
		Long elapsed_ms(void);
		Long elapsed_sec(void);
	};
} // namespace ykes

#endif
