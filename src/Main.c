#include <stdio.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "printComp.h"

int main(void) 
{    
    /*int row, col;
    mt_clrscr();
 
    mt_gotoXY(11, 60);
    mt_getscreensize(&row, &col);
    mt_setfgcolor(GREEN); 
    mt_setbgcolor(RED); 
    printf("Rows - %dCols - %d\n", row, col);
    mt_gotoXY(15, 50);
    printf("Rows - %dCols - %d\n", row, col);
    mt_setfgcolor(DEFAULT); 
    mt_setbgcolor(DEFAULT); */

    memoryShow();
    CPUshow();
    flagShow();
    keysShow();
    mt_setfgcolor(DEFAULT); 
    mt_setbgcolor(DEFAULT);
}
