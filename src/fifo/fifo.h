#ifndef FIFO_H
#define FIFO_H

#include <stdbool.h>

int fifo(int* pages, int numpages, int numframes);
inline int isIn(int* frames, int numframes, int page);
inline void display(int* frames, int numframes, int hand, int pagefault);


#endif