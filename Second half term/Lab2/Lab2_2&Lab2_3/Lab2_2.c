/*ͳ�Ƶ��ʸ���*/
#include<stdio.h>
#include<string.h>

int Lab2_2(const char *szLine)         //const char *ָ��ָ������ݲ��ɱ䣬��ָ�뱾������ٸ�ֵ
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

