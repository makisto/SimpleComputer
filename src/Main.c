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
  
    sc_regSet(IMPULS, 1);

    int y, acc, inst, value;

    signal(SIGALRM, timer);
    signal(SIGUSR1, reset);

    settimer(&nval);

    while(key != QUIT)
    { 
        system("tput reset");
        console();
        if(sc_regGet(IMPULS, &value))
        {
            rk_readkey(&key);
	    switch(key)
	    {
                case SAVE:
		    sc_memorySave("memory.dat");
		    break;
		case LOAD:
		    sc_memoryLoad("memory.dat");
		    break;
		case F5:
		    scanf("%d", &acc);
		    accumulator = acc;
		    break;
		case F6:
	            scanf("%d", &inst);
		    inst_counter = inst;
	            break;
		case UP:
		    cursor -= 10;
                    if(cursor < 0)
                    {
                        cursor += N;
                    }
		    break;
		case DOWN:
		    cursor += 10;
                    if(cursor > N - 1)
                    {
                        cursor -= N;
                    }
		    break;
		case LEFT:
		    cursor--;
                    if(cursor < 0)
                    {
                        cursor = N - 1;
                    }
		    break;
		case RIGHT:
	            cursor++;
                    if(cursor > N - 1)
                    {
                        cursor = 0;
                    }
		    break;
                case RUN:
                    sc_regSet(IMPULS, 0);
                    cursor = 0;
                    break;
                case ENTER:
	            scanf("%d", &y);
                    sc_memorySet(cursor, y);
                    break;
                case STEP:
                    printf("Coming soon\n");
                    getchar();
                    break;
                case RESET:
                    raise(SIGUSR1);
                    break;
		default:
	            break;
	    } 
        }
        else
        {
            setitimer(ITIMER_REAL, &nval, NULL);
            pause();
        }
    }
    return 0;
}
