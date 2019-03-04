#include <stdio.h>
#include "myTerm.h"

int mt_clrscr(void)
{
    return 0;
}

int mt_gotoXY(int row, int col)
{
    return 0;
}

int mt_getscreensize(int * rows, int * cols)
{
    return 0;
}

int mt_setfgcolor(enum colors color)
{
    printf("%d\n", color); //Проверка значений
    return 0;
}

int mt_setbgcolor(enum colors color)
{
    return 0;
}


