#include <stdio.h>
#include "mySimpleComputer.h"

int main(void) 
{
    sc_memoryInit();
    sc_memorySet (76, 8);
    sc_memorySet (4, 543634);
    sc_memorySet (765, 543634);
    sc_memorySet (26, 8657);
    sc_memoryShow();
    sc_memorySave ("Comp.dat");
    sc_memoryInit();
    sc_memoryShow();
    sc_memoryLoad ("Comp.dat");
    sc_memoryShow();
    sc_regInit();

}
