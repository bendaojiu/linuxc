#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>

//获取PID,网上找到的,用popen函数来执行shell命令
#define BUF_SIZE 1024
int pid_find()
{
	int pid = 0;
	FILE *fp = popen("ps -e | grep mysignal | awk \'{print $1}\'", "r");
	//打开管道，执行shell命令
	//不知道为什么这里必须用反转义符，直接用`不可以。。。。
	char buffer[10] = {0};
	pid = atoi(fgets(buffer, 10, fp));
	return pid;
}

int main(int arg, char *args[])
{
	
	int pid = pid_find();
	if (pid == 0)
	{
		printf("没有找到目标程序的pid\n");
		return 0;
	}
	printf("pid: %d\n", pid);
	kill(pid, SIGINT);
	return 0;
}
