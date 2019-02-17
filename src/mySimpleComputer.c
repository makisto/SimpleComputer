#include <stdio.h>
#include "mySimpleComputer.h"

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
