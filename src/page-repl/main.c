#include <stdio.h>

#include "./lru/lru.h"
#include "./fifo/fifo.h"
#include "./clock/clock.h"

int main()
{
	int numpages = 20, numframes = 3;
	int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};


    //Test each algorithm
	printf("#####LRU: \n\n");
	lru(pages, numpages,  numframes);
	printf("\n#####FIFO: \n");
	fifo(pages, numpages,  numframes);
	printf("#####CLOCK: \n\n");
	clock(pages, numpages,  numframes);

}
