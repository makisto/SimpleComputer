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
    int k = 0;
    char buf3[9999][5];
    int isIF = 0;
    int isOP = 0;
    int isJUMP = 0;

    FILE * f;
    FILE * f1;

    f = fopen("file.bas", "r");
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
                    printf("%d ", a + k);
                    fprintf(f1, "%d ", a + k);
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
                        if(isIF == 1)
                        {
                            printf("JNEG "); 
                            fprintf(f1, "JNEG "); 
                            isOP = 1; 
                        }
                        else
                        {  
                            strncpy(buf2[i], "JUMP", 5);
                            printf("%s ", buf2[i]);
                            fprintf(f1, "%s ", buf2[i]);
                            isJUMP = 1;
                        }
                    }
                    else if(strcmp(buf2[i], "LET") == 0)
                    {
                        int beg_op, mid_op, end_op;
                        int i1 = 0;
                        int operation;
                        strncpy(buf2[2], istr, 10);
                        for(int i = 0; buf2[2][i] != '\0'; i++)
                        {
                            strncpy(buf3[i], &buf2[2][i], 1);     
                            i1++;                 
                        }
                        for(int i = 0; i < i1; i++)
                        {
                            switch(i)
                            {  
                                case 0:
                                    if(strcmp(buf3[i], "C") == 0)
                                    {
                                        beg_op = 67;  
                                    }
                                    else if(strcmp(buf3[i], "D") == 0)
                                    {
                                        beg_op = 68;  
                                    }
                                    break;
                                case 2:
                                    if(strcmp(buf3[i], "A") == 0)
                                    {
                                        mid_op = 65;
                                        printf("LOAD %d\n", mid_op); 
                                        fprintf(f1, "LOAD %d\n", mid_op); 
                                        k++;
                                    }
                                    break;
                                case 3:
                                    if(strcmp(buf3[i], "+") == 0)
                                    {
                                        operation = 0;
                                    }
                                    if(strcmp(buf3[i], "-") == 0)
                                    {
                                        operation = 1;
                                    }
                                    if(strcmp(buf3[i], "/") == 0)
                                    {
                                        operation = 2;
                                    }
                                    if(strcmp(buf3[i], "*") == 0)
                                    {
                                        operation = 3;
                                    }
                                    break;
                                case 4:
                                    if(strcmp(buf3[i], "B") == 0)
                                    {
                                        end_op = 66;
                                    }
                                    switch(operation)
                                    {
                                        case 0:
                                            printf("%d ADD %d\n", a + k, end_op); 
                                            fprintf(f1, "%d ADD %d\n", a + k, end_op); 
                                            break; 
                                        case 1:
                                            printf("%d SUB %d\n", a + k, end_op);
                                            fprintf(f1, "%d SUB %d\n", a + k, end_op); 
                                            break;  
                                        case 2:
                                            printf("%d DIVIDE %d\n", a + k, end_op); 
                                            fprintf(f1, "%d DIVIDE %d\n", a + k, end_op); 
                                            break;
                                        case 3:
                                            printf("%d MUL %d\n", a + k, end_op); 
                                            fprintf(f1, "%d MUL %d\n", a + k, end_op); 
                                            break;
                                    } 
                                    k++;
                                    break;                              
                            }
                        }
                        printf("%d STORE %d", a + k, beg_op); 
                        fprintf(f1, "%d STORE %d", a + k, beg_op); 
                    }
                    else if(strcmp(buf2[i], "IF") == 0)
                    {
                        isIF = 1;
                        int first_op, second_op;
                        int i1 = 0;
                        strncpy(buf2[2], istr, 10);
                        for(int i = 0; buf2[2][i] != '\0'; i++)
                        {
                            strncpy(buf3[i], &buf2[2][i], 1);     
                            i1++;              
                        }
                        char temp;
                        strncpy(&temp, buf3[2], 1);
                        strncpy(buf3[2], buf3[1], 1);
                        strncpy(buf3[1], &temp, 1);
                        for(int i = 0; i < i1; i++)
                        {
                            switch(i)
                            {  
                                case 0:
                                    if(strcmp(buf3[i], "C") == 0)
                                    {
                                        first_op = 67;  
                                    }
                                    break;
                                case 1:
                                    if(strcmp(buf3[i], "D") == 0)
                                    {
                                        second_op = 68;
                                    }
                                    break; 
                                case 2:
                                    if(strcmp(buf3[i], "<") == 0)
                                    {
                                        printf("LOAD %d\n", second_op); 
                                        fprintf(f1, "LOAD %d\n", second_op); 
                                        k++;   
                                        printf("%d SUB %d", a + k, first_op); 
                                        fprintf(f1, "%d SUB %d", a + k, first_op); 
                                    }
                                    else if(strcmp(buf3[i], ">") == 0)
                                    {
                                       printf("LOAD %d\n", first_op); 
                                       fprintf(f1, "LOAD %d\n", first_op); 
                                       k++; 
                                       printf("%d SUB %d", a + k, second_op); 
                                       fprintf(f1, "%d SUB %d", a + k, second_op);   
                                    }
                                    break;                            
                            }
                        }
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
                    else if(isOP == 1 || isJUMP == 1)
                    {
                        a = atoi(buf2[i]);
                        if((a < 0) || (a > 99))
                        {
                            printf("ОШИБКА ЧТЕНИЯ\n");
                            return -1;
                        }
                        printf("%d", a + k);
                        fprintf(f1, "%d", a + k);
                        isIF = isOP = isJUMP = 0;
                    }
                    else if(strcmp(buf2[i], " ") == 0)
                    {
                        break;
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
