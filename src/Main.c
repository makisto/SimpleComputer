#include <stdlib.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "printComp.h"

int main(void) 
{    
    sc_memoryInit();
    sc_regInit();
    
    sc_memorySet(0, 0xABC);
    sc_memorySet(99, 0xDEF);
    sc_memorySet(45, 0x123);
    sc_memorySet(72, 0x456);
    sc_memorySet(14, 0x789);

    int x;
    while(x != 101)
    {
        system("tput reset");
        memoryShow();
        printBoxes();
        CPUshow();
        flagShow();
        keysShow();
        printBigChars();
        mt_gotoXY(24, 1);
        scanf("%d", &x);
        if((x > 99) || (x < 0))
        {
            sc_regSet(OUT_OF_MEMORY, 1);
        }
        else
        {
            sc_regSet(OUT_OF_MEMORY, 0);
        }
        inst_counter = x;
    }
}
