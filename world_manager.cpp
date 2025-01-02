#include "world_manager.hpp"

ykes::WorldManager::WorldManager()
{
}
ykes::WorldManager::WorldManager(WorldManager const &wm)
{
}
void ykes::WorldManager::operator=(WorldManager const &wm)
{
}

ykes::WorldManager::~WorldManager()
{
}

int ykes::WorldManager::start()
{
	return 0;
}

void ykes::WorldManager::shut()
{
}

void ykes::WorldManager::insertObject(Object *obj)
{
	updates.push(obj);
}
int ykes::WorldManager::removeObject(Object *obj)
{
	return updates.remove(obj);
}

ykes::List ykes::WorldManager::getObjectList(void) const
{
	return updates;
}
ykes::List ykes::WorldManager::getObjectsOfType(std::string type) const
{
	List list = List();

	for (size_t i = 0; i < updates.count; i++)
		if ((*(updates.list + i))->getType() == type)
			list.push(*(updates.list + i));
	return list;
}
void ykes::WorldManager::update(void)
{

	for (size_t i = 0; i < deletions.count; i++)
	{
		delete *(deletions.list + i);
		*(deletions.list + i) = NULL;
	}
}

int ykes::WorldManager::markForDelete(Object *obj)
{

	for (size_t i = 0; i < deletions.count; i++)
		if ((*(deletions.list + i))->getType() == obj->getType())
			return 0;

	deletions.push(obj);
	return 1;
}
