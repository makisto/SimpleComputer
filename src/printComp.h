#ifndef _PRINT_COMP_
#define _PRINT_COMP_

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>

struct itimerval nval;
int accumulator;
int inst_counter;
int com;
int op;

void memoryShow();
void CPUshow();
void flagShow();
void keysShow();
void printBoxes();
void printBigChars();
void console();
void settimer(struct itimerval * nval);
void timer();
void reset();

#endif
