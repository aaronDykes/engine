#include "display_manager.cpp"
#include "game_manager.hpp"
#include "object_list.hpp"
#include <time.h>

int main()
{

	static ykes::GameManager &game = ykes::GameManager::get_instance();

	game.run();

	return 0;
}
