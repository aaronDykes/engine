#pragma once

#include "common.h"
#include "event.hpp"
#include <string>

namespace ykes
{

	class Manager
	{

	    private:
		std::string m_type;
		bool        active;

	    protected:
		void set_type(std::string m_type);

	    public:
		Manager();
		virtual ~Manager();
		std::string get_type(void);

		int          onEvent(Event *event) const;
		virtual int  start();
		virtual void end();
	};

} // namespace ykes
