#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h> 
#include"Lab4.h"


char file[100];  //全局变量  	

void Lab4(char c[3][100])
{
	int a = 3;
	
	CONF s;
	s = Configuration(s);       //为配置变量各个分量初始化默认值 
	
	switch(a)
	{
		case 3:{
			int b;
			sscanf(c[0] , "%d" , &b);              	         //把字符串转换成int型整数
			
			if(b <= s.recordcount1 && b >= s.recordcount2)   //必须大于下限，小于上限 
			{
			    s.recordcount = b;
			}
			else
			{
				printf("输入的记录条数不合法，函数结束！\n");
				return ;
			}           	
			strcpy(s.filename , c[1]);              //文件名信息写入配置信息变量
			break;                                  //路径已具备，文件名一定合法（会自动加上‘.txt’） 
		}
		
		case 2:{
			int b;
			sscanf(c[0] , "%d" , &b);              	        //把字符串转换成int型整数
			if(b <= s.recordcount1 && b >= s.recordcount2)  //必须大于下限，小于上限 
			{
			    s.recordcount = b;
			}
			else
			{
				printf("输入的记录条数不合法，函数结束！\n");
				return ;                                   //跳出 run 函数 
			}   
			strcpy(s.filename , "Lab4.txt");               //此文件名一定合法 
			break;
		}
		
		default: {
			printf("输入缺少参数，是否继续输入参数(y & n)\n");
			char a;
			scanf("%c",&a);

			if(a == 'y')
			{
				int n;
				char p[100];
				printf("输入记录条数:");
				if(scanf("%d",&n) != 1)
				  {
				  	  printf("\n输入数据错误，run函数结束");
				  	  return ;                             //跳出 run 函数 
				  }
				else if(n <= s.recordcount1 && n >= s.recordcount2)   //必须大于下限，小于上限 
					{
					    s.recordcount = n;
					}
				else
					{
						printf("输入的记录条数不合法，函数结束！\n");
						return ;                           //跳出 run 函数 
					}
				
				printf("\n输入文件名:");
				if(scanf("%s",p) != 1)
				  {
				  	  printf("\n输入数据错误，run函数结束");
				  	  return ;                            //跳出 run 函数 
				  }
				else
				      strcpy(s.filename , p);             //路径已具备，文件名一定合法（会自动加上‘.txt’）
			}
			else        //非 y 时 
			{
				return ;                                  //跳出 run 函数 
			}		
			break;
		}
	}
	
	char w[10];
	strcpy(w , c[2]);
	write(s , w);

	return ;
}

/*
*	函数名：Configuration
*	功能：为配置变量各个分量初始化默认值
*	参数：CONF s  记录文件信息的结构体变量
*	返回值：CONF s  记录文件信息的结构体变量
*/
CONF Configuration(CONF s)
{
	freopen("conf.ini","r",stdin);
	scanf("%s",s.filesavepath);
    scanf("%d%d%d%d%d%d%d",&s.maxvalue1,&s.minvalue1,&s.maxvalue2,&s.minvalue2,&s.recordcount1,&s.recordcount2,&s.recordcount);
    fclose(stdin);
    
    return s;
}

/*
*	函数名：write
*	功能：生成数据记录文件 
*	参数：CONF r  记录文件信息的结构体变量
*	返回值：无 
*/
void write(CONF r , char w[10])
{
	strcpy(file , r.filename);         //把文件名赋给全局变量 
	
	FILE *fp;

	if((fp=fopen(r.filename , w )) == NULL)      /*注意双斜杠*/   //已完成清空操作 
	  {
		printf("\n文件创建错误，write函数结束！");
		return ;                             //跳出 write 函数 
	  }
	fclose(fp);
	  
	if(freopen(r.filename, w ,stdout) == NULL)
	  {
	  	printf("\n文件打开错误，write函数结束！");
		return ;                             //跳出 write 函数 	  
	  }
	
	else{
		printf("%d\n",r.recordcount);
	
		srand((int)time(NULL));   //设定随机数种子
		int i,m,n,p;
		char q[100];
	
		for(i = 0;i < r.recordcount;i++)
		  {
	  		m = RandRanges(r.maxvalue1 , r.minvalue1);
	  		n = RandRanges(r.maxvalue1 , r.minvalue1);
	  		p = RandRanges(r.maxvalue2 , r.minvalue2);
	  	
	  		sprintf(q,"%d,%d,%d",m,n,p);          //拼接 
	  	    printf("%s\n",q);
	      }
    	fclose(stdout);
		}
		
	FILE *fq=freopen("a.out","w",stdout);
    fflush(fq);//将输出缓冲区清空
    freopen( "CON", "r", stdin );
	freopen( "CON", "w", stdout ); //定向输出到控制台
    
	return ;
}

/*
*	函数名：RandRanges
*	功能：生成一个指定范围内的随机整数的函数 
*	参数：int a , int b     2个int型整数 
*	返回值：一个int型随机数 
*/
RandRanges(int a , int b)
{
	return rand()%(a - b + 1) + b;
}
