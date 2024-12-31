#include "utillity.hpp"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void writeMessage(const char *fmt, ...)
{
	fprintf(stderr, "Message: ");
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
}

char *getTime(void)
{
	static char time_str[30];

	time_t now;
	time(&now);

	struct tm *p_time = NULL;
	p_time            = localtime(&now);

	sprintf(
	    time_str, "%02d:%02d:%02d", p_time->tm_hour, p_time->tm_min,
	    p_time->tm_sec
	);

	return time_str;
}