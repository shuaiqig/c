/*�����ַ���*/ 
#include<stdio.h>
#include<string.h>
#define n 100

int s(char a[])     /*���ַ�������*/ 
{
	int i,k = 0;
	for(i = 0;a[i] != '\0';i++)     k++;
        
    return k;
}

int main()
{
	char a[n],b[n];
	printf("�������һ���ַ�����\n");
	gets(a);
	printf("�����������ַ�����\n");
    gets(b);
    
	do   
	{
      if(s(a) < s(b))
        strcpy(a,b);
	  printf("�����������ַ�����\n");
	}
	while(gets(b)!=NULL);   /*��Ϊ�ж���䣬ͬʱҲ�����һ������*/ 
	
	printf("��ַ���Ϊ��"); 
	puts(a);
	
	return 0;
}

