#include <stdio.h>
#include <stdlib.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "printComp.h"

int main(void) 
{    
    system("tput reset");
    memoryShow();
    printBoxes();
    CPUshow();
    flagShow();
    keysShow();
    int mas[] = {1, 1};
    bc_printbigchar(mas, 15, 2, GREEN, GREEN);
}
