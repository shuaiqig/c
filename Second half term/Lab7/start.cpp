#include<stdio.h>    
#include<malloc.h>
#include <windows.h>
#include"start.h" 
#include"process.h" 

int t = 0;  //时间做全局变量 

ELEVATORSTATE d;   //电梯状态结构体，保存此电梯的各项状态信息

RESPONSELISTNODE *PHead = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));   //待响应指令队列链表  头结点

SERVELISTNODE *now = (SERVELISTNODE*)malloc(sizeof(ServeListNode));     //当前服务指令队列链表结点结构体

SERVELISTNODE *pn = NULL;

SERVELISTNODE **pn2 = NULL;

SERVELISTNODE **rn = &now;

RESPONSELISTHEADNODE *Head = (RESPONSELISTHEADNODE*)malloc(sizeof(ResponseListHeadNode));   //链表头结点数据结构体声明

Summary s;

void start_1(int date[][3], int n)
{
    printf("*****************************仿真基本信息*****************************\n");
	printf("电梯最大楼层数：32\n");
	printf("本次仿真用户请求文件数量：1\n");
	printf("仿真输出类型：详情输出\n");
	printf("*****************************单次仿真信息*****************************\n");
	printf("仿真编号：1\n");
	printf("*****************************用户请求指令信息*****************************\n");
	
	int i = 0;
    USERCALL u[n];           //用户请求信息结构体
	for(i = 0; i < n; i++)       //将排序好的用户指令输入结构体 
	    {
	    	
			printf("%d,%d,%d\n", date[i][0], date[i][1], date[i][2]); 
			
			u[i].user_floor = date[i][0];
	    	u[i].user_target = date[i][1];
	    	u[i].call_time = date[i][2];
	    	if(u[i].user_floor <= u[i].user_target)
	    	    u[i].call_type = 'U';  //上 
	    	else
	    	    u[i].call_type = 'D';  //下 
		}
	
	printf("**********************************************************************\n");
	
	//待响应指令队列链表结点结构体
	RESPONSELISTNODE *pl = NULL;
	PHead->next_node = NULL;
	
	Head->list_num = 0;
	Head->head = PHead;
	Head->tail = PHead;

	
	d.current_floor = 1;   //电梯状态结构体，保存此电梯的各项状态信息
	d.run_state = 'S';
	
	
    //当前服务指令队列链表结点结构体
	now->serve_state = 'P';
	now->next_node = NULL;
	
	printf("t：%d, 电梯所在楼层：%d, 电梯运行状态：%c, 响应指令：", t, d.current_floor, d.run_state);
	PutServeList();
	printf("\n");

	i = 0;
	char PrintJudge; 
	while( ! (i == n && now->next_node == NULL && PHead->next_node == NULL) ) {
	
	int j = 0;
	for( ; j < n; j++)
	    {
	    	if(i < n && date[j][2] == t)   //判断当前时刻是否有新的指令到来 
	    		{
					if (u[j].user_floor == u[j].user_target) 
						{
							i++;
							continue;
						}
						
					pl = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));    //    分配一个新节点
	   		 		pl->user_call = &u[j];                                  
	   			 	pl->next_node = NULL;                                   
	    	
	    			ResponseAdd(&Head->head, pl);        //添加到待响应指令队列 
	    	
        			i++;
				}
		}
	
	PrintJudge = d.run_state;
	
	doyouwork();  //电梯仿真函数 
	t++;
	
	if(PrintJudge != d.run_state)
		{
			printf("t：%d, 电梯所在楼层：%d, 电梯运行状态：%c, 响应指令：", t, d.current_floor, d.run_state);
			PutServeList();
			printf("\n");
		}
	}	
}


