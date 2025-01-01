#include "event_step.hpp"

ykes::EventStep::EventStep(int i)
{
	step_count = i;
}
ykes::EventStep::~EventStep()
{
}

void ykes::EventStep::setCount(int Int)
{
}
void ykes::EventStep::inc(void)
{
}

int ykes::EventStep::getCount(void) const
{
	return step_count;
}