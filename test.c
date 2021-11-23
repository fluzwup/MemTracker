#include "tracker.h"


int main(int argc, char **argv)
{
	void *p = malloc(1000);
	free(p);
	p = malloc(1000);
	p = realloc(p, 2000);
	free(p);
	p = malloc(100);
}
