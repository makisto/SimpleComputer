#include <stdio.h>
#include "mySimpleComputer.h"

#define commands 12
int mas_commands[] = {10, 11, 20, 21, 30, 31, 32, 33, 40, 41, 42, 43};

int sc_memoryInit()
{
    for(int i = 0; i < N; i++)
    {
        RAM[i] = 0;
    }
    return 0;
}

int sc_memoryShow()
{
    for(int i = 0; i < N; i++)
    {
        printf("%d ", RAM[i]);
    }
    printf("\n");
    return 0;
}

int sc_memorySet (int address, int value)
{
    if((address >= 0) && (address < N))
    {
        RAM[address] = value;
        return 0;
    }
    else
    {
        printf("OUT_OF_ADDRES\n");
        return OUT_OF_ADDRESS;
    }
}

int sc_memoryGet (int address, int * value)
{
    if((address >= 0) && (address < N))
    {
        *value = RAM[address];
        return 0;
    }
    else
    {
        printf("OUT_OF_ADDRES\n");
        return OUT_OF_ADDRESS;
    }
}

int sc_memorySave (char * filename)
{
    FILE* f = fopen(filename, "wb+");
    if(f == NULL)
    {
        printf("OUT_OF_FILE\n");   
        return OUT_OF_FILE;   
    }
    fwrite(RAM, sizeof(int), N, f);
    fclose(f);
    return 0;
}

int sc_memoryLoad (char * filename)
{
    FILE* f = fopen(filename, "rb+");
    if(f == NULL)
    {
        printf("OUT_OF_FILE\n");  
        return OUT_OF_FILE;    
    }
    fread(RAM, sizeof(int), N, f);
    fclose(f);
    return 0;
}

int sc_regInit(void)
{
    reg_flags = 0;
    return 0;
} 

int sc_regSet (int registr, int value)
{
    if ( (registr >= 1) && (registr <= 8))
    {
        if (value == 1)
        {
           reg_flags = reg_flags | (1 << (registr - 1));
           return 0;
        }
        else if (value == 0)
        {
           reg_flags = reg_flags & (~(1 << (registr - 1)));
           return 0;
        }
        else
        {
            printf("WRONG_VALUE\n");
            return WRONG_VALUE;
        }
    }
    else
    {
        printf("WRONG_REGISTR\n");
        return WRONG_REGISTR;
    }
}

int sc_regGet (int registr, int * value)
{
    if ( (registr >= 1) && (registr <= 8))
    { 
        *value = (reg_flags >> (registr - 1)) & 0x1;
        return 0;
    }
    else
    {
        printf("WRONG_REGISTR\n");
        return WRONG_REGISTR;
    }
}

int sc_commandEncode(int command, int operand, int * value)
{
    int buf = 0; 

    for(int i = 0; i < commands; i++)
    {
        if(command == mas_commands[i])
        {
            buf = 1;
        }
    }

    if((buf == 1) && ((operand >= 0) && (operand < N)))
    {
        *value = (command << 7) | operand;
        return 0;
    }
    else
    {
        printf("OUT_OF_COMMAND\n");
        return OUT_OF_COMMAND;
    }
}

int sc_commandDecode(int value, int * command, int * operand)
{
    int buf = 0;
    int attribute;
    int buf_command;
    int buf_operand;

    attribute = (value >> 14) & 1;
    if(attribute == 0)
    {
        buf_command = (value >> 7) & 0x7F;
        buf_operand = value & 0x7F;

        for(int i = 0; i < commands; i++)
        {
            if(buf_command == mas_commands[i])
            {
                buf = 1;
            }
        }

        if((buf == 1) && ((*operand >= 0) && (*operand < N))) 
        {
            *command = buf_command;
            *operand = buf_operand;
        }
        else if(buf == 0)
        {
            printf("OUT_OF_COMMAND\n");
            return OUT_OF_COMMAND;
        }
        return 0;
    }
    else
    {
        printf("WRONG_COMMAND\n");
        return WRONG_COMMAND;
    } 
}
