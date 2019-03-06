#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "myTerm.h"

int mt_clrscr(void)
{
    printf("\033[H");  
    return 0;
}

int mt_gotoXY(int row, int col)
{
    printf("\033[%d;%dH", row, col); 
    return 0;
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
    printf("\033[3%dm", color); 
    return 0;
}

int mt_setbgcolor(enum colors color)
{
    printf("\033[4%dm", color);
    return 0;
}


