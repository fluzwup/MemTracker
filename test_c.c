#include "tracker.h"


int main(int argc, char **argv)
{
	int leak = 0;

	if(argc == 2 && 0 == strcmp(argv[1], "leak"))
		leak = -1;

	void *p = malloc(1000);
	free(p);
	p = malloc(1000);
	p = realloc(p, 2000);
	free(p);
	if(leak)
		p = malloc(100);

	return 0;
}
