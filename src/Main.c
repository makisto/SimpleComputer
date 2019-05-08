#include <stdlib.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "myReadkey.h"
#include "printComp.h"

int main(void) 
{    	
    struct itimerval nval;

    sc_memoryInit();
    sc_regInit();
    
    sc_memorySet(0, 0xABC);
    sc_memorySet(99, 0xDEF);
    sc_memorySet(45, 0x123);
    sc_memorySet(72, 0x456);
    sc_memorySet(14, 0x789);
  
    sc_regSet(IMPULS, 1);

    enum keys key;
    key = NONE;
    cursor = 0;
    int y, acc, inst, value;

    signal(SIGALRM, timer);
    signal(SIGUSR1, reset);

    nval.it_interval.tv_sec = 2;
    nval.it_interval.tv_usec = 0;
    nval.it_value.tv_sec = 0;
    nval.it_value.tv_usec = 0;

    while(key != QUIT)
    { 
        system("tput reset");
        //mt_clrscr();
        console();
        rk_readkey(&key);
        if(sc_regGet(IMPULS, &value))
        {
	    switch(key)
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
		case UP:
		    cursor -= 10;
                    if(cursor < 0)
                    {
                        cursor += 100;
                    }
		    break;
		case DOWN:
		    cursor += 10;
                    if(cursor > 99)
                    {
                        cursor -= 100;
                    }
		    break;
		case LEFT:
		    cursor--;
                    if(cursor < 0)
                    {
                        cursor = 99;
                    }
		    break;
		case RIGHT:
	            cursor++;
                    if(cursor > 99)
                    {
                        cursor = 0;
                    }
		    break;
                case RUN:
	            sc_regSet(IMPULS, 0);
                    break;
                case STEP:
                    printf("Введите значение");
	            scanf("%d", &y);
                    sc_memorySet(inst_counter, y);
                    break;
                case RESET:
                    raise(SIGUSR1);
                    cursor = 0;
                    break;
		default:
	            break;
	    } 
        }
        else 
        {
            setitimer(ITIMER_REAL, &nval, 0);
            pause();
            timer(SIGALRM);
        }
    }
}