void start_2(int date[][3], int n)
{
    FILE *fp;
    if((fp = fopen("E:\\代码\\大一下\\第七次实验\\仿真文件2.txt", "w")) == NULL)
    	{
    		printf("文件创建失败！\n");
    		return ;
		}
	
	else
		{
			fprintf(fp, "*****************************仿真基本信息*****************************\n");
			fprintf(fp, "电梯最大楼层数：20\n");
			fprintf(fp, "本次仿真用户请求文件数量：1\n");
			fprintf(fp, "仿真输出类型：详情输出\n");
			fprintf(fp, "*****************************单次仿真信息*****************************\n");
			fprintf(fp, "仿真编号：1\n");
			fprintf(fp, "*****************************用户请求指令信息*****************************\n");
			fprintf(fp, "%d\n", n);
			int i = 0;
		    USERCALL u[n];           //用户请求信息结构体
			for(i = 0; i < n; i++)       //将排序好的用户指令输入结构体 
		    	{
	    	
					fprintf(fp, "%d,%d,%d\n", date[i][0], date[i][1], date[i][2]); 
			
					u[i].user_floor = date[i][0];
			    	u[i].user_target = date[i][1];
	    			u[i].call_time = date[i][2];
			    	if(u[i].user_floor <= u[i].user_target)
	    			    u[i].call_type = 'U';  //上 
	    			else
	    			    u[i].call_type = 'D';  //下 
				}
	
			fprintf(fp, "**********************************************************************\n");
	
			//待响应指令队列链表结点结构体
			RESPONSELISTNODE *pl = NULL;
			PHead->next_node = NULL;
	
			Head->list_num = 0;
			Head->head = PHead;
			Head->tail = PHead;

	
			d.current_floor = 1;   //电梯状态结构体，保存此电梯的各项状态信息
			d.run_state = 'S';
	
	
  		  //当前服务指令队列链表结点结构体
			now->serve_state = 'P';
			now->next_node = NULL;
	
			fprintf(fp, "t：%d, 电梯所在楼层：%d, 电梯运行状态：%c, 响应指令：", t, d.current_floor, d.run_state);
			PutServeList_2(fp);
			fprintf(fp, "\n");

			i = 0;
			char PrintJudge; 
			while( ! (i == n && now->next_node == NULL && PHead->next_node == NULL) ) {
	
			int j = 0;
			for( ; j < n; j++)
	 		   {
	 			   	if(i < n && date[j][2] == t)   //判断当前时刻是否有新的指令到来 
	    				{
							if (u[j].user_floor == u[j].user_target) 
								{
									i++;
									continue;
								}
						
							pl = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));    //    分配一个新节点
	   				 		pl->user_call = &u[j];                                  
	   					 	pl->next_node = NULL;                                   
	    	
	    					ResponseAdd(&Head->head, pl);        //添加到待响应指令队列 
        					i++;
						}
				}
	
			PrintJudge = d.run_state;
	
			doyouwork();  //电梯仿真函数 
			t++;
	
			if(PrintJudge != d.run_state)
				{
					fprintf(fp, "t：%d, 电梯所在楼层：%d, 电梯运行状态：%c, 响应指令：", t, d.current_floor, d.run_state);
					PutServeList_2(fp);
					fprintf(fp, "\n");
				}
			}
			
			fclose(fp);
			printf("文件生成完毕,请查阅E:\\代码\\大一下\\第七次实验\\仿真文件2.txt\n");	
		}
}

void start_3(int date[][3], int n)
{
	    FILE *fp;
    if((fp = fopen("E:\\代码\\大一下\\第七次实验\\仿真文件3.txt", "w")) == NULL)
    	{
    		printf("文件创建失败！\n");
    		return ;
		}
	
	else
		{
			fprintf(fp, "*****************************仿真基本信息*****************************\n");
			fprintf(fp, "电梯最大楼层数：20\n");
			fprintf(fp, "本次仿真用户请求文件数量：1\n");
			fprintf(fp, "仿真输出类型：详情输出\n");
			fprintf(fp, "*****************************单次仿真信息*****************************\n");
			fprintf(fp, "仿真编号：1\n");
			fprintf(fp, "*****************************用户请求指令信息*****************************\n");
			fprintf(fp, "%d\n", n);
			int i = 0;
		    USERCALL u[n];           //用户请求信息结构体
			for(i = 0; i < n; i++)       //将排序好的用户指令输入结构体 
		    	{
	    	
					fprintf(fp, "%d,%d,%d\n", date[i][0], date[i][1], date[i][2]); 
			
					u[i].user_floor = date[i][0];
			    	u[i].user_target = date[i][1];
	    			u[i].call_time = date[i][2];
			    	if(u[i].user_floor <= u[i].user_target)
	    			    u[i].call_type = 'U';  //上 
	    			else
	    			    u[i].call_type = 'D';  //下 
				}
	
			fprintf(fp, "**********************************************************************\n");
	
			//待响应指令队列链表结点结构体
			RESPONSELISTNODE *pl = NULL;
			PHead->next_node = NULL;
	
			Head->list_num = 0;
			Head->head = PHead;
			Head->tail = PHead;

	
			d.current_floor = 1;   //电梯状态结构体，保存此电梯的各项状态信息
			d.run_state = 'S';
	
	
  		  //当前服务指令队列链表结点结构体
			now->serve_state = 'P';
			now->next_node = NULL;
	

			s.All = 0;  //电梯概要信息
			s.Up = 0;
			s.Down = 0;
			s.Road = 0;
			
			i = 0;
			char PrintJudge; 
			while( ! (i == n && now->next_node == NULL && PHead->next_node == NULL) ) {
	
			int j = 0;
			for( ; j < n; j++)
	 		   {
	 			   	if(i < n && date[j][2] == t)   //判断当前时刻是否有新的指令到来 
	    				{
							if (u[j].user_floor == u[j].user_target) 
								{
									i++;
									continue;
								}
						
							pl = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));    //    分配一个新节点
	   				 		pl->user_call = &u[j];                                  
	   					 	pl->next_node = NULL;                                   
	    	
	    					ResponseAdd(&Head->head, pl);        //添加到待响应指令队列 
        					i++;
						}
				}
	
			PrintJudge = d.run_state;
	
			doyouwork();  //电梯仿真函数 
			t++;
			}
			
			fprintf(fp, "仿真总时长：%d, 电梯响应指令：%d, 上行指令：%d, 下行指令：%d, 电梯运行长度：%d;\n", t, s.All, s.Up, s.Down, s.Road);			
			fclose(fp);		
			printf("文件生成完毕,请查阅E:\\代码\\大一下\\第七次实验\\仿真文件3.txt\n");			
		}
}
 

