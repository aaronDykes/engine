#pragma once

#include "clock.hpp"
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
		void operator=(GameManager const &);
		~GameManager();
		bool game;
		int  frame_time;

	    public:
		static inline GameManager &get_instance(void);

		int start(
		    ykes::LogManager &log, ykes::Clock *c, ykes::WorldManager &wm
		);

		void broadcastEvents(void);
		void shut(ykes::LogManager &log, ykes::WorldManager &wm);
		void run();
		void end_game(bool over = true);
		bool get_game_state() const;
		int  get_frame_time() const;
	};
} // namespace ykes

inline ykes::GameManager &ykes::GameManager::get_instance(void)
{
	static GameManager g;
	return g;
}
