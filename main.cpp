#include "game_manager.hpp"
#include "log.hpp"
#include <time.h>

int main()
{

	static GM &game = GM::get_instance();
	static LM &log  = LM::get_instance();

	game.run(log);

	return 0;
}
