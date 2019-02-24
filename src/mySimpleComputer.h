#ifndef MYSIMPCOMP
#define MYSIMPCOMP

#define N 100

#define REGISTR1  1
#define REGISTR2  2
#define REGISTR3  3
#define REGISTR4  4
#define REGISTR5  5
#define REGISTR6  6
#define REGISTR7  7
#define REGISTR8  8

#define OUT_OF_ADDRESS -1
#define OUT_OF_FILE -2
#define WRONG_REGISTR -3
#define OUT_OF_COMMAND -4
#define WRONG_COMMAND -5

int RAM[N];
int reg_flags;

int sc_memoryInit();
int sc_memoryShow();
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int * value);
int sc_memorySave (char * filename);
int sc_memoryLoad (char * filename);
int sc_regInit(void);
int sc_regSet(int registr, int value);
int sc_regGet(int registr, int * value);
int sc_commandEncode(int command, int operand, int * value);
int sc_commandDecode(int value, int * command, int * operand);

#endif


