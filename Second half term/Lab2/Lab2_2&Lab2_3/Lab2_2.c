/*统计单词个数*/
#include<stdio.h>
#include<string.h>

int Lab2_2(const char *szLine)         //const char *指针指向的内容不可变，但指针本身可以再赋值
{
	int n = 1;
	const char *p;
	for(p = szLine;p <= szLine + strlen(szLine);p++)
	   {
	   	   if(*p == ' ' || *p == ',' || *p == ';' || *p == ':')
	   	      n++;
	   }

	return n;
}

