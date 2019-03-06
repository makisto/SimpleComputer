#include <stdio.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "printComp.h"

void memoryShow()
{
    mt_clrscr();
    mt_setfgcolor(GREEN); 
    mt_setbgcolor(RED); 
    for(int i = 0; i < N; i++)
    {
        if((i % 10 == 0) && (i >= 10))
        {
            mt_gotoXY((i / 10) + 1, 0);
        }
        printf("%d ", RAM[i]);
    }
}

void CPUshow()
{
    mt_setfgcolor(BLACK); 
    mt_setbgcolor(WHITE); 
    mt_gotoXY(1, 50);
    printf("accumulator");
    mt_gotoXY(2, 50);
    printf("%d", accumulator);
    mt_gotoXY(3, 50);
    printf("instructionCounter");
    mt_gotoXY(4, 50);
    printf("%d", inst_counter);
    mt_gotoXY(5, 50);
    printf("Operation");
    mt_gotoXY(6, 50);
    printf("%d", oper_res);
}

void flagShow()
{
    int fl;
    mt_setfgcolor(YELLOW); 
    mt_setbgcolor(PURPLE); 
    mt_gotoXY(7, 50);
    printf("Flags");
    mt_gotoXY(8, 50);
    if(sc_regGet(OVERFLOW, &fl) == 0)
    printf("O ");
    else printf(" ");
    if(sc_regGet(NULL_DEL, &fl) == 0)
    printf("N ");
    else printf(" ");
    if(sc_regGet(OUT_OF_MEMORY, &fl) == 0)
    printf("M ");
    else printf(" ");
    if(sc_regGet(IMPULS, &fl) == 0)
    printf("I ");
    else printf(" ");
    if(sc_regGet(WRONG_COMMAND, &fl) == 0)
    printf("C ");
    else printf(" ");
}

void keysShow()
{
    mt_setfgcolor(LIGHT_BLUE); 
    mt_setbgcolor(BLACK); 
    mt_gotoXY(9, 50);
    printf("Keys:");
    mt_gotoXY(10, 50);
    printf("l - load");
    mt_gotoXY(11, 50);
    printf("s - save");
    mt_gotoXY(12, 50);
    printf("r - run");
    mt_gotoXY(13, 50);
    printf("s - step");
    mt_gotoXY(14, 50);
    printf("i - reset");
    mt_gotoXY(15, 50);
    printf("f5 - accumulator");
    mt_gotoXY(16, 50);
    printf("f6 - instructionCounter");
    mt_gotoXY(17, 0);
}      
