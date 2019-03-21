#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "mySimpleComputer.h"
#include "myTerm.h"
#include "myBigChars.h"
#include "printComp.h"

int main(void) 
{    
    system("tput reset");

    memoryShow();
    printBoxes();
    CPUshow();
    flagShow();
    keysShow();
    int plus[] = {4279769112, 404232447};
    //int minus[] = {4278190080, 255};
    int zero[] = {2172748287, 4286677377};
    /*int one[] = {1617721456, 1616928864};
    int two[] = {1617181720, 4282260536};
    int three[] = {541073948, 472006712};
    int four[] = {606348324, 538976316};
    int five[] = {470025276, 405020704};
    int six[] = {436347928, 405021222};
    int seven[] = {811614334, 33818748};
    int eight[] = {405021720, 405021720};
    int nine[] = {606348312, 405020728};*/
    bc_printbigchar(plus, 15, 5, RED, GREEN);
    //bc_printbigchar(minus, 15, 11, RED, GREEN);
    bc_printbigchar(zero, 15, 19, RED, GREEN);
    bc_printbigchar(zero, 15, 28, RED, GREEN);
    bc_printbigchar(zero, 15, 37, RED, GREEN);
    bc_printbigchar(zero, 15, 46, RED, GREEN);
    /*bc_printbigchar(one, 15, 28, RED, GREEN);
    bc_printbigchar(two, 15, 36, RED, GREEN);
    bc_printbigchar(three, 15, 45, RED, GREEN);
    bc_printbigchar(four, 15, 54, RED, GREEN);
    bc_printbigchar(five, 15, 63, RED, GREEN);
    bc_printbigchar(six, 15, 72, RED, GREEN);
    bc_printbigchar(seven, 15, 81, RED, GREEN);
    bc_printbigchar(eight, 15, 90, RED, GREEN);
    bc_printbigchar(nine, 15, 99, RED, GREEN);*/
    mt_gotoXY(24, 1);
}
