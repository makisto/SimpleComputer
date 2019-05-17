#include "mySimpleComputer.h"
#include "myTerm.h"
#include "printComp.h"
#include "curs.h"

int alu(int command, int operand)
{
    int value;

    sc_memoryGet(operand, &value);
    switch(command)
    {
        case 0x1E:
            //printf("ADD\n");
            if((0x7FFF - accumulator) < value)
            {
                sc_regSet(OVERFLOW, 1);
                sc_regSet(IMPULS, 1);
                cursor = inst_counter = 0;
                break;
            }
            else
            {
                accumulator += value;
                inst_counter++;
            }
            break;
        case 0x1F:
            //printf("SUB\n");
            accumulator -= value;
            inst_counter++;
            break;
        case 0x20:
            //printf("DIVIDE\n");
            if(value == 0)
            {
                sc_regSet(NULL_DEL, 1);
                sc_regSet(IMPULS, 1);
                cursor = inst_counter = 0;
                break;
            }
            else
            {
                accumulator /= value;
                inst_counter++;
            }
            break;
        case 0x21:
            //printf("MUL\n");
            if((0x777F / accumulator) < value)
            {
                sc_regSet(OVERFLOW, 1);
                sc_regSet(IMPULS, 1);
                cursor = inst_counter = 0;
                break;
            }
            else
            {
                accumulator *= value;
                inst_counter++;
            }
            break;
    }
    return 0;
}

int cu()
{
    int value = 0;
    int result;

    sc_memoryGet(inst_counter, &value);
    result = sc_commandDecode(value, &com, &op);

    if(result != 0)
    {    
        sc_regSet(WRONG_COMMAND, 1);
        return -1; 
    }
    else
    {
        if((com == 0x1E) || (com == 0x1F) || (com == 0x20) || (com == 0x21))
        {
            alu(com, op);
        }
        else
        {
            switch(com)
            {
                int x, y;
                case 0xA:
                    //printf("READ\n");
                    printf("Введите значениe\n");
	            scanf("%d", &y);
                    if(y > 0x7FFF)
                    {
                        sc_regSet(OVERFLOW, 1);
                        sc_regSet(IMPULS, 1);
                        cursor = inst_counter = 0;
                    }
                    else
                    {
                        sc_memorySet(op, y);
                        inst_counter++;
                    }
                    break;
                case 0xB:
                    //printf("WRITE\n");
                    sc_memoryGet(op, &y);
                    printf("\n%d", y);
                    inst_counter++;
                    break;
                case 0x14:
                    //printf("LOAD\n");
                    sc_memoryGet(op, &y);
                    accumulator = y;
                    inst_counter++;
                    break;
                case 0x15: 
                    //printf("STORE\n");
                    sc_memorySet(op, accumulator);
                    inst_counter++;
                    break;
                case 0x28:
                    //printf("JUMP\n");
                    inst_counter = op;
                    break;
                case 0x29:
                    //printf("JNEG\n");
                    if(accumulator < 0)
                    {
                        inst_counter = op;
                    }
                    else
                    {
                        inst_counter++;
                    }
                    break;
                case 0x2A:
                    //printf("JZ\n");
                    if(accumulator == 0)
                    {
                        inst_counter = op;
                    }
                    else
                    {
                        inst_counter++;
                    }
                    break;
                case 0x2B:
                    //printf("HALT\n");
                    sc_regSet(IMPULS, 1);
                    cursor = inst_counter = 0;
                    break;
                case 0x40:
                    //printf("NEG\n"); //for me
                    sc_memoryGet(op, &y);
                    accumulator = 0 - y;
                    inst_counter++;
                    break;
                case 0x42:
                    //printf("SUBC\n");  //for Darya
                    sc_memoryGet(op, &x);
                    sc_memoryGet(accumulator, &y);
                    accumulator = (x - y);
                    inst_counter++;
                    break;
                case 0x47:
                    //printf("SUBC\n");  //for Andrew
                    sc_memoryGet(op, &x);
                    sc_memorySet(accumulator, x);
                    inst_counter++;
                    break;
            }
        }

        return 0;
    }
}

