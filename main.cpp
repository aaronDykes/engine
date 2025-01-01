#include "game_manager.hpp"
#include "log.hpp"
#include "object_list.hpp"
#include <time.h>

using namespace ykes;

int main()
{

	static GM &game = GM::get_instance();

	List list = List();

	Object o = Object("Bullet");

	list.push(&o);
	list.push(&o);
	list.push(&o);
	list.push(&o);
	list.push(&o);
	list.push(&o);

	list.push(&o);
	list.push(&o);
	list.push(&o);
	list.push(&o);
	list.push(&o);

	list.dump();

	game.run(LM::get_instance());

	return 0;
}
