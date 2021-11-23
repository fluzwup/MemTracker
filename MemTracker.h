#ifndef MemTracker_h_included
#define MemTracker_h_included

#ifdef __cplusplus
extern "C" {
#endif

void *allocFunc(void *ptr, size_t size, const char *caller, int line);
void freeFunc(void *ptr);
void *reallocFunc(void *ptr, void *newptr, size_t size, const char *caller, int line);

#ifdef __cplusplus
}
#endif

#endif
