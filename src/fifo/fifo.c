#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./fifo.h"


int fifo(int* pages, int numpages, int numframes)
{
	int *frames = (int*)malloc(numframes * sizeof(int));
	int hand = 0, pagefault = 0;
	bool is_in;
	
	for (int i=0; i<numframes; i++) frames[i] = -1;


	for (int i=0; i<numpages; i++)
	{
		
		//If already in memory, skip
		is_in = isIn(frames, numframes, pages[i]);
		if (is_in) continue;
		
		//Page fault
		pagefault++;
		frames[hand] = pages[i];
		hand++;
		hand = hand % numframes;
		
		display(frames, numframes, hand, pagefault);	
	}
	return pagefault;
}

static bool isIn(int* frames, int numframes, int page)
{
	for (int i=0; i<numframes; i++) if (frames[i] == page) return true;
	return false; 
}

static void display(int* frames, int numframes, int hand, int pagefault)
{
	
	for (int i=0; i<numframes; i++)
		printf("%d ", frames[i]);
	printf("\n");
	printf(" hand: %d\n", hand);
	printf("pagefault: %d\n\n", pagefault);
}
