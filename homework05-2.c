/*
	编写两个不同的可执行程序，名称分别为a和b，b为a的子进程。
	在a程序中调用open函数打开a.txt文件。
	在b程序不可以调用open或者fopen，只允许调用read函数来实现读取a.txt文件。
	（a程序中可以使用 fork与execve函数创建子进程）。

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int arg, char *args[])
{
	FILE *fp = NULL;
	if (arg < 2)
	{
		char filename[100];
		memset(filename, 0, sizeof(filename));
		printf("请输入打开文件名：");
		scanf("%s", &filename);
		fp = fopen(filename, "r");
		if (fp == NULL)
		{
			printf("打开文件出错，error is %s\n", strerror(errno));
			return 0;
		}
	}
	else
	{
		fp = fopen(args[1], "r");
		if (fp == NULL)
		{
			printf("打开文件出错，error is %s\n", strerror(errno));
			return 0;
		}
	}
	
	pid_t pid = fork();
	int status;
	if (pid == -1)
	{
		printf("call fork error\n");
		return -1;
	}
	if (pid == 0)
	{
		char buf[100];
		memset(buf, 0, sizeof(buf));
		fread(buf, sizeof(buf), 1, fp);
		printf("%s", buf);
		fclose(fp);
		return 0;
	}
	else
	{
		wait(&status);
		return 0;
	}
	return 0;
}
