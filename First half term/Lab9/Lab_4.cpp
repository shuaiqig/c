/*�жϻ����ַ���*/ 
#include<stdio.h>
int level(char a[])
{
	int i,j,k = 0;
	for(i = 0;a[i] != '\0';i++);
	for(j = 0;a[j] != '\0';j++)
	    {
			if(a[j] != a[i-j-1])      k++;    
		}
    if(k == 0)       printf("����ַ����ǻ����ַ�\n");
    else             printf("����ַ������ǻ����ַ�\n");
}

int main()
{
	char a[100];
	printf("����������ַ���\n");
	gets(a);
	
	level(a);
	
	return 0;
}
