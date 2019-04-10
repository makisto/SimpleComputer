#ifndef _MY_READKEY_
#define _MY_READKEY_

#include <unistd.h>
#include <termios.h>

enum keys
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    LOAD,
    SAVE,
    RUN,
    STEP,
    RESET,
    F5,
    F6,
    QUIT,
    CANON,
    UNCANON,
    NONE
};

int rk_readkey (enum keys * key);
int rk_mytermsave (void);
int rk_mytermrestore (void);
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int
sigint);

#endif
