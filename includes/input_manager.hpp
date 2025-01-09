#pragma once

#include "manager.hpp"

namespace ykes
{

	class InputManager : public Manager
	{
	    private:
		InputManager();
		InputManager(InputManager const &im);
		~InputManager();
		void operator=(InputManager const &im);

	    public:
		static inline InputManager &get_instance(void);

		int get_input(void) const;

		int  start(void);
		void shut(void);
	};
} // namespace ykes

inline ykes::InputManager &ykes::InputManager::get_instance()
{
	static InputManager m;
	return m;
}