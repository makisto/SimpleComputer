#include <stdio.h>
#include "mySimpleComputer.h"

int main(void) 
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m;
    int z = 50;

    sc_memoryInit();
    sc_memorySet (76, 8);
    sc_memorySet (4, 543634);
    sc_memorySet (765, 543634);
    sc_memorySet (26, 8657);
    sc_memoryShow();

    sc_memoryGet(4, &a);
    sc_memoryGet(76, &b);
    sc_memoryGet(26, &c);
    sc_memoryGet(990, &d);
    sc_memoryGet(99, &e);
    printf("Значения ячеек:\n%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e);

    sc_memorySave ("Comp.dat");
    sc_memoryInit();
    sc_memoryShow();
    sc_memoryLoad ("Comp.dat");
    sc_memoryShow();

    sc_regInit();
    sc_regSet(REGISTR1, 1);
    sc_regSet(REGISTR5, 0);
    sc_regSet(REGISTR4, 6);
    sc_regSet(9, 0);
    sc_regGet(REGISTR1, &f);
    sc_regGet(REGISTR5, &g);
    sc_regGet(REGISTR4, &h);
    sc_regGet(9, &m);
    printf("Значения флагов:\n%d\n%d\n%d\n%d\n", f, g, h, m);
    
    sc_commandEncode(70, z, &i);
    sc_commandEncode(11, z, &j);
    sc_commandEncode(67, z, &k);
    sc_commandEncode(43, z, &l);
    printf("Закодированная команда: \n%d\n%d\n%d\n%d\n", i, j, k, l);
    sc_commandDecode(i, &i, &z);
    sc_commandDecode(j, &j, &z);
    sc_commandDecode(k, &k, &z);
    sc_commandDecode(l, &l, &z);
    printf("Декодированная команда: \n%d\n%d\n%d\n%d\n", i, j, k, l);
    
}
