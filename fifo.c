#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fifo(int* pages, int numpages, int* frames, int numframes);
void display(int* frames, int numframes);
int main()
{
	int numpages = 20, numframes = 3;
	int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	int frames[] = {-1, -1, -1};
	fifo(pages, numpages, frames, numframes);

}

int fifo(int* pages, int numpages, int* frames, int numframes)
{
	int cur_frame_i = 0;
	int num_pagefault = 0;
	bool isIn;
	for (int i=0; i<numpages; i++)
	{
		
		//Check if page fault
		isIn = false;
		for (int j = 0; j<numframes; j++) 
			if (frames[j] == pages[i]) {isIn = true; break;};	
		if (isIn) continue;
			
		num_pagefault++;
		frames[cur_frame_i] = pages[i];
		cur_frame_i++;
		cur_frame_i = cur_frame_i % numframes;
		
		display(frames, numframes);	
		printf(" hand: %d\n", cur_frame_i);
	}
	return num_pagefault;
}

void display(int* frames, int numframes)
{
	
	for (int i=0; i<numframes; i++)
		printf("%d ", frames[i]);
	printf("\n");
}
