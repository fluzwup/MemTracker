#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include "MemTracker.h"

void _free(void * address, const char *file, int line) 
{
	free(address);
	freeFunc(address);
}

void *_realloc(void * oldBuffer, size_t newSize, const char *file, int line) 
{
	void *newptr = _malloc(newSize, file, line);
	reallocFunc(oldBuffer, newptr, newSize, file, line);
	return newptr;
}

void *_malloc(size_t size, const char *file, int line) 
{
	void *ptr = malloc(size);
	allocFunc(ptr, size, file, line);
	return ptr;
}

