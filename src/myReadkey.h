#ifndef _MY_READKEY_
#define _MY_READKEY_

enum keys
{
    key1,
    key2
};

int rk_readkey (enum keys * key);
int rk_mytermsave (void);
int rk_mytermrestore (void);
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int
sigint);

#endif
