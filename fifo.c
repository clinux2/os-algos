#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fifo(int* pages, int numpages, int* frames, int numframes);
bool isIn(int* frames, int numframes, int page);
void display(int* frames, int numframes, int hand, int pagefault);

int main()
{
	int numpages = 20, numframes = 3;
	int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	int frames[] = {-1, -1, -1};
	fifo(pages, numpages, frames, numframes);

}

int fifo(int* pages, int numpages, int* frames, int numframes)
{
	int hand = 0;
	int pagefault = 0;
	bool is_in;
	
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

bool isIn(int* frames, int numframes, int page)
{
	for (int i=0; i<numframes; i++) if (frames[i] == page) return true;
	return false; 
}

void display(int* frames, int numframes, int hand, int pagefault)
{
	
	for (int i=0; i<numframes; i++)
		printf("%d ", frames[i]);
	printf("\n");
	printf(" hand: %d\n", hand);
	printf("pagefault: %d\n\n", pagefault);
}
