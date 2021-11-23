#include <new>
#include <stdlib.h>
#include "tracker.h"

void *  operator new( size_t size, const char *file, int line )
{
  void *ptr = _malloc(size, file, line);
  if (!ptr) throw std::bad_alloc();
  return ptr;
}


void *  operator new( size_t size, const std::nothrow_t &, const char *file, int line )
{
  void *ptr = _malloc(size, file, line);
  return ptr;
}


void    operator delete( void *ptr ) throw()
{
  _free(ptr, "none", 0);
}


void    operator delete( void * ptr, const std::nothrow_t & )
{
  _free(ptr, "none", 0);
}



void *  operator new[]( size_t size, const char *file, int line ) 
{
  void *ptr = _malloc(size, file, line);
  if (!ptr) throw std::bad_alloc();
  return ptr;
}


void *  operator new[]( size_t size, const std::nothrow_t &, const char *file, int line )
{
  void *ptr = _malloc(size, file, line);
  return ptr;
}


void    operator delete[]( void * ptr )
{
  _free(ptr, "none", 0);
}


void    operator delete[]( void * ptr, const std::nothrow_t & )
{
  _free(ptr, "none", 0);
}

