/*ͳ�Ƶ��ʸ���*/
#include<stdio.h>
#include<string.h>
#define N 1024

int CountWordsInOneLine(const char *szLine)         //const char *ָ��ָ������ݲ��ɱ䣬��ָ�뱾������ٸ�ֵ
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
	printf("������һ���ַ���");
	gets(c);
	printf("\n���ʸ���Ϊ��%d \n",CountWordsInOneLine(c));
	return 0;
} 
