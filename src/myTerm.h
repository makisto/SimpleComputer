#ifndef _MY_TERM_
#define _MY_TERM_

#include <sys/ioctl.h>
#include <unistd.h>

enum colors
{
    BLACK, 
    RED,  
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    LIGHT_BLUE,
    WHITE, 
    DEFAULT = 9
};

int mt_clrscr(void);
int mt_gotoXY(int row, int col);
int mt_getscreensize(int * rows, int * cols);
int mt_setfgcolor(enum colors color);
int mt_setbgcolor(enum colors color);

#endif
