#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mySimpleComputer.h"
#include "printComp.h"

int translate(char * file, char * filename)
{
    int mem, com1, op1, i;
    int a;
    int value;
    char str[900];
    char sep[10] = " \n;";
    char * buf;
    char * istr;
    char buf2[9999][4];

    FILE * f = fopen("file.sa", "r+");
    if(f == NULL)
    {
        printf("ОШИБКА\n");
        return -1;
    }
    else
    {
        printf("ВЫПОЛНЕНО\n");
    }

    while(!feof(f))
    {
        buf = fgets(str, sizeof(str), f);       
        if(buf == NULL)
        {
            if(feof(f) != 0)
            {
                printf("СЧИТАЛИ\n");
                break;
            }
            else
            {
                printf("ОШИБКА ЧТЕНИЯ\n");
                break;
            }
        }

        istr = strtok(str, sep);
        i = 0;
        while(istr != NULL)
        {
            strncpy(buf2[i], istr, 10);
            istr = strtok(NULL, sep);
            switch(i)
            {
                case 0:
                    a = atoi(buf2[i]);
                    if((a < 0) || (a > 99))
                    {
                        printf("ОШИБКА ЧТЕНИЯ\n");
                        return -1;
                    }
                    mem = a;
                    printf("1 компонент - %s\n", buf2[i]);
                    break;
                case 1:
                    if(strcmp(buf2[i], "READ") == 0)
                    {
                        com1 = 0xA;
                    }
                    else if(strcmp(buf2[i], "WRITE") == 0)
                    {
                        com1 = 0xB;
                    } 
                    else if(strcmp(buf2[i], "LOAD") == 0)
                    {
                        com1 = 0x14;
                    }
                    else if(strcmp(buf2[i], "STORE") == 0)
                    {
                        com1 = 0x15;
                    }
                    else if(strcmp(buf2[i], "ADD") == 0)
                    {
                        com1 = 0x1E;
                    }
                    else if(strcmp(buf2[i], "SUB") == 0)
                    {
                        com1 = 0x1F;
                    }
                    else if(strcmp(buf2[i], "DIVIDE") == 0)
                    {
                        com1 = 0x20;
                    }
                    else if(strcmp(buf2[i], "MUL") == 0)
                    {
                        com1 = 0x21;
                    }
                    else if(strcmp(buf2[i], "JUMP") == 0)
                    {
                        com1 = 0x28;
                    }
                    else if(strcmp(buf2[i], "JNEG") == 0)
                    {
                        com1 = 0x29;
                    }
                    else if(strcmp(buf2[i], "JZ") == 0)
                    {
                        com1 = 0x2A;
                    }
                    else if(strcmp(buf2[i], "HALT") == 0)
                    {
                        com1 = 0x2B;
                    }
                    else if(strcmp(buf2[i], "NEG") == 0)
                    {
                        com1 = 0x40;
                    }
                    else if(strcmp(buf2[i], "=") == 0)
                    {
                        com1 = 0;
                    }
                    else
                    {
                        return -1;
                    }
                    printf("2 компонент - %s\n", buf2[i]);
                    break;
                case 2:
                    a = atoi(buf2[i]);
                    if(com1 == 0)
                    {
                        if((a < 0) || (a > 0x7FFF))
                        {
                            printf("ОШИБКА ЧТЕНИЯ\n");
                            return -1;
                        }
                        else
                        {
                            op1 = a;
                        }
                    }
                    else
                    {
                        op1 = a;
                    }
                    printf("3 компонент - %s\n", buf2[i]);
                    break;
            }
            i++;
        }
        if(com1 == 0)
        {
            sc_memorySet(mem, op1);
        }
        else
        {
            sc_commandEncode(com1, op1, &value);
            sc_memorySet(mem, value);
        }
    }
    fclose(f);
    sc_memorySave(filename);

    return 0;  
}
