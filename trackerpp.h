#include <sys/types.h>
#include <new>

#include "tracker.h"

void * operator new( size_t );
void * operator new( size_t , const std::nothrow_t & );
void   operator delete( void * );
void   operator delete( void * , const std::nothrow_t & );

void * operator new[]( size_t );
void * operator new[]( size_t , const std::nothrow_t & );
void   operator delete[]( void * );
void   operator delete[]( void *, const std::nothrow_t & );

void * operator new( size_t, const char *, int );
void * operator new( size_t, const std::nothrow_t &, const char *, int );

void * operator new[]( size_t, const char *, int );
void * operator new[]( size_t, const std::nothrow_t &, const char *, int );

#ifndef MEMTRACKER_NOSOURCE
#define new_NOTHROW new(std::nothrow, (const char *)__FILE__, __LINE__)
#define new         new((const char *)__FILE__, __LINE__)
#endif
