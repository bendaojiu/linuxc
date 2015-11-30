#include <string.h>

void upper(const char *src, char *desc)
{
	int len = strlen(src);
	int i = 0;
	for (; i<len; i++)
	{
		if ((src[i] <='z') && (src[i] >='a'))
			desc[i] = src[i] - 0x20;//A编码为0x41，a为0x61
		else
			desc[i] = src[i];
	}
}
