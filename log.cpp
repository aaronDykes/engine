#include "common.h"
#include "log.hpp"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

LM::LogManager()
{
}
LM::LogManager(LogManager const &)
{
}

void LM::operator=(LogManager const &)
{
}

LM::~LogManager()
{
}

int LM::start()
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
int LM::shut()
{

	if (!this->log_file)
		return 0;
	fclose(this->log_file);
	this->log_file = NULL;
	return 0;
}

void LM::init_flush(bool do_flush)
{

	this->flush = do_flush;

	if (this->flush)
		fflush(this->log_file);
}

void LM::message(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	fprintf(this->log_file, "Game log [%d]: ", this->log_count++);
	vfprintf(this->log_file, fmt, args);
	va_end(args);
}
