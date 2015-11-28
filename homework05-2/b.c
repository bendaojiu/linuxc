#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


int main(int arg, char *args[])
{
	printf("b again\n");
	if (args[1] == NULL)
	{
		printf("进程a没有传入数据\n");
		return -1;
	}
	int fd = atoi(args[1]);
	if (fd == 0)
	{
		printf("进程a传入数据错误\n");
		return -1;
	}
	
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	
	read(fd, buf, sizeof(buf));
	
	printf("%s", buf);
	close(fd);
	printf("b end\n");
	return 0;
}
