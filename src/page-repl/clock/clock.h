#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>

int clock(int* pages, int numpages, int numframes);
void clock_display(int* frames, int numframes, int pagefault);
int clock_isIn(int* frames, int numframes, int page);
void clock_display_truths(bool* ref_bits, int numframes);

#endif