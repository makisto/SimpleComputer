#include "myReadkey.h"
#include "printComp.h"
#include "myTerm.h"

int rk_readkey (enum keys * key)
{
    struct termios orig_options;
    char buf[16];

    if(tcgetattr(0, &orig_options) != 0)
    {
        return -1;
    }
    if(rk_mytermregime(0, 1, 1, 0, 0) != 0)
    {
        return -1;
    }

    read(0, buf, 15);

    if(buf[0] == 'q')
    {
        *key = QUIT;  
    }
    if(buf[0] == 'l')
    {
        *key = LOAD;  
    }
    if(buf[0] == 's')
    {
        *key = SAVE;  
    }
    if(buf[0] == 'r')
    {
        *key = RUN;  
    }
    if(buf[0] == 'i')
    {
        *key = RESET;  
    }
    if((buf[0] == '\033') && (buf[1] == '[') && (buf[2] == '1') && (buf[3] == '5'))
    {
        *key = F5;  
    }
    if((buf[0] == '\033') && (buf[1] == '[') && (buf[2] == '1') && (buf[3] == '7'))
    {
        *key = F6;  
    }
    if((buf[0] == '\033') && (buf[1] == '[') && (buf[2] == 'A'))
    {
        *key = UP;  
    }
    if((buf[0] == '\033') && (buf[1] == '[') && (buf[2] == 'B'))
    {
        *key = DOWN;  
    }
    if((buf[0] == '\033') && (buf[1] == '[') && (buf[2] == 'C'))
    {
        *key = RIGHT;  
    }
    if((buf[0] == '\033') && (buf[1] == '[') && (buf[2] == 'D'))
    {
        *key = LEFT;  
    }

    if(tcsetattr(0, TCSANOW, &orig_options) != 0)
    {
	return -1;
    }

    return 0;
}

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int
sigint)
{
    struct termios options;

    if(tcgetattr(0, &options) != 0)
    {
	return -1;
    }
	
    if(regime == 1)
    {
	options.c_lflag |= ICANON;
    }
    else if(regime == 0)
    {
	options.c_lflag &= ~ICANON;

	options.c_cc[VTIME] = vtime;
	options.c_cc[VMIN] = vmin;
		
	if(echo == 1)
	{
	    options.c_lflag |= ECHO;
	}
	else if(echo == 0)
	{
            options.c_lflag &= ~ECHO;	
	}
	if(sigint == 1)
	{
	    options.c_lflag |= ISIG;
	}
	else if(sigint == 0)
	{
	    options.c_lflag &= ~ISIG;
	}
    }
	
    if(tcsetattr(0, TCSANOW, &options) != 0)
    {
        return -1;
    }
    return 0;
}

int rk_mytermsave (void)
{
    struct termios terminal;
    FILE * term;
	
    if(tcgetattr(0, &terminal) != 0)
    {
	return -1;
    }
	
    if((term = fopen("term", "wb")) == NULL)
    {
	return -1;
    }
	
    fwrite(&terminal, sizeof(terminal), 1, term);
    fclose(term);
	
    return 0;
}

int rk_mytermrestore (void)
{
    struct termios terminal;
    FILE * term;
	
    if((term = fopen("term", "wb")) == NULL)
    {
	return -1;
    }
	
    if(fread(&terminal, sizeof(terminal), 1, term) > 0)
    {
	if(tcsetattr(0, TCSAFLUSH, &terminal) != 0)
	{
            return -1;
	}
	else
	{
            fclose(term);
	}
    }
	
    return 0;
}
