#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include <time.h>

#define N 100

//·����     E:\����\��һ��\������ʵ��\Lab3.exe

int main(int argc, char const *argv[])
{
	char c[N],s1[N],s2[N];
	int a,i,j;
	srand((unsigned) time(NULL));   //��ʱ�����֣�ÿ�β������������һ�� 
		
	if(argc < 2 || strlen(argv[1]) > 100)                   //��֪���ļ����Ĵ��� ����ֹ�������     
	    strcpy(c,"����\\��һ��\\������ʵ��\\ʵ��3.txt");
	else
	    strcpy(c,argv[1]);   
	
	if(argc < 3)                   //  ��֪����¼�����Ĵ���
	    a = rand()%100; 
	else if(*argv[2] - '1' < 0)
	{
	    printf("�����¼�����쳣��\n");
        a = rand()%100;
	}
	else
		sscanf(argv[2],"%d",&a);          //���ַ���ת����int������ 
	
	int b[a][3];
	
	for(i = 0;i < a;i++)            //���������ֵ 
	   for(j = 0;j < 3;j++)
	      {
	      	b[i][j] = rand()%100;
		  }

	freopen(c,"w",stdout); //����ض���������ݽ���������Ӧ�ļ���

	printf("%d\n",a);              //�������� 
	for(i = 0;i < a;i++)
	{ 
	   for(j = 0;j < 2;j++)
	      {
	        printf("%d,",b[i][j]);
		  }
		printf("%d\n",b[i][2]);
	}

	fclose(stdout);//�ر��ļ� 
	return 0;  	
}