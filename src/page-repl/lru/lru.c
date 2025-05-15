#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./lru.h"


int lru(int* pages, int numpages, int numframes)
{
	int *frames = (int*)malloc(numframes * sizeof(int));
	int *lru_trackings = (int*)malloc(numframes * sizeof(int));
	int pagefault = 0, clock = 0;
	
	for (int i=0; i<numframes; i++) frames[i] = -1;
	lru_display(frames, numframes, pagefault);
	

	int min_i, isin_i;
	for (int i=0; i<numpages; i++) 
	{	
		clock++;	

		//Update priority if found
		isin_i = lru_isIn(frames, numframes, pages[i]);
		if (isin_i >= 0) {lru_trackings[isin_i] = clock; continue;}
		
		//Occur page fault
		if (pagefault < numframes) {min_i = pagefault;}
		else { min_i = lru_min(lru_trackings, numframes);	}
		frames[min_i] = pages[i]; lru_trackings[min_i] = clock;
		
		pagefault++;
		printf("min_i: %d\n", min_i);
		lru_display(frames, numframes, pagefault);
	}
	

	return pagefault;
}

int lru_isIn(int* frames, int numframes, int page)
{
	for (int i=0; i<numframes; i++) if (frames[i] == page) return i;
	return -1; 
}

void lru_display(int* frames, int numframes, int pagefault)
{
	
	for (int i=0; i<numframes; i++)
		printf("%d ", frames[i]);
	printf("\n");
	printf("pagefault: %d\n", pagefault);
}


int lru_min(int *arr, int size)
{
	int min_i = 0;
	for (int i=0; i<size; i++) if (arr[i] < arr[min_i]) min_i = i;
	return min_i;
}
