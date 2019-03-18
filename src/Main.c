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
    CPUshow();
    flagShow();
    keysShow();
    mt_setfgcolor(DEFAULT); 
    mt_setbgcolor(DEFAULT);
    int row, col;
    mt_getscreensize(&row, &col);
    printf("Rows - %d\nCols - %d\n", row, col);
}
