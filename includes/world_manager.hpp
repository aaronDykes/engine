#ifndef _WORLD_MANAGER_H
#define _WORLD_MANAGER_H

#include "manager.hpp"
#include "object_list.hpp"

#define WM ykes::WorldManager

namespace ykes
{

	class WorldManager : public Manager
	{
	    private:
		WorldManager();
		WorldManager(WorldManager const &);
		void operator=(WorldManager const &);

		List updates;
		List deletions;

	    public:
		static inline WorldManager &get_instance();
		~WorldManager();

		int  start();
		void shut();

		void insertObject(Object *obj);
		int removeObject(Object *obj); // return 0 on success, -1 on failure

		List getObjectList(void) const;
		List getObjectsOfType(std::string type) const;
		void update(void);

		int markForDelete(Object *obj);
	};

} // namespace ykes

inline ykes::WorldManager &ykes::WorldManager::get_instance(void)
{
	static WorldManager w;
	return w;
}
#endif
