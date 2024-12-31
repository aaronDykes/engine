#include "game_manager.hpp"
#include "log.hpp"

GM::GameManager()
{
}
GM::GameManager(GameManager const &)
{
}
void GM::operator=(GameManager const &)
{
}
GM::~GameManager()
{
}

int GM::start(LM &log)
{
	log.start();
	return 0;
}
void GM::shut(LM &log)
{
	log.shut();
	this->end_game(true);
}
void GM::run(void)
{
}
void GM::end_game(bool over)
{
	this->game = over;
}
bool GM::get_game_state() const
{
	return this->game;
}
int GM::get_frame_time() const
{
	return this->frame_time;
}