#include <stdlib.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "myReadkey.h"
#include "printComp.h"

int main(void) 
{    
    system("tput reset");

    sc_memoryInit();
    sc_regInit();
    

    sc_memorySet(0, 0xABC);
    sc_memorySet(99, 0xDEF);
    sc_memorySet(45, 0x123);
    sc_memorySet(72, 0x456);
    sc_memorySet(14, 0x789);
  
    enum keys key;
    key = NONE;
    cursor = 0;
    int y, acc, inst;

    printBoxes();
    keysShow();
    flagShow();
    CPUshow();
    memoryShow();
    printBigChars();

    while(key != QUIT)
    {
        mt_gotoXY(25, 1);
        rk_readkey(&key);
        switch(key)
        {
            case SAVE:
                sc_memorySave("memory.dat");
        	break;
            case LOAD:
        	sc_memoryLoad("memory.dat");
                memoryShow();
        	break;
            case F5:
        	printf("Введите значение аккумулятора\n");
        	scanf("%d", &acc);
        	accumulator = acc;
                CPUshow();
        	break;
            case F6:
        	printf("Введите значение счётчика\n");
        	scanf("%d", &inst);
        	inst_counter = inst;
                CPUshow();
        	break;
            case RUN:
		printf("Введите значение");
		scanf("%d", &y);
		sc_memorySet(inst_counter, y);
                memoryShow();	
                break;
            case RESET:
        	sc_memoryInit();
        	sc_regInit();
        	accumulator = 0;
        	inst_counter = 0;
                flagShow();
                CPUshow();
                memoryShow();
                printBigChars();
        	break;
            case UP:
		cursor -= 10;
                CPUshow();
                memoryShow();
                printBigChars();
                break;
            case DOWN:
		cursor += 10;
                CPUshow();
                memoryShow();
                printBigChars();
                break;
            case LEFT:
		cursor--;
                CPUshow();
                memoryShow();
                printBigChars();
                break;
	    case RIGHT:
		cursor++;
                CPUshow();
                memoryShow();
                printBigChars();
                break;
            default:
        	break;
        }
    }
}
