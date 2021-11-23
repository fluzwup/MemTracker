#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif
void _free(void *address, const char *file, int line);
void *_realloc(void * oldBuffer, size_t newSize, const char *file, int line);
void *_malloc(size_t size, const char *file, int line);
#ifdef __cplusplus
}
#endif

#define free(x) _free(x, __FILE__, __LINE__)
#define malloc(x) _malloc(x, __FILE__, __LINE__)
#define realloc(x, y) _realloc(x, y, __FILE__, __LINE__)


