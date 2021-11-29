#include "trackerpp.h"
#include <cstring>

int main(int argc, char **argv)
{
	bool leak = false;

	if(argc == 2 && 0 == strcmp(argv[1], "leak"))
		leak = true;

	void *p = malloc(1000);
	free(p);
	p = malloc(1000);
	p = realloc(p, 2000);
	free(p);
	if(leak) 
		p = malloc(100);

	unsigned char *blah = new unsigned char[1000];
	delete[] blah;
	if(leak)
		blah = new unsigned char[1000];
	
	return 0;
}
