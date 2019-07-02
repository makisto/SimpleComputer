#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "translator.h"

int count_value(char value)
{
    int val = 0;

    if(strcmp(&value, "A") == 0)
    {
        val = 68;
    }
    else if(strcmp(&value, "B") == 0)
    {
        val = 69;
    }
    else if(strcmp(&value, "C") == 0)
    {
        val = 70;
    }
    else if(strcmp(&value, "D") == 0)
    {
        val = 71;
    }
    else if(strcmp(&value, "E") == 0)
    {
        val = 72;
    }

    return val;
}


int basic(char * filename)
{
    char buf[20];
    char c;
    char symbol;
    int const_op;
    int goto_op;
    int as_mem = -1; 
    int bas_mem = -1;
    int end_flag = 1;
    int i = 0;
    int operand = 0;
    int n[100];
    int isIF = 0;
    int isMath = 0;

    FILE * file1 = fopen(filename, "rt");
    FILE * file2 = fopen("file123.sa", "wt");
    if((file1 == NULL) || (file2 == NULL))
    {
        return -1;
    }

    do
    {
        fscanf(file1, "%s", buf);
        if(!strcmp(buf, "IF"))
        {
            //printf("1\n");
            as_mem++;
            bas_mem++;
            n[bas_mem] = as_mem;
            as_mem += 2;
            //printf("%d - %d - %d\n", bas_mem, n[bas_mem], as_mem);
            isIF = 1;
	}
	else if(!strcmp(buf, "INPUT"))
	{
            //printf("2\n");
            as_mem++;
            bas_mem++;
            n[bas_mem] = as_mem;
            //printf("%d - %d - %d\n", bas_mem, n[bas_mem], as_mem);
	}
	else if(!strcmp(buf, "OUTPUT"))
	{
            //printf("3\n");
            as_mem++;
            bas_mem++;
            n[bas_mem] = as_mem;
            //printf("%d - %d - %d\n", bas_mem, n[bas_mem], as_mem);
	}
	else if(!strcmp(buf, "GOTO"))
	{	
            if(isIF == 1)
            {
                isIF = 0;
                continue;
            }
            else
            {
                //printf("4\n");
                as_mem++;
                bas_mem++;
                n[bas_mem] = as_mem;
                //printf("%d - %d - %d\n", bas_mem, n[bas_mem], as_mem);
            }
        }
        else if(!strcmp(buf, "LET"))
        {
            //printf("5\n");
            bas_mem++;
            fscanf(file1, " %c=", &symbol);
            const_op = fscanf(file1, "%d", &operand);
            if(const_op == 0)	
            {
                as_mem++;
                n[bas_mem] = as_mem;
                //as_mem += 2;
                fscanf(file1, "%s", buf);			
                i = 0;
                do
                {
                    if((buf[i] == '+') || (buf[i] == '-') || (buf[i] == '*') || (buf[i] == '/'))
                    {
                        as_mem += 2;
                        isMath = 1;
                    }
                    i++;
                }while(buf[i] != '\0');
                if(isMath == 0)
                {
                    as_mem++;
                }
            }
            else 
            {
                n[bas_mem] = count_value(symbol);          
            }
            isMath = 0;	
            //printf("%d - %d - %d\n", bas_mem, n[bas_mem], as_mem);	  
	}
        else if(!strcmp(buf, "REM"))
        {
            //printf("6\n");
            continue;
        }	
	else if(!strcmp(buf, "END"))
	{
            //printf("7\n");
            bas_mem++;
            as_mem++;
            n[bas_mem] = as_mem;
            end_flag = 0;
            //printf("%d - %d - %d\n", bas_mem, n[bas_mem], as_mem);
        }
    }while(end_flag);

    fseek(file1, 0, SEEK_SET);

    as_mem = -1; 
    end_flag = 1; 
 
    do
    {	
        fscanf(file1, "%s", buf);
        if (!strcmp(buf, "IF"))
        {
            fscanf(file1, " %c%c", &c, &symbol);
            switch(symbol)
            {
                case '<': 
                    const_op = fscanf(file1, "%d", &operand);
                    if(const_op == 0)
                    {
                        fscanf(file1, "%c", &symbol);
                        fscanf(file1, " GOTO %d", &goto_op);
                        as_mem++;
                        fprintf(file2, "%d LOAD %d\n", as_mem, count_value(c));
                        as_mem++;
                        fprintf(file2, "%d SUB %d\n", as_mem, count_value(symbol));
                        as_mem++;
                        fprintf(file2, "%d JNEG %d\n", as_mem, n[goto_op / 10]);
                    }
                    else
                    {
                        fscanf(file1, " GOTO %d", &goto_op);
                        fprintf(file2, "%d = %d\n", 90, operand);
                        as_mem++;
                        fprintf(file2, "%d LOAD %d\n", as_mem, count_value(c));
                        as_mem++;
                        fprintf(file2, "%d SUB %d\n", as_mem, 90);
                        as_mem++;
                        fprintf(file2, "%d JNEG %d\n", as_mem, n[goto_op / 10]);
                    }
                    break;
                case '>':
                    const_op = fscanf(file1, "%d", &operand);
                    if(const_op == 0)
                    {
                        fscanf(file1, "%c", &symbol);
                        fscanf(file1, " GOTO %d", &goto_op);
                        as_mem++;
                        fprintf(file2, "%d LOAD %d\n", as_mem, count_value(symbol));
                        as_mem++;
                        fprintf(file2, "%d SUB %d\n", as_mem, count_value(c));
                        as_mem++;
                        fprintf(file2, "%d JNEG %d\n", as_mem, n[goto_op / 10]);
                    }
                    else
                    {
                        fscanf(file1, " GOTO %d", &goto_op);
                        fprintf(file2, "%d = %d\n", 90, operand);
                        as_mem++;
                        fprintf(file2, "%d LOAD %d\n", as_mem, 90);
                        as_mem++;
                        fprintf(file2, "%d SUB %d\n", as_mem, count_value(c));
                        as_mem++;
                        fprintf(file2, "%d JNEG %d\n", as_mem, n[goto_op / 10]);
                    }
                    break;
                case '=':
                    const_op = fscanf(file1, "%d", &operand);
                    if(const_op == 0)
                    {
                        fscanf(file1, "%c", &symbol);
                        fscanf(file1, " GOTO %d", &goto_op);
                        as_mem++;
                        fprintf(file2, "%d LOAD %d\n", as_mem, count_value(symbol));
                        as_mem++;
                        fprintf(file2, "%d SUB %d\n", as_mem, count_value(c));
                        as_mem++;
                        fprintf(file2, "%d JZ %d\n", as_mem, n[goto_op / 10]);
                    }
                    else
                    {
                        fscanf(file1, " GOTO %d", &goto_op);
                        fprintf(file2, "%d = %d\n", 90, operand);
                        as_mem++;
                        fprintf(file2, "%d LOAD %d\n", as_mem, count_value(c));
                        as_mem++;
                        fprintf(file2,"%d SUB %d\n", as_mem, 90);
                        as_mem++;
                        fprintf(file2, "%d JZ %d\n", as_mem, n[goto_op / 10]);
                    }
                    break;
            }
        }
        else if(!strcmp(buf, "INPUT"))
        {
            as_mem++;
            fscanf(file1, " %c", &c);
            fprintf(file2, "%d READ %d\n", as_mem, count_value(c));
        }
        else if(!strcmp(buf, "OUTPUT"))
        {
            as_mem++;
            fscanf(file1, " %c", &c);
            fprintf(file2, "%d WRITE %d\n", as_mem, count_value(c));
        }
        else if(!strcmp(buf, "GOTO"))
        {	
            as_mem++;
            fscanf(file1, "%d", &operand);
            fprintf(file2, "%d JUMP %d\n", as_mem, n[operand / 10]);
	}
        else if(!strcmp(buf, "LET"))
        {
            fscanf(file1, " %c=", &symbol);
            const_op = fscanf(file1, "%d", &operand);
            if(const_op == 0)	
            {
                fscanf(file1, "%s", buf);
                i = 0;			
                as_mem++;
                fprintf(file2, "%d LOAD %d\n", as_mem, count_value(buf[i]));
                do
                {
                    if(buf[i] == '+')
                    {
                        as_mem++;
                        fprintf(file2, "%d ADD %d\n", as_mem, count_value(buf[i + 1]));
                    }
                    if(buf[i] == '-')
                    {
                        as_mem++;
                        fprintf(file2, "%d SUB %d\n", as_mem, count_value(buf[i + 1]));
                    }
                    if(buf[i] == '*')
                    {
                        as_mem++;
                        fprintf(file2, "%d MUL %d\n", as_mem, count_value(buf[i + 1]));
                    }
                    if(buf[i] == '/')
                    {
                        as_mem++;
                        fprintf(file2, "%d DIVIDE %d\n", as_mem, count_value(buf[i + 1]));
                    }
                    i++;
                }while(buf[i] != '\0');
                as_mem++;
                fprintf(file2, "%d STORE %d\n", as_mem, count_value(symbol));	
            }
            else 
            {
                fprintf(file2, "%d = %d\n", count_value(symbol), operand);
            }
	}
        else if(!strcmp(buf, "REM"))
	{
            continue;
        }	
        else if(!strcmp(buf, "END"))
        {
            as_mem++;
            fprintf(file2, "%d HALT 00", as_mem);
            end_flag = 0;
        }
    }while(end_flag);

    fclose(file1);
    fclose(file2);

    translate("file123.sa");

    return 0;
}
