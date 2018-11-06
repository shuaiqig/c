//需输入3个参数   文件路径、记录条数、数据记录文件类型 
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include <time.h>

#define N 100

//路径：     E:\代码\大一下\第四次实验\Lab3_new.exe

int main(int argc , char const *argv[])
{
	char c[N],s1[N],s2[N],c1[N];
	int a,i,j;
	srand((unsigned) time(NULL));   //以时间做种，每次产生的随机数不一样 
		
	if(argc < 2 || strlen(argv[1]) > 100)                   //不知道文件名的处理 、防止数组溢出     
	    strcpy(c , "代码\\大一下\\第四次实验\\实验3");
	else
	    strcpy(c , argv[1]);
	
	if(argc < 3)                   //  不知道记录条数的处理
	    a = rand()%100; 
	else if(*argv[2] - '1' < 0)
	{
	    printf("输入记录条数异常！\n");
        a = rand()%100;
	}
	else
		sscanf(argv[2] , "%d" , &a);          //把字符串转换成int型整数 
	
	if(argc < 4)                  //根据从命令行参数输入的内容，生成相应类型的文件 
	{
		strcpy(c1 , "w");
		strcat(c , ".txt");   //拼接后缀名  .txt
    }
	else if(strcmp(argv[3] , "txt") == 0)
	{
		strcpy(c1 , "w");
		strcat(c , ".txt");  
    }
	else if(strcmp(argv[3] , "dat") == 0)
	{
		strcpy(c1 , "wb");
		strcat(c , ".dat");   //拼接后缀名  .dat
    }
	else
	{
		strcpy(c1 , "w");
		strcat(c , ".txt");
    }
			
	freopen(c , c1 , stdout); //输出重定向，输出数据将保存在相应文件中

	printf("%d\n" , a);              //输入内容 
	for(i = 0;i < a;i++)
	{ 
	   for(j = 0;j < 2;j++)
	      {
	        printf("%d," , rand()%100);
		  }
		printf("%d\n" , rand()%100);
	}

	fclose(stdout);//关闭文件 
	return 0;  	
}
