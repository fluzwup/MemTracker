#include <new>
#include <stdlib.h>
#include "efence.h"

void *  operator new( size_t size ) throw(std::bad_alloc)
{
  void *ptr = _malloc(size, "none", 0);
  if (!ptr) throw std::bad_alloc();
  return ptr;
}


void *  operator new( size_t size, const std::nothrow_t & ) throw()
{
  void *ptr = _malloc(size, "none", 0);
  return ptr;
}


void    operator delete( void *ptr ) throw()
{
  _free(ptr, "none", 0);
}


void    operator delete( void * ptr, const std::nothrow_t & ) throw()
{
  _free(ptr, "none", 0);
}



void *  operator new[]( size_t size ) throw(std::bad_alloc)
{
  void *ptr = _malloc(size, "none", 0);
  if (!ptr) throw std::bad_alloc();
  return ptr;
}


void *  operator new[]( size_t size, const std::nothrow_t & ) throw()
{
  void *ptr = _malloc(size, "none", 0);
  return ptr;
}


void    operator delete[]( void * ptr ) throw()
{
  _free(ptr, "none", 0);
}


void    operator delete[]( void * ptr, const std::nothrow_t & ) throw()
{
  _free(ptr, "none", 0);
}

