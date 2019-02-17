#ifndef MYSIMPCOMP
#define MYSIMPCOMP

#define N 100
#define OUT_OF_ADDRESS -1
#define OUT_OF_FILE -2

int RAM[N];
int reg_flags;

int sc_memoryInit();
int sc_memoryShow();
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int * value);
int sc_memorySave (char * filename);
int sc_memoryLoad (char * filename);
int sc_regInit(void);
int sc_regSet(int register, int value);
int sc_regGet(int register, int * value);
int sc_commandEncode(int command, int operand, int * value);
int sc_commandDecode(int value, int * command, int * operand);

#endif


