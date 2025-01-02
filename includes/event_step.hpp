#pragma once
#include "event.hpp"

namespace ykes
{
	const std::string STEP_EVENT = "ykes::EventStep";

	class EventStep : public Event
	{
	    private:
		int step_count;

	    public:
		EventStep() : step_count(0) {};
		EventStep(int i);
		~EventStep();

		void setCount(int Int);
		void inc(void);

		int getCount(void) const;
	};
} // namespace ykes
