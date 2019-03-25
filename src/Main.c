#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "printComp.h"

int main(void) 
{    
    sc_regInit();
    int x;
    sc_memorySet(0, 0xABC);
    sc_memorySet(99, 0xDEF);
    sc_memorySet(45, 0x123);
    sc_memorySet(72, 0x456);
    sc_memorySet(14, 0x789);
    mt_gotoXY(25, 1);
    while(x != 101)
    {
        system("tput reset");
        memoryShow();
        printBoxes();
        CPUshow();
        flagShow();
        keysShow();
        printBigChars();
        scanf("%d", &x);
        inst_counter = x;
    }
}
