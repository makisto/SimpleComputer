#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "translator.h"

int basic(char * file)
{
    int i;
    int a;
    char str[50];
    char sep[10] = " \n";
    char * buf;
    char * istr;
    char buf2[9999][4];

    FILE * f;
    FILE * f1;

    f = fopen(file, "r");
    f1 = fopen("file123.sa", "w+");
    
    if((f == NULL) || (f1 == NULL))
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
                    printf("%d ", a);
                    fprintf(f1, "%s ", buf2[i]);
                    break;
                case 1:
                    if(strcmp(buf2[i], "INPUT") == 0)
                    {
                        strncpy(buf2[i], "READ", 5);
                        printf("%s ", buf2[i]);
                        fprintf(f1, "%s ", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "OUTPUT") == 0)
                    {
                        strncpy(buf2[i], "WRITE", 6);
                        printf("%s ", buf2[i]);
                        fprintf(f1, "%s ", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "END") == 0)
                    {
                        strncpy(buf2[i], "HALT", 5);
                        printf("%s ", buf2[i]);
                        fprintf(f1, "%s ", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "GOTO") == 0)
                    {
                        strncpy(buf2[i], "JUMP", 5);
                        printf("%s ", buf2[i]);
                        fprintf(f1, "%s ", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "LET") == 0)
                    {
                        strncpy(buf2[i], "JNEG", 5);
                        printf("%s ", buf2[i]);
                        fprintf(f1, "%s ", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "IF") == 0)
                    {
                        strncpy(buf2[i], "JZ", 5);
                        printf("%s ", buf2[i]);
                        fprintf(f1, "%s ", buf2[i]);
                    }
                    else
                    {
                        return -1;
                    }
                    break;
                case 2:
                    if(strcmp(buf2[i], "A") == 0)
                    {
                        strncpy(buf2[i], "65", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "B") == 0)
                    {
                        strncpy(buf2[i], "66", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "C") == 0)
                    {
                        strncpy(buf2[i], "67", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "D") == 0)
                    {
                        strncpy(buf2[i], "68", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "E") == 0)
                    {
                        strncpy(buf2[i], "69", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "F") == 0)
                    {
                        strncpy(buf2[i], "70", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "G") == 0)
                    {
                        strncpy(buf2[i], "71", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "H") == 0)
                    {
                        strncpy(buf2[i], "72", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "I") == 0)
                    {
                        strncpy(buf2[i], "73", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "J") == 0)
                    {
                        strncpy(buf2[i], "74", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "K") == 0)
                    {
                        strncpy(buf2[i], "75", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "L") == 0)
                    {
                        strncpy(buf2[i], "76", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "M") == 0)
                    {
                        strncpy(buf2[i], "77", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "N") == 0)
                    {
                        strncpy(buf2[i], "78", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "O") == 0)
                    {
                        strncpy(buf2[i], "79", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "P") == 0)
                    {
                        strncpy(buf2[i], "80", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "Q") == 0)
                    {
                        strncpy(buf2[i], "81", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "R") == 0)
                    {
                        strncpy(buf2[i], "82", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "S") == 0)
                    {
                        strncpy(buf2[i], "83", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "T") == 0)
                    {
                        strncpy(buf2[i], "84", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "U") == 0)
                    {
                        strncpy(buf2[i], "85", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "V") == 0)
                    {
                        strncpy(buf2[i], "86", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "W") == 0)
                    {
                        strncpy(buf2[i], "87", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "X") == 0)
                    {
                        strncpy(buf2[i], "88", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "Y") == 0)
                    {
                        strncpy(buf2[i], "89", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else if(strcmp(buf2[i], "Z") == 0)
                    {
                        strncpy(buf2[i], "90", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    else
                    {
                        a = atoi(buf2[i]);
                        printf("%d", a);
                        fprintf(f1, "%s", buf2[i]);
                    }
                    break;
                case 3:
                    if(strcmp(buf2[i], "REM") == 0)
                    {
                        strncpy(buf2[i], ";", 5);
                        printf("%s", buf2[i]);
                        fprintf(f1, "%s ", buf2[i]);
                    }
                    break;
                    if(strcmp(buf2[2], " ") == 0)
                    {
                        break;
                    }
                    break;
            }
            i++;
        }
        printf("\n");
        fprintf(f1, "\n");
    }
    fclose(f);
    fclose(f1);

    translate("file123.sa");

    return 0;  
}
