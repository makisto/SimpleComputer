#define CTEST_MAIN

#include "mySimpleComputer.h"
#include "myTerm.h"
#include <ctest.h>

int operand = 0x50;
int command;

CTEST(adress, Correct)
{
    int result = sc_memorySet(34, 55);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(adress, Incorrect)
{
    int result = sc_memorySet(884, 55);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(value, Correct)
{
    int result = sc_memoryGet(34, &result);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(value, Incorrect)
{
    int result = sc_memoryGet(884, &result);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}  

CTEST(flag, Right)
{
    int result = sc_regSet(OVERFLOW, 1);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
} 

CTEST(flag, Wrong)
{
    int result = sc_regSet(OVERFLOW, 75);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
} 

CTEST(flag, Correct)
{
    int result = sc_regGet(OVERFLOW, &result);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
} 

CTEST(flag, Incorrect)
{
    int result = sc_regGet(11, &result);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(command, Correct)
{
    int result = sc_commandEncode(0xA, operand, &result);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(command, Incorrect)
{
    int result = sc_commandEncode(0x99, operand, &result);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(command, Right)
{
    int result = sc_commandDecode(2256, &command, &operand);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(command, Wrong)
{
    int result = sc_commandDecode(0xFFFF, &command, &operand);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(comm, Wrong)
{
    int result = sc_commandDecode(0x66, &command, &operand);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(GOTO, Incorrect)
{
    int result = mt_gotoXY(110, 110);
    int expected = -1;
    ASSERT_EQUAL(expected, result);   
}

CTEST(SetFrontColor, Correct)
{
    int result = mt_setfgcolor(DEFAULT);
    int expected = 0;
    ASSERT_EQUAL(expected, result);   
}

CTEST(SetFrontColor, Incorrect)
{
    int result = mt_setfgcolor(8);
    int expected = -1;
    ASSERT_EQUAL(expected, result);   
}

CTEST(SetBackColor, Correct)
{
    int result = mt_setfgcolor(DEFAULT);
    int expected = 0;
    ASSERT_EQUAL(expected, result);   
}

CTEST(SetBackColor, Incorrect)
{
    int result = mt_setbgcolor(8);
    int expected = -1;
    ASSERT_EQUAL(expected, result);   
}

int main(int argc, const char** argv) 
{
    int test_res = ctest_main(argc, argv);
    return test_res;
}
