#include "trackerpp.h"


int main(int argc, char **argv)
{
	void *p = malloc(1000);
	free(p);
	p = malloc(1000);
	p = realloc(p, 2000);
	free(p);
	p = malloc(100);


	unsigned char *blah = new unsigned char[1000];
	delete[] blah;
	blah = new unsigned char[1000];
}
