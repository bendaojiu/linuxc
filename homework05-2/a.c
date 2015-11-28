#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int arg, char *args[])
{
	printf("a again\n");
	/*
	if (arg < 2)
	{
		printf("参数不够\n");
		return -1;
	}
	*/
	int fd = open("a.txt", O_RDONLY);//打开文件
	if (fd == -1)
	{
		printf("open failed %s\n", strerror(errno));
		return -1;
	}
	pid_t pid = fork();//创建一个自己的副本
	if (pid < 0)
	{
		printf("fork failed %s\n", strerror(errno));
		return -1;
	}
	if (pid > 0)//如果是父进程
	{
		close(fd);
	}
	if (pid == 0)//如果是子进程
	{
		char s[128];
		memset(s, 0, sizeof(s));
		sprintf(s, "%d", fd);
		char *args[] = {"b", s, NULL};
		if (execve("b", args, NULL) == -1)
		{
			printf("execve failed %s\n", strerror(errno));
			close(fd);
		}
		return 0;
	}
	printf("a end\n");
	return 0;
}
