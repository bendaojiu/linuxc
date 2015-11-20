/*
	编写一个孤儿进程，
	这个孤儿进程可以同时创建100个僵死进程。
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i = 0;
	pid_t pid;
	pid = fork();
	
	
	if (pid == 0)
	{
		for (i = 0; i < 100; i++)
		{
			pid_t pidtmp;
			pidtmp = fork();
		
			if (pidtmp == 0)
			{
				exit(0);
			}
		}
		pause();
	}
	else
	{
		exit(0);
	}
	return 0;
	
}
