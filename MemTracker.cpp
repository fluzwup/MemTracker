
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class MemTracker
{
public:
	size_t size;
	void *address;
	int epoch;
	string epochName;
	string caller;
	int line;
	bool freed;
};

vector<MemTracker> trackList;
int blockCount = 0;
int epoch = 0;
string epochName = "None";

int StartEpoch(char *s)
{
	epochName = s;
	return ++epoch;
}

void PrintAllocatedBlockCount()
{
	int allocCount = 0;
	
	for(size_t j = 0; j < trackList.size(); ++j)
	{
		if(!trackList[j].freed)
			++allocCount;
	}
	printf("Total blocks:  %i; remaining allocated: %i\n", (int)trackList.size(), allocCount);

}

void ListAllocatedBlocks()
{
	int allocCount = 0;
	
	printf("All remaining allocated blocks\n");
	printf("size, address, epoch, name, caller\n");

	for(size_t j = 0; j < trackList.size(); ++j)
	{
		if(!trackList[j].freed)
		{
			++allocCount;
			printf("%10i, %10x, %10i, %s, %s:%i\n", (int)trackList[j].size,
				(size_t)trackList[j].address, trackList[j].epoch,
				trackList[j].epochName.c_str(), trackList[j].caller.c_str(), trackList[j].line);
		}
	}
	printf("Total blocks:  %i; remaining allocated: %i\n", (int)trackList.size(), allocCount);
}

void AtExitList(void)
{
	ListAllocatedBlocks();
}

extern "C" 
{
void *allocFunc(void *ptr, size_t size, const char *caller, int line)
{
	static bool firstCall = true;

	if(firstCall)
	{
		atexit(AtExitList);
		trackList.reserve(10000);
		firstCall = false;
	}
	
	MemTracker newBlock;
	newBlock.size = size;
	newBlock.address = ptr;
	newBlock.caller = caller;
	newBlock.line = line;
	newBlock.epoch = epoch;
	newBlock.epochName = epochName;
	newBlock.freed = false;

	int trackIndex = trackList.size();
	trackList.resize(trackIndex + 1);
	trackList[trackIndex++] = newBlock;

	++blockCount;

	return ptr;
}

void freeFunc(void *ptr)
{
	int index = -1;
	// find existing block so we know how much to copy
	for(size_t j = 0; j < trackList.size(); ++j)
	{
		if(!trackList[j].freed && (trackList[j].address == ptr))
		{
			index = j;
			break;
		}
	}

	if(index < 0)
	{
		printf("WARNING:  Could not find block %x to free\n", (size_t)ptr);
		return;
	}

	// mark block as freed
	trackList[index].freed = true;
}

void *reallocFunc(void *ptr, void *newptr, size_t size, const char *caller, int line)
{
	int index = -1;

	// find existing block so we know how much to copy
	for(size_t j = 0; j < trackList.size(); ++j)
	{
		if(!trackList[j].freed && trackList[j].address == ptr)
		{
			index = j;
			break;
		}
	}
	
	if(index < 0) 
	{
		printf("WARNING:  Could not find block %x to realloc\n", (size_t)ptr);
		return 0; 
	}
	
	// find size of smaller block--that's how much data to move
	size_t copySize = (size > trackList[index].size) ? 
		trackList[index].size : size; 

	// copy block
	memcpy(newptr, trackList[index].address, copySize);
	
	// free old block
	freeFunc(trackList[index].address);
	
	return newptr;
}
}
