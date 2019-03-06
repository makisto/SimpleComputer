#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "myTerm.h"

int mt_clrscr(void)
{
    printf("\E[H\E[2J");  
    return 0;
}

int mt_gotoXY(int row, int col)
{
    int x, y;

    mt_getscreensize(&x, &y);
    if((row >= 0) && (col >= 0) && (row <= x) && (col <= y))
    {
        printf("\E[%d;%dH", row, col); 
        return 0;
    }
    else
    {
        return -1;
    }
}

int mt_getscreensize(int * rows, int * cols)
{
    struct winsize ws;
    
    if(!ioctl(1, TIOCGWINSZ, &ws))
    {
        *rows = ws.ws_row;
        *cols = ws.ws_col;
        return 0;
    }
    else
    {
        return -1;
    }
}

int mt_setfgcolor(enum colors color)
{
    if((color >= 0 && color <= 7) || (color == 9))
    {
        printf("\E[3%dm", color); 
        return 0;
    }
    else
    {
        return -1;
    }    
}

int mt_setbgcolor(enum colors color)
{
    if((color >=0 && color <= 7) || (color == 9))
    {
        printf("\E[4%dm", color); 
        return 0;
    }
    else
    {
        return -1;
    }  
}


