#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include "manager.hpp"
#include <iostream>

namespace ykes
{
	const std::string LOG_FILE = "./ykes.log";

	class LogManager : public Manager
	{
	    private:
		LogManager();
		LogManager(LogManager const &);
		void  operator=(LogManager const &);
		bool  flush;
		FILE *log_file;

	    public:
		~LogManager();

		static inline LogManager &get_instance()
		{
			static LogManager l;
			return l;
		}

		int  start();
		int  shut();
		void init_flush(bool do_flush = true);
		void logMessage(const char *fmt, ...);
	};
} // namespace ykes

#endif
