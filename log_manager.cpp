#include "common.h"
#include "log_manager.hpp"
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
void ykes::LogManager::shut()
{

	if (!this->log_file)
		return;
	fclose(this->log_file);
	this->log_file = NULL;
}

void ykes::LogManager::init_flush(bool do_flush)
{

	this->flush = do_flush;

	if (this->flush)
		fflush(this->log_file);
}

void ykes::LogManager::message(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	fprintf(this->log_file, "Game log [%d]: ", this->log_count++);
	vfprintf(this->log_file, fmt, args);
	va_end(args);
}
