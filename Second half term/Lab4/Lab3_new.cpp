//������3������   �ļ�·������¼���������ݼ�¼�ļ����� 
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include <time.h>

#define N 100

//·����     E:\����\��һ��\���Ĵ�ʵ��\Lab3_new.exe

int main(int argc , char const *argv[])
{
	char c[N],s1[N],s2[N],c1[N];
	int a,i,j;
	srand((unsigned) time(NULL));   //��ʱ�����֣�ÿ�β������������һ�� 
		
	if(argc < 2 || strlen(argv[1]) > 100)                   //��֪���ļ����Ĵ��� ����ֹ�������     
	    strcpy(c , "����\\��һ��\\���Ĵ�ʵ��\\ʵ��3");
	else
	    strcpy(c , argv[1]);
	
	if(argc < 3)                   //  ��֪����¼�����Ĵ���
	    a = rand()%100; 
	else if(*argv[2] - '1' < 0)
	{
	    printf("�����¼�����쳣��\n");
        a = rand()%100;
	}
	else
		sscanf(argv[2] , "%d" , &a);          //���ַ���ת����int������ 
	
	if(argc < 4)                  //���ݴ������в�����������ݣ�������Ӧ���͵��ļ� 
	{
		strcpy(c1 , "w");
		strcat(c , ".txt");   //ƴ�Ӻ�׺��  .txt
    }
	else if(strcmp(argv[3] , "txt") == 0)
	{
		strcpy(c1 , "w");
		strcat(c , ".txt");  
    }
	else if(strcmp(argv[3] , "dat") == 0)
	{
		strcpy(c1 , "wb");
		strcat(c , ".dat");   //ƴ�Ӻ�׺��  .dat
    }
	else
	{
		strcpy(c1 , "w");
		strcat(c , ".txt");
    }
			
	freopen(c , c1 , stdout); //����ض���������ݽ���������Ӧ�ļ���

	printf("%d\n" , a);              //�������� 
	for(i = 0;i < a;i++)
	{ 
	   for(j = 0;j < 2;j++)
	      {
	        printf("%d," , rand()%100);
		  }
		printf("%d\n" , rand()%100);
	}

	fclose(stdout);//�ر��ļ� 
	return 0;  	
}
