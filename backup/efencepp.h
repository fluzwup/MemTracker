#include <sys/types.h>
#include <new>

#include "efence.h"

#define new_NOTHROW new(std::nothrow)

void * operator new( size_t )                             throw(std::bad_alloc);
void * operator new( size_t , const std::nothrow_t & )    throw();
void   operator delete( void * )                             throw();
void   operator delete( void * , const std::nothrow_t & )    throw();

void * operator new[]( size_t )                           throw(std::bad_alloc);
void * operator new[]( size_t , const std::nothrow_t & )  throw();
void   operator delete[]( void * )                           throw();
void   operator delete[]( void *, const std::nothrow_t & )   throw();

void * operator new( size_t, const char *, int )                         throw( std::bad_alloc );
void * operator new( size_t, const std::nothrow_t &, const char *, int ) throw();
void   operator delete( void *, const char *, int )                         throw();
void   operator delete( void *, const std::nothrow_t &, const char *, int ) throw();

void * operator new[]( size_t, const char *, int )                         throw( std::bad_alloc );
void * operator new[]( size_t, const std::nothrow_t &, const char *, int ) throw();
void   operator delete[]( void *, const char *, int )                         throw();
void   operator delete[]( void *, const std::nothrow_t &, const char *, int ) throw();

