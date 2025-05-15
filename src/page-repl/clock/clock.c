#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./clock.h"

int clock(int* pages, int numpages, int numframes)
{
	int *frames = (int*)malloc(numframes * sizeof(int));
	bool *ref_bits = (bool*)malloc(numframes * sizeof(bool));
	int pagefault = 0, next_victim = 0;
	int isIn_i;
	
	for (int i=0; i<numframes; i++) {frames[i] = -1; ref_bits[i] = false;}	

	for (int i=0; i<numpages; i++) 
	{
		//Update ref bit if already in memory	
		isIn_i = clock_isIn(frames, numframes, pages[i]);	
		if (isIn_i >= 0) {ref_bits[isIn_i] = true;  continue;}
		
		//Page fault!!!
		pagefault++;
		while ( ref_bits[next_victim] == true)
		{
			ref_bits[next_victim] = false;
			next_victim++;
			next_victim = next_victim % numframes;
		}
		clock_display_truths(ref_bits, numframes);
		printf("frames: \n");
		frames[next_victim] = pages[i];	
		next_victim++;
		next_victim = next_victim % numframes;
		
		clock_display(frames, numframes, pagefault);
	}
	

	return pagefault;
}

int clock_isIn(int* frames, int numframes, int page)
{
	for (int i=0; i<numframes; i++) if (frames[i] == page) return i;
	return -1; 
}

void clock_display(int* frames, int numframes, int pagefault)
{
	for (int i=0; i<numframes; i++)
		printf("%d ", frames[i]);
	printf("\n");
	printf("pagefault: %d\n\n", pagefault);
	
}

void clock_display_truths(bool* ref_bits, int numframes)
{
	printf("ref_bits: \n");
	for (int i=0; i<numframes; i++)
		printf("%d ", ref_bits[i]);
	printf("\n");
}

