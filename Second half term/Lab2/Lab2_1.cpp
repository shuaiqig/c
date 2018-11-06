/*统计单词个数*/
#include<stdio.h>
#include<string.h>
#define N 1024

int CountWordsInOneLine(const char *szLine)         //const char *指针指向的内容不可变，但指针本身可以再赋值
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

int main()
{
	char c[N];
	printf("请输入一行字符：");
	gets(c);
	printf("\n单词个数为：%d \n",CountWordsInOneLine(c));
	return 0;
} 
