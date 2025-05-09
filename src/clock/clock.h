#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>

int clock(int* pages, int numpages, int numframes);
void display(int* frames, int numframes, int pagefault);
int isIn(int* frames, int numframes, int page);
void display_truths(bool* ref_bits, int numframes);

#endif