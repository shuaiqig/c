/*ͳ���ַ����ִ���*/ 
#include<stdio.h>
#include<string.h>

int count(char str[], char c)
{
	strlwr(str);
	int i,F = 0;
	for(i = 0;i < 100;i++)
		if(str[i] == c)        F++;
	return F;
}

int main()
{
	char a[100],c;
	printf("������Ҫ���ҵ��ַ�����\n");
    gets(a);                              /*ע��˳��*/ 
	printf("������Ҫ���ҵ��ַ�'c'\n");
	scanf("%c",&c);
	
    printf("�ַ�%c���ִ���Ϊ%d��\n",c,count(a,c));
    
    return 0;
}
