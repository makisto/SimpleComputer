#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "myReadkey.h"
#include "curs.h"
#include "translator.h"
#include "printComp.h"

int main(void) 
{    	
    sc_memoryInit();
    sc_regInit();
  
    sc_regSet(IMPULS, 1);

    int x, y, z, acc, inst, value, code;
    char f; 
    char t;

    signal(SIGALRM, timer);
    signal(SIGUSR1, reset);

    settimer(&nval);

    while(key != QUIT)
    { 
        mt_clrscr();
        console();
        if(sc_regGet(IMPULS, &value))
        {
            rk_readkey(&key);
	    switch(key)
	    {
                case SAVE:
                    printf("Введите имя файла\n");
                    scanf("%s", &f);
		    sc_memorySave(&f);
		    break;
		case LOAD:
                    printf("Введите имя файла\n");
                    scanf("%s", &f);
		    sc_memoryLoad(&f);
		    break;
		case F5:
                    printf("Значение аккумулятора:\n");
		    scanf("%d", &acc);
                    if(acc > 0x7FFF)
                    {
                        sc_regSet(OVERFLOW, 1);
                    }
                    else
                    {
                        accumulator = acc;
                    }
		    break;
		case F6:
                    printf("Значение счётчика:\n");
	            scanf("%d", &inst);
                    if((inst < 0) || (inst > N - 1))
                    {
                        sc_regSet(OUT_OF_MEMORY, 1); 
                    }
                    else
                    {
                        sc_regSet(OUT_OF_MEMORY, 0); 
                        inst_counter = inst;
                    }
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
                    sc_regInit();
                    cursor = 0;
                    break;
                case ENTER:
                    printf("1 - Ручной ввод\n2 - Запуск транслятора\n");
                    scanf("%d", &z);
                    if(z == 1)
                    {
                        printf("Введите данные\n");
                        scanf("%d", &x);
	                scanf("%d", &y);
                        if(x == 0)
                        {
                            sc_memorySet(cursor, y);
                        }
                        else if(sc_commandEncode(x, y, &code) == 0)
                        {
                            sc_memorySet(cursor, code);
                        }
                    }
                    else if(z == 2)
                    {
                        printf("Введите имя транслируемого файла\n");
                        scanf("%s", &t);
                        translate(&t);
                    }
                    break;
                case STEP:
                    cu();
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
