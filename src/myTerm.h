#ifndef MY_TERMINAL
#define MY_TERMINAL

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
