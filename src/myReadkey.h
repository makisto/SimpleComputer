#ifndef _MY_READKEY_
#define _MY_READKEY_

#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include "myTerm.h"

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
    ENTER,
    NONE
}key;

int rk_readkey (enum keys * key);
int rk_mytermsave (void);
int rk_mytermrestore (void);
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int
sigint);

#endif
