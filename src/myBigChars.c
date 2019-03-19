#include <stdio.h>
#include <unistd.h>

#include "myBigChars.h"

int bc_printA (char * str)
{
    printf("\E(0%s\E(B", str);
    return 0;
}

int bc_box (int x1, int y1, int x2, int y2)
{
    mt_gotoXY(x1, y1);
    bc_printA("l");
    for (int i = (x1 + 1); i <= (x1 + y2); i++)
    {
        bc_printA("q");
    }
    bc_printA("k");
    mt_gotoXY(x1, y1);
    for (int i = (x1 + 1); i < (x1 + x2); i++) 
    {
        mt_gotoXY(i, y1 + y2 + 1);
	bc_printA("x");
	mt_gotoXY(i, y1);
	bc_printA("x");
    }
    mt_gotoXY(x1 + x2, y1);
    bc_printA("m");
    for (int i = (x1 + 1); i <= (x1 + y2); i++)
    { 
        bc_printA("q");
    }
    bc_printA("j");
    return 0;
}

int bc_printbigchar (int* big, int x, int y, enum colors fg_color, enum colors bg_color)
{
    int bit;
    int mas_position;
    mt_setfgcolor(fg_color);
    mt_setbgcolor(bg_color);
    mt_gotoXY(x, y);
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            mas_position = i >> 2;
            bit = (big[mas_position] >> ((i % 4) * 8 + j));
            if(bit == 0)
            {
                bc_printA(" ");
            }
            else if(bit == 1)
            {
                bc_printA("a"); 
            }  
        }
        mt_gotoXY(x + (i + 1), y);       
    }
    mt_setfgcolor(DEFAULT);
    mt_setbgcolor(DEFAULT);
    return 0;
}

int bc_setbigcharpos (int * big, int x, int y, int value)
{
    int mas_position;

    if(x <= 3)
    {
        mas_position = 0;
    }
    else if(x >= 4)
    {
        mas_position = 1;
    }
    
    x = x % 4;

    if (value == 1)
    {
       big[mas_position] = big[mas_position] | (1 << (x * 8 + y));
    }
    else if (value == 0)
    {
       big[mas_position] = big[mas_position] & (~(1 << (x * 8 + y)));
    }
    return 0;
}

int bc_getbigcharpos (int * big, int x, int y, int * value)
{
    int mas_position;

    if(x <= 3)
    {
        mas_position = 0;
    }
    else if(x >= 4)
    {
        mas_position = 1;
    }
    
    x = x % 4;

    *value = (big[mas_position] >> (x * 8 + y));
    return 0;
}

int bc_bigcharwrite (int fd, int * big, int count)
{
    write(fd, big, count * sizeof(int) * 2);
    close(fd);

    return 0;
}

int bc_bigcharread (int fd, int * big, int need_count, int * count)
{
    read(fd, big, need_count * (sizeof(int)) * 2);
    close(fd);

    return 0;
}
