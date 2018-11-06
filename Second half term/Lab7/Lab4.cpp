#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h> 
#define N 100
//路径： 代码\大一下\第七次实验\lab4.exe

typedef struct configinfo{
	char  filesavepath[N] ;      //用于存放数据记录文件的默认存储目录 
	char  filename[N] ;                    //用于存储生成的默认文件名信息 
	int  maxvalue1 ;     //用于存放实验1中生成的数据记录三元组中第1、2个元素元素值的上限 
	int  minvalue1;   //用于存放实验1中生成的数据记录三元组中第1、2个元素元素值的下限 
	int  maxvalue2 ;     //用于存放实验1中生成的数据记录三元组中第3个元素元素值的上限 
	int  minvalue2;   //用于存放实验1中生成的数据记录三元组中第3个元素元素值的下限 
	int  recordcount1; //用于存放数据记录文件中需要生成的记录条数上限 
	int  recordcount2; //用于存放数据记录文件中需要生成的记录条数下限 
	int  recordcount;  //用于存放数据记录文件中需要生成的记录条数
	}CONF;
	
void run(int a , char **c);
CONF Configuration(CONF s);
void write(CONF r);
int RandRanges(int a , int b);

 	
int main (int argc , char* argv[]) 
{ 
	run (argc , argv);      //调用程序主功能实现函数 
	return  0 ; 
}

void run(int a , char **c)
{
	CONF s;
	
	s = Configuration(s);       //为配置变量各个分量初始化默认值
	
	switch(a)
	{
		case 3:{
			int b;
			sscanf(c[1] , "%d" , &b);              	         //把字符串转换成int型整数
			if(b <= s.recordcount1 && b >= s.recordcount2)   //必须大于下限，小于上限 
			{
			    s.recordcount = b;
			}
			else
			{
				printf("输入的记录条数不合法，函数结束！\n");
				return ;
			}           	
			strcpy(s.filename , c[2]);              //文件名信息写入配置信息变量
			break;                                  //路径已具备，文件名一定合法（会自动加上‘.txt’） 
		}
		
		case 2:{
			int b;
			sscanf(c[1] , "%d" , &b);              	        //把字符串转换成int型整数
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
				char p[N];
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
	write(s);
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
	freopen("E:\\代码\\大一下\\第七次实验\\conf.ini","r",stdin);
	scanf("%s%s",s.filesavepath,s.filename);
    scanf("%d%d%d%d%d%d",&s.maxvalue1,&s.minvalue1,&s.maxvalue2,&s.minvalue2,&s.recordcount1,&s.recordcount2);
    fclose(stdin);
    
    return s;
}

/*
*	函数名：write
*	功能：生成数据记录文件 
*	参数：CONF r  记录文件信息的结构体变量
*	返回值：无 
*/
void write(CONF r)
{
	char c[1024];
	strcat(r.filesavepath , r.filename);   //拼接 	
	strcpy(c , r.filesavepath);
	
	FILE *fp;
	if((fp=fopen(c,"w")) == NULL)      /*注意双斜杠*/   //已完成清空操作 
	  {
		printf("\n文件创建错误，write函数结束！");
		return ;                             //跳出 write 函数 
	  }
	fclose(fp);
	  
	if(freopen(c,"w",stdout) == NULL)
	  {
	  	    printf("\n文件打开错误，write函数结束！");
		    return ;                             //跳出 write 函数 	  
	  }
	
	else{
		printf("%d\n",r.recordcount);
	
		srand((int)time(NULL));   //设定随机数种子
		int i,m,n,p;
		char q[N];
	
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
	return;
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
