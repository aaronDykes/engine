#pragma once

#include "clock.hpp"
#include "display_manager.hpp"
#include "game_manager.hpp"
#include "log_manager.hpp"
#include "manager.hpp"
#include "world_manager.hpp"

#define FRAME_TIME_DEF 33

namespace ykes
{
	class GameManager : public Manager
	{

	    private:
		GameManager();
		GameManager(GameManager const &);
		~GameManager();
		void operator=(GameManager const &);
		bool game;
		int  frame_time;

	    public:
		static inline GameManager &get_instance(void);

		int start(void);

		void broadcastEvents(void);
		void shut(void);
		int  run(void);
		void end_game(bool over = true);
		bool get_game_state() const;
		int  get_frame_time() const;
	};
} // namespace ykes

inline ykes::GameManager &ykes::GameManager::get_instance(void)
{
	static GameManager g;
	g.set_type("ykes::GameManager");
	return g;
}
