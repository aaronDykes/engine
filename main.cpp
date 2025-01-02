#include "game_manager.hpp"
#include "object_list.hpp"
#include <time.h>

using namespace ykes;

int main()
{

	static ykes::GameManager &game = ykes::GameManager::get_instance();

	game.run();

	return 0;
}
