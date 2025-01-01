#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H
#include "clock.hpp"
#include "log.hpp"
#include "manager.hpp"
#include "world_manager.hpp"

#define FRAME_TIME_DEF 33

#define GM ykes::GameManager

namespace ykes
{
	class GameManager : public Manager
	{

	    private:
		GameManager();
		GameManager(GameManager const &);
		void operator=(GameManager const &);
		~GameManager();
		bool      game;
		int       frame_time;
		static LM logger;

	    public:
		static inline GameManager &get_instance(void);

		int  start(LM &log, CLOCK *c, WM &wm);
		void shut(LM &log, WM &wm);
		void run();
		void end_game(bool over = true);
		bool get_game_state() const;
		int  get_frame_time() const;
	};
} // namespace ykes

inline GM &GM::get_instance(void)
{
	static GameManager g;
	return g;
}
#endif
