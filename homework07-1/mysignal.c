#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int status = 1;//设置一个标志位，1为打印，0为不打印

void catch_Signal(int Sign)
{
	switch (Sign)
	{
		case SIGINT:
			if (status == 0)
				status = 1;
			else
				status = 0;
			break;
	}
}

int signal1(int signo, void (*func)(int))
{
	struct sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	return sigaction(signo, &act, &oact);
}

int main(int arg, char *args[])
{
	signal1(SIGINT, catch_Signal);
	while(1)
	{
		if (status)
		{
			printf("hello\n");
		}
		sleep(1);
	}
	return 0;
}
