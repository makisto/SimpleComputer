#include "mySimpleComputer.h"
#include "myTerm.h"
#include "printComp.h"
#include "myBigChars.h"

void memoryShow()
{
    for(int i = 0; i < N; i++)
    {
        if(i == cursor)
        {
            mt_setbgcolor(GREEN);
            mt_setfgcolor(RED);
        }
        else
        {
            mt_setbgcolor(DEFAULT);
            mt_setfgcolor(DEFAULT);
        }
        if(i % 10 == 0)
        {
            mt_gotoXY((i / 10) + 3, 2);
        }
        printf("+%04X ", RAM[i]);
    }
}

void CPUshow()
{
    mt_gotoXY(2, 28);
    printf("Memory");
    mt_gotoXY(2, 70);
    printf("accumulator");
    mt_gotoXY(3, 70);
    printf("+%04X", accumulator);
    mt_gotoXY(5, 68);
    printf("instructionCounter");
    mt_gotoXY(6, 70);
    printf("+%04X", inst_counter);
    mt_gotoXY(8, 72);
    printf("Operation");
    mt_gotoXY(9, 70);
    printf("+00 : 00");
}

void flagShow()
{
    int fl;
    mt_gotoXY(11, 75);
    printf("Flags");
    mt_gotoXY(12, 71);
    if(sc_regGet(OVERFLOW, &fl))
    {
        printf("O ");
    }
    else 
    {
        printf(" ");
    }
    if(sc_regGet(OUT_OF_MEMORY, &fl))
    {
        printf("M ");
    }
    else 
    {
        printf(" ");
    }
    if(sc_regGet(NULL_DEL, &fl))
    {
        printf("N ");
    }
    else 
    {
        printf(" ");
    }
    if(sc_regGet(IMPULS, &fl))
    {
        printf("I ");
    }
    else 
    {
        printf(" ");
    }
    if(sc_regGet(WRONG_COMMAND, &fl))
    {
        printf("C");
    }
    else 
    {
        printf(" ");
    }
}

void keysShow()
{
    mt_gotoXY(14, 56);
    printf("Keys:");
    mt_gotoXY(15, 56);
    printf("l - load");
    mt_gotoXY(16, 56);
    printf("s - save");
    mt_gotoXY(17, 56);
    printf("r - run");
    mt_gotoXY(18, 56);
    printf("t - step");
    mt_gotoXY(19, 56);
    printf("i - reset");
    mt_gotoXY(20, 56);
    printf("f5 - accumulator");
    mt_gotoXY(21, 56);
    printf("f6 - instructionCounter");
} 

void printBoxes()
{
    bc_box(2, 1, 11, 60);  
    bc_box(2, 63, 2, 25);  
    bc_box(5, 63, 2, 25);
    bc_box(8, 63, 2, 25);
    bc_box(11, 63, 2, 25);
    bc_box(14, 1, 9, 52);
    bc_box(14, 55, 9, 33);
}    

void printBigChars()
{
    int value;
    int bigchar[2];
    char char_symbol[8];

    sc_memoryGet(inst_counter, &value);
    if(value >> 14)
    {
        sprintf(char_symbol, "-%04X", value);
    }
    else
    {
        sprintf(char_symbol, "+%04X", value);    
    }
    
    for(int i = 0; i < 5; i++)
    {
        bc_initbigchar(bigchar, char_symbol[i]);
        bc_printbigchar(bigchar, 15, 2 + (i * 9), RED, GREEN);
    }
}

void console()
{        
    printBoxes();
    keysShow();
    flagShow();
    CPUshow();
    memoryShow();
    printBigChars();
    printf("\nInput\\Output\n");
}

void settimer(struct itimerval * nval)
{
    nval->it_interval.tv_sec = 0;
    nval->it_interval.tv_usec = 0;
    nval->it_value.tv_sec = 0;
    nval->it_value.tv_usec = 155500;
}

void timer()
{
    console();
    inst_counter++;
    cursor = inst_counter;
    if (inst_counter == N) 
    {
        sc_regSet(IMPULS, 1);
        cursor = inst_counter = 0;
    }
}

void reset()
{
    sc_memoryInit();
    sc_regInit();
    sc_regSet(IMPULS, 1);
    cursor = inst_counter = accumulator = 0;
}
