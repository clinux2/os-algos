#ifndef FIFO_H
#define FIFO_H

#include <stdbool.h>

int fifo(int* pages, int numpages, int numframes);
int fifo_isIn(int* frames, int numframes, int page);
void fifo_display(int* frames, int numframes, int hand, int pagefault);


#endif