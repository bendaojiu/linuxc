#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>

void writelog(const char *log)
{
	time_t tDate;
	struct tm *eventTime;
	time(&tDate);//获取系统时间
	eventTime = localtime(&tDate);//将时间格式化为struct tm结构
	int iYear = eventTime->tm_year + 1900;
	int iMon = eventTime->tm_mon + 1;
	int iDay = eventTime->tm_mday;
	int iHour = eventTime->tm_hour;
	int iMin = eventTime->tm_min;
	int iSec = eventTime->tm_sec;
	char sDate[16];
	sprintf(sDate, "%04d-%02d-%02d", iYear, iMon, iDay);
	char sTime[16];
	sprintf(sTime, "%02d:%02d:%02d", iHour, iMin, iSec);
	char s[1024];
	sprintf(s, "%s %s %s\n", sDate, sTime, log);
	FILE *fd = fopen("my.log", "a+");//以追加方式打开
	fputs(s, fd);
	fclose(fd);
}

void setdaemon()
{
	pid_t pid, sid;
	pid = fork();
	if (pid < 0)
	{
		printf("fork failed\n");
		exit(-1);
	}
	if (pid > 0)
	{
		exit(0);//在父进程直接退出
	}
	if ((sid == setsid()) < 0)
	{
		printf("setsid failed\n");
		exit(-2);
	}
	//chdir("/");
	//umask(0);
}

int main(int arg, char *args[])
{
	setdaemon();
	char buf[100];
	int i = 0;
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "log %d", i++);
		writelog(buf);
		sleep(1);
	}
}
