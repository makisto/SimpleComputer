#include <stdlib.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "myReadkey.h"
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

    enum keys key;
    key = NONE;
    cursor = 0;
    int x, y, acc, inst;
    while(key != QUIT)
    {
        system("tput reset");
        memoryShow();
        printBoxes();
        CPUshow();
        flagShow();
        keysShow();
        printBigChars();
        rk_readkey(&key);
        /*switch(key) //Не проверено
        {
        	case SAVE:
        		sc_memorySave("memory.dat");
        		break;
        	case LOAD:
        		sc_memoryLoad("memory.dat");
        		break;
        	case F5:
        		printf("Введите значение аккумулятора\n");
        		scanf("%d", &acc);
        		accumulator = acc;
        		break;
        	case F6:
        		printf("Введите значение счётчика\n");
        		scanf("%d", &inst);
        	    inst_counter = inst;
        		break;
        	case RUN:
				printf("Выберите ячейку памяти\n");
		    	scanf("%d", &x);
		    	printf("Введите значение");
		    	scanf("%d", &y);
		    	sc_memorySet(x, y);	
        		break;
        	case RESET:
        		sc_memoryInit();
        		sc_regInit();
        		accumulator = 0;
        		inst_counter = 0;
        		breakl
        	case CANON:
        		printf("CANON\n");
        		rk_mytermregime(1, 0, 0, 1, 1);
        		break;
        	case UNCANON:
        		printf("UNCANON\n");
        		rk_mytermregime(0, 1, 1, 0, 0);
        		break;
        	default:
        		break;
        }*/
        if(key == SAVE)
        {
        	sc_memorySave("memory.dat");
		}
		if(key == LOAD)
		{
			sc_memoryLoad("memory.dat");
		}
		if(key == F5)
		{
			printf("Введите значение аккумулятора\n");
        	scanf("%d", &acc);
        	accumulator = acc;
		}
		if(key == F6)
		{
		    printf("Введите значение счётчика\n");
        	scanf("%d", &inst);
        	inst_counter = inst;	
		}
		if(key == RUN)
		{
		    printf("Выберите ячейку памяти\n");
        	scanf("%d", &x);
        	printf("Введите значение\n");
        	scanf("%d", &y);
        	sc_memorySet(x, y);	
		}
        if(key == RESET)
        {
            sc_memoryInit();
        	sc_regInit();
        	accumulator = 0;
        	inst_counter = 0;	
		}
        if(key == UP)
        {
            cursor -= 10;
        }
        if(key == DOWN)
        {
            cursor += 10;
        }
        if(key == LEFT)
        {
            cursor--;
        }
        if(key == RIGHT)
        {
            cursor++;
        }	
    }
}
