#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"run.h"
#include"start.h"

void load(char file[], int date[][3])    //��ȡ���洢 ������ 
{
    int a[10000];
    int m;
	
	int x , i = 0 ;
	FILE *fp; 
	if((fp = fopen(file , "r")) == NULL)
	{
		printf("\n�ļ���ȡ�����˳�load������\n");
		return ;
	}
	
	else{
		
		while(fscanf(fp,"%d,",&x) == 1)    //��ȡ 
            {
            	a[i] = x;         //���ļ��е����ݴ���һ������   ע�⣬a��0�� Ϊ��¼������������ 
            	i++;
			}
		m = i;               //  m  ���ݸ��� 

        fclose(fp);
       	}
       
	int j , k1 = 1;                  //��ά����洢                  
	for(i = 0;i < m/3;i++)
	    for(j = 0;j < 3;j++)
	        {
	        	date[i][j] = a[k1];
	        	k1++;
			}
    
	qsort(date, m/3, sizeof(date[0]), CmpLink1);     //��ά����   ����
	
}

int CmpLink1(const void *a,const void *b)   //  qsort  ��� 
{
	int *c = (int *)a;
    int *d = (int *)b;
    
    if(c[2] > d[2])
		return 1; 
	else  
		return c[2] == d[2]?0:-1;
}
