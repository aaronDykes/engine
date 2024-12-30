#include "common.h"
#include "log.hpp"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

ykes::LogManager::LogManager()
{
}
ykes::LogManager::LogManager(LogManager const &)
{
}

void ykes::LogManager::operator=(LogManager const &)
{
}

ykes::LogManager::~LogManager()
{
}

int ykes::LogManager::start()
{
	this->log_file = NULL;
	this->log_file = fopen(LOG_FILE.c_str(), "a");

	if (!this->log_file)
	{
		fprintf(stderr, "Unable to open file %s\n", LOG_FILE.c_str());
		return 1;
	}

	return 0;
}
int ykes::LogManager::shut()
{
	if (!this->log_file)
		return 0;
	fclose(this->log_file);
	this->log_file = NULL;
	return 0;
}

void ykes::LogManager::init_flush(bool do_flush)
{

	this->flush = do_flush;

	if (this->flush)
		fflush(stderr);
}

void ykes::LogManager::logMessage(const char *fmt, ...)
{
	fprintf(stderr, "Message: ");
	va_list args;
	va_start(args, fmt);
	vfprintf(this->log_file, fmt, args);
	va_end(args);
}
