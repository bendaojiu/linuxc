#include <stdio.h>
#include <string.h>
#include "upper.h"

int main(int arg, char *args[])
{
	char inbuf[1024], outbuf[1024];
	memset(inbuf, 0, sizeof(inbuf));
	memset(outbuf, 0, sizeof(outbuf));
	if (arg < 2)
	{
		printf("请输入字符串:");
		scanf("%s", inbuf);
	}
	else
		strcpy(inbuf, args[1]);
	upper(inbuf, outbuf);
	printf("\n%s\n", outbuf);
	return 0;
}
