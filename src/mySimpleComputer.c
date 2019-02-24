#include <stdio.h>
#include "mySimpleComputer.h"

#define commands 12
int mas_commands[] = {0x10, 0x11, 0x20, 0x21, 0x30, 0x31, 0x32, 0x33, 0x40, 0x41, 0x42, 0x43};

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
        printf("Out of Memory\n");
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
        printf("Out of Address\n");
        return OUT_OF_ADDRESS;
    }
}

int sc_memorySave (char * filename)
{
    FILE* f = fopen(filename, "wb+");
    if(f == NULL)
    {
        printf("Cannot open file\n");   
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
        printf("Cannot open file\n");  
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
    if ( (registr >= 1) || (registr <= 8))
    {
         if (value == 1)
         {
            reg_flags = reg_flags | (1 << (registr - 1));
         }
         else if (value == 0)
         {
             reg_flags = reg_flags & (~(1 << (registr - 1)));
         }
		 return 0;
    }
    else
	{
        printf("Mistake\n");
        return WRONG_REGISTR;
    }
}

int sc_regGet (int registr, int * value)
{
    if ( (registr >= 1) || (registr <=8))
    { 
        registr = (reg_flags >> (registr - 1)) & 0x1;
        *value = registr;
        return 0;
    }
    else
    {
        printf("Mistake2\n");
        return WRONG_REGISTR;
    }
}

int sc_commandEncode(int command, int operand, int * value)
{
    int buf;

    for(int i = 0; i < commands; i++)
    {
        if(command == mas_commands[i])
        {
            buf = 1;
        }
    }

    if(buf == 1)
    {
        *value = (command << 7) | operand;
        return 0;
    }
    else
    {
        return OUT_OF_COMMAND;
    }
}

int sc_commandDecode(int value, int * command, int * operand)
{
    int buf;
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

        if(buf == 1)
        {
            *command = buf_command;
            *operand = buf_operand;
        }
        else if(buf == 0)
        {
            return OUT_OF_COMMAND;
        }
        return 0;
    }
    else
    {
        return WRONG_COMMAND;
    } 
}

