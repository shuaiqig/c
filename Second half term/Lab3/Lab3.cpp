#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include <time.h>

#define N 100

//路径：     E:\代码\大一下\第三次实验\Lab3.exe

int main(int argc, char const *argv[])
{
	char c[N],s1[N],s2[N];
	int a,i,j;
	srand((unsigned) time(NULL));   //以时间做种，每次产生的随机数不一样 
		
	if(argc < 2 || strlen(argv[1]) > 100)                   //不知道文件名的处理 、防止数组溢出     
	    strcpy(c,"代码\\大一下\\第三次实验\\实验3.txt");
	else
	    strcpy(c,argv[1]);   
	
	if(argc < 3)                   //  不知道记录条数的处理
	    a = rand()%100; 
	else if(*argv[2] - '1' < 0)
	{
	    printf("输入记录条数异常！\n");
        a = rand()%100;
	}
	else
		sscanf(argv[2],"%d",&a);          //把字符串转换成int型整数 
	
	int b[a][3];
	
	for(i = 0;i < a;i++)            //以随机数赋值 
	   for(j = 0;j < 3;j++)
	      {
	      	b[i][j] = rand()%100;
		  }

	freopen(c,"w",stdout); //输出重定向，输出数据将保存在相应文件中

	printf("%d\n",a);              //输入内容 
	for(i = 0;i < a;i++)
	{ 
	   for(j = 0;j < 2;j++)
	      {
	        printf("%d,",b[i][j]);
		  }
		printf("%d\n",b[i][2]);
	}

	fclose(stdout);//关闭文件 
	return 0;  	
}
