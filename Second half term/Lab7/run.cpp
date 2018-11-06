#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"run.h"
#include"start.h"

void load(char file[], int date[][3])    //读取，存储 ，排序 
{
    int a[10000];
    int m;
	
	int x , i = 0 ;
	FILE *fp; 
	if((fp = fopen(file , "r")) == NULL)
	{
		printf("\n文件读取错误，退出load函数！\n");
		return ;
	}
	
	else{
		
		while(fscanf(fp,"%d,",&x) == 1)    //读取 
            {
            	a[i] = x;         //将文件中的数据存入一个数组   注意，a【0】 为记录条数，不采用 
            	i++;
			}
		m = i;               //  m  数据个数 

        fclose(fp);
       	}
       
	int j , k1 = 1;                  //二维数组存储                  
	for(i = 0;i < m/3;i++)
	    for(j = 0;j < 3;j++)
	        {
	        	date[i][j] = a[k1];
	        	k1++;
			}
    
	qsort(date, m/3, sizeof(date[0]), CmpLink1);     //二维数组   排序
	
}

int CmpLink1(const void *a,const void *b)   //  qsort  相关 
{
	int *c = (int *)a;
    int *d = (int *)b;
    
    if(c[2] > d[2])
		return 1; 
	else  
		return c[2] == d[2]?0:-1;
}