void start_4(int date[][3], int n, int m, int mi, FILE *fp)
{
			
				fprintf(fp, "*****************************单次仿真信息*****************************\n");
				fprintf(fp, "仿真编号：%d\n", mi);
				fprintf(fp, "*****************************用户请求指令信息*****************************\n");
				fprintf(fp, "%d\n", n);
				int i = 0;
			    USERCALL u[n];           //用户请求信息结构体
				for(i = 0; i < n; i++)       //将排序好的用户指令输入结构体 
			    	{
		    	
						fprintf(fp, "%d,%d,%d\n", date[i][0], date[i][1], date[i][2]); 
				
						u[i].user_floor = date[i][0];
				    	u[i].user_target = date[i][1];
		    			u[i].call_time = date[i][2];
				    	if(u[i].user_floor <= u[i].user_target)
		    			    u[i].call_type = 'U';  //上 
		    			else
		    			    u[i].call_type = 'D';  //下 
					}
		
				fprintf(fp, "**********************************************************************\n");
		
				//待响应指令队列链表结点结构体
				RESPONSELISTNODE *pl = NULL;
				PHead->next_node = NULL;
		
				Head->list_num = 0;
				Head->head = PHead;
				Head->tail = PHead;
        
		
				d.current_floor = 1;   //电梯状态结构体，保存此电梯的各项状态信息
				d.run_state = 'S';
		
		
  	  	 		  //当前服务指令队列链表结点结构体
				now->serve_state = 'P';
				now->next_node = NULL;
		
        
				s.All = 0;  //电梯概要信息
				s.Up = 0;
				s.Down = 0;
				s.Road = 0;
				
				i = 0;
				t = 0; 
				while( ! (i == n && now->next_node == NULL && PHead->next_node == NULL) ) {
		
				int j = 0;
		//		char PrintJudge;
				for( ; j < n; j++)
		 		   {
		 			   	if(i < n && date[j][2] == t)   //判断当前时刻是否有新的指令到来 
		    				{
								if (u[j].user_floor == u[j].user_target) 
									{
										i++;
										continue;
									}
							
								pl = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));    //    分配一个新节点
		   				 		pl->user_call = &u[j];                                  
		   					 	pl->next_node = NULL;                                   
		    	
		    					ResponseAdd(&Head->head, pl);        //添加到待响应指令队列 
               					i++;
							}
					}
		
		//		PrintJudge = d.run_state;
	
				doyouwork();  //电梯仿真函数 
				t++;
	
		/*		if(PrintJudge != d.run_state)
					{
						fprintf(fp, "t：%d, 电梯所在楼层：%d, 电梯运行状态：%c, 响应指令：", t, d.current_floor, d.run_state);
						PutServeList_2(fp);
						fprintf(fp, "\n");
					}
		*/			
				}
				
				fprintf(fp, "仿真总时长：%d, 电梯响应指令：%d, 上行指令：%d, 下行指令：%d, 电梯运行长度：%d;\n", t, s.All, s.Up, s.Down, s.Road);			
			
}

void PutServeList()
{
	SERVELISTNODE *p = now->next_node;
	while(p != NULL)
		{
			printf("<%d, %d, %d, %c> ", p->user_call->user_floor, p->user_call->user_target, p->user_call->call_time, p->serve_state);
			p = p->next_node;
		}
}

void PutServeList_2(FILE *fp)
{
	SERVELISTNODE *p = now->next_node;
	while(p != NULL)
		{
			fprintf(fp, "<%d, %d, %d, %c> ", p->user_call->user_floor, p->user_call->user_target, p->user_call->call_time, p->serve_state);
			p = p->next_node;
		}
}


