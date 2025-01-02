#include "clock.hpp"

ykes::Clock::Clock()
{
	this->after.tv_nsec = 0;
	this->after.tv_sec  = 0;

	this->before.tv_nsec = 0;
	this->before.tv_sec  = 0;

	this->sleep.tv_nsec = 0;
	this->sleep.tv_sec  = 0;
}
ykes::Clock::~Clock()
{
}

void ykes::Clock::start(void)
{
	clock_gettime(CLOCK_REALTIME, &this->before);
}
void ykes::Clock::_sleep(Long N)
{
	this->sleep.tv_sec  = 0;
	this->sleep.tv_nsec = N;
	nanosleep(&this->sleep, NULL);
}

Long ykes::Clock::elapsed_ns(void)
{
	clock_gettime(CLOCK_REALTIME, &this->after);
	return this->after.tv_nsec - this->before.tv_nsec;
}
Long ykes::Clock::elapsed_ms(void)
{
	clock_gettime(CLOCK_REALTIME, &this->after);
	long int before_ms = before.tv_sec * 1000000 + before.tv_nsec / 1000;
	long int after_ms  = after.tv_sec * 1000000 + after.tv_nsec / 1000;
	return after_ms - before_ms;
}
Long ykes::Clock::elapsed_sec(void)
{
	clock_gettime(CLOCK_REALTIME, &this->after);

	return after.tv_sec - before.tv_sec;
}