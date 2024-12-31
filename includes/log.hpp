#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include "manager.hpp"
#include <iostream>

#define LM ykes::LogManager

namespace ykes
{
	const std::string LOG_FILE = "./ykes.log";

	class LogManager : public Manager
	{
	    private:
		LogManager();
		LogManager(LogManager const &);
		void operator=(LogManager const &);
		~LogManager();
		bool  flush;
		int   log_count = 0;
		FILE *log_file;

	    public:
		static inline LogManager &get_instance(void);

		int  start();
		int  shut();
		void init_flush(bool do_flush = true);
		void message(const char *fmt, ...);
	};
} // namespace ykes

inline LM &LM::get_instance(void)
{
	static LogManager l;
	return l;
}

#endif
