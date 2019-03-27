#include "myBigChars.h"
#include "printComp.h"

int bc_printA (char * str)
{
    printf("\E(0%s\E(B", str);
    return 0;
}

int bc_box (int x1, int y1, int x2, int y2)
{
    int row, col;

    mt_getscreensize(&row, &col);
    if((x1 <= 0) || (y1 <= 0) || (x1 >= row) || (y1 >= col))
    {
         return -1;
    }

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

int bc_printbigchar (int * big, int x, int y, enum colors fg_color, enum colors bg_color)
{
    int row, col;
    int bit;

    mt_getscreensize(&row, &col);
    if((x <= 0) || (y <= 0) || (x >= row) || (y >= col))
    {
         return -1;
    }

    mt_setfgcolor(fg_color);
    mt_setbgcolor(bg_color);

    mt_gotoXY(x, y);
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            bit = (big[i >> 2] >> ((i % 4) * 8 + j)) & 0x1;
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

int bc_initbigchar(int * big, char value)
{
    switch(value)
    {
        case '-':
            big[0] = 4278190080;
            big[1] = 255;
            break;

        case '+':
            big[0] = 4279769112;
            big[1] = 404232447;
            break;

        case '0':
            big[0] = 2172748287;
            big[1] = 4286677377;
            break;

        case '1':
            big[0] = 1617721456;
            big[1] = 1616928864;
            break;

	case '2':
            big[0] = 1617181720;
            big[1] = 4282260536;
            break;

	case '3':
            big[0] = 541073948;
            big[1] = 472006712;
            break;

	case '4':
            big[0] = 606348324;
            big[1] = 538976316;
            break;

	case '5':
            big[0] = 470025276;
            big[1] = 405020704;
            break;

	case '6':
            big[0] = 436347928;
            big[1] = 405021222;
            break;

	case '7':
            big[0] = 811614334;
            big[1] = 33818748;
            break;

	case '8':
            big[0] = 405021720;
            big[1] = 405021720;
            break;

	case '9':
            big[0] = 606348312;
            big[1] = 405020728;
            break;

        case 'A':
            big[0] = 0x3C24243C;
            big[1] = 0x24242424;
            break;

        case 'B':
            big[0] = 0xE12221E;
            big[1] = 0x1E22120E;
            break;

        case 'C':
            big[0] = 0x2022418;
            big[1] = 0x18240202;
            break;

        case 'D':
            big[0] = 0x2424140C;
            big[1] = 0xC142424;
            break;

        case 'E':
            big[0] = 0x7E027E7E;
            big[1] = 0x7E7E027E;
            break;

        case 'F':
            big[0] = 0x3C047C7C;
            big[1] = 0x404043C;
            break;

        default:
            break;
    }
    
    return 0;
}

int bc_setbigcharpos (int * big, int x, int y, int value)
{
    if((x < 0) || (x > 7) || (y < 0) || (y > 7))
    {
        return -1;
    }
    if (value == 1)
    {
       big[x / 4] = big[x / 4] | (1 << ((x % 4) * 8 + y));
    }
    else if (value == 0)
    {
       big[x / 4] = big[x / 4] & (~(1 << ((x % 4) * 8 + y)));
    }
    return 0;
}

int bc_getbigcharpos (int * big, int x, int y, int * value)
{
    if((x < 0) || (x > 7) || (y < 0) || (y > 7))
    {
        return -1;
    }

    *value = (big[x / 4] >> ((x % 4) * 8 + y)) & 0x1;
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
