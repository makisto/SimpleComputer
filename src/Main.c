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
        mt_gotoXY(24, 1);
        scanf("%d", &x);
        rk_readkey(&key);
        /*switch(key) //Ќе провер€лось
        {
        	case SAVE:
        		sc_memorySave("memory.dat");
        		break;
        	case LOAD:
        		sc_memoryLoad("memory.dat");
        		break;
        	case F5:
        		printf("¬ведите значение аккумул€тора\n");
        		scanf("%d", &acc);
        		accumulator = acc;
        		break;
        	case F6:
        		printf("¬ведите значение счЄтчика команд\n");
        		scanf("%d", &inst);
        	    inst_counter = inst;
        		break;
        	case RUN:
        		printf("¬ведите номер €чейки\n");
        		scanf("%d", &x);
        		printf("¬ведите желаемое значение")ж
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
        if(KEY == SAVE)
        {
        	sc_memorySave("memory.dat");
		}
		if(KEY == LOAD)
		{
			sc_memoryLoad("memory,dat");
		}
		if(KEY == F5)
		{
			printf("¬ведите значение аккумул€тора\n");
        	scanf("%d", &acc);
        	accumulator = acc;
		}
		if(KEY == F6)
		{
		    printf("¬ведите значение счЄтчика команд\n");
        	scanf("%d", &inst);
        	inst_counter = inst;	
		}
		if(KEY == RUN)
		{
		    printf("¬ведите номер €чейки\n");
        	scanf("%d", &x);
        	printf("¬ведите желаемое значение")ж
        	scanf("%d", &y);
        	sc_memorySet(x, y);	
		}
        if(KEY == RESET)
        {
            sc_memoryInit();
        	sc_regInit();
        	accumulator = 0;
        	inst_counter = 0;	
		}
		if(KEY == CANON)
		{
			printf("CANON\n");
        	rk_mytermregime(1, 0, 0, 1, 1);
		}
		if(KEY == UNCANON)
		{
			printf("UNCANON\n");
        	rk_mytermregime(0, 1, 1, 0, 0);
		}		
    }
}
