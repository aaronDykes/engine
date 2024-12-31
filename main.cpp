#include "game_manager.hpp"
#include "log.hpp"
#include "object_list.hpp"
#include <time.h>

using namespace ykes;

int main()
{

	static GM &game = GM::get_instance();
	static LM &log  = LM::get_instance();

	List list  = List();
	List list2 = List();

	Object o  = Object("Bullet");
	Object o1 = Object("lame");
	Object o2 = Object("okay cool");
	Object o3 = Object("fireball");

	list.push(&o);
	list.push(&o1);

	list2.push(&o);
	list2.push(&o1);
	list2.push(&o2);
	list2.push(&o3);

	list = list + list2;

	list.dump();

	game.run(log);

	return 0;
}
