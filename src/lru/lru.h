#ifndef LRU_H
#define LRU_H

#include <stdbool.h>

int lru(int* pages, int numpages, int numframes);
void lru_display(int* frames, int numframes, int pagefault);
int lru_isIn(int* frames, int numframes, int page);
int lru_min(int *arr, int size);


#endif

