#ifndef FIFO_H
#define FIFO_H

#include <stdbool.h>

int fifo(int* pages, int numpages, int numframes);
static bool isIn(int* frames, int numframes, int page);
static void display(int* frames, int numframes, int hand, int pagefault);


#endif