#pragma once

#include "common.h"
#include "event.hpp"
#include <string>

namespace ykes
{

	class Manager
	{

	    private:
		std::string  m_type;
		virtual void operator=(Manager const &m);
		bool         active;

	    protected:
		Manager();
		virtual ~Manager();
		void set_type(std::string m_type);

	    public:
		std::string get_type(void) const;

		int          onEvent(Event *event) const;
		virtual int  start();
		virtual void shut();
	};

} // namespace ykes
