#include "game_manager.hpp"
#include "object_list.hpp"
#include <time.h>

using namespace ykes;

int main()
{

	static ykes::GameManager &game = ykes::GameManager::get_instance();

	//  List list = List();
	/*
	      Object *o  = new Object("Bullet");
	      Object *o1 = new Object("Bullet");
	      Object *o2 = new Object("Bullet");
	      Object *o3 = new Object("Bullet");
	      Object *o4 = new Object("Bullet");
	      Object *o5 = new Object("Bullet");
	      Object *o6 = new Object("Bullet");
	      Object *o7 = new Object("Bullet");
	      Object *o8 = new Object("Bullet");

	      list.push(o);

	      list.push(o1);
	      list.push(o2);
	      list.push(o3);
	      list.push(o4);
	      list.push(o5);
	      list.push(o6);
	      list.push(o7);
	      list.push(o8);

	      list.dump();

	      list.clear(); */

	game.run();

	return 0;
}
