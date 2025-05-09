#ifndef LRU_H
#define LRU_H

#include <stdbool.h>

int lru(int* pages, int numpages, int numframes);
void display(int* frames, int numframes, int pagefault);
int isIn(int* frames, int numframes, int page);
int min(int *arr, int size);


#endif

