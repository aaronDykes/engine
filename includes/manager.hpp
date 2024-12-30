#ifndef MANAGER_H
#define MANAGER_H
#include "common.h"
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

		virtual int  start();
		virtual void end();
	};

} // namespace ykes

#endif
