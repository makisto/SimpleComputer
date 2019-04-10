#include "myReadkey.h"
#include "printComp.h"

int rk_readkey (enum keys * key)
{
	char buf;
	
	read(1, &buf, 1);
	switch(buf)
	{
		case 'q':
			*key = QUIT;
			break;
		case 'l':
			*key = LOAD;
			break;
		case 's':
			*key = SAVE;
			break;
		case 'r':
			*key = RUN;
			break;
		case 'i':
			*key = RESET;
			break;
		case 'z':
			*key = CANON;
			break;
		case 'x':
			*key = UNCANON;
			break;
		case '\E':
			read(1, &buf, 1);
			read(1, &buf, 1);
			switch(buf)
			{
				case 'A':
					*key = UP;
					break;
				case 'B':
					*key = DOWN;
					break;
				case 'C':
					*key = RIGHT;
					break;
				case 'D':
					*key = LEFT;
					break;
				case '1':
					read(1, &buf, 1);
					switch(buf)
					{
						case '5':
							*key = F5;
							break;
						case '7':
							*key = F6;
							break;
						default:
							*key = NONE;
							break;
					}
				default:
					*key = NONE;
					break;
		    }
		default:
            *key = NONE;
			break;			
	}
		
    return 0;
}

int rk_mytermsave (void)
{
	struct termios terminal;
	FILE * term;
	
	if(tcgetattr(1, &terminal) != 0)
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
		if(tcsetattr(1, TCSAFLUSH, &terminal) != 0)
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

int rk_mytermregime (int regime, int vtime, int vmin, int echo, int
sigint)
{
	struct termios terminal;
	if((regime > 1) || (regime < 0) || (echo > 1) || (echo < 0) || (sigint > 1) || (sigint < 0))
	{
		return -1;
	}
	if(tcgetattr(1, &terminal) < 0)
	{
		return -1;
	}
	
	if(regime == 1)
	{
		terminal.c_lflag |= ICANON;
	}
	else if(regime == 0)
	{
		terminal.c_lflag &= ~ICANON;
		
		terminal.c_cc[VTIME] = vtime;
		terminal.c_cc[VMIN] = vmin;
		
		if(echo == 1)
		{
			terminal.c_lflag |= ECHO;
		}
		else if(echo == 0)
		{
		    terminal.c_lflag &= ~ECHO;	
		}
		if(sigint == 1)
		{
			terminal.c_lflag |= ISIG;
		}
		else if(sigint == 0)
		{
			terminal.c_lflag &= ~ISIG;
		}
	}
	
    return 0;
}
