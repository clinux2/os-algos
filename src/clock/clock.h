#ifndef CLOCK_H
#define CLOCK_H

int clock(int* pages, int numpages, int numframes);
static void display(int* frames, int numframes, int pagefault);
static int isIn(int* frames, int numframes, int page);

static void display_truths(bool* ref_bits, int numframes);

#endif