#include<stdio.h>    
#include<malloc.h>
#include <windows.h>
#include"start.h" 
#include"process.h" 

int t = 0;  //ʱ����ȫ�ֱ��� 

ELEVATORSTATE d;   //����״̬�ṹ�壬����˵��ݵĸ���״̬��Ϣ

RESPONSELISTNODE *PHead = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));   //����Ӧָ���������  ͷ���

SERVELISTNODE *now = (SERVELISTNODE*)malloc(sizeof(ServeListNode));     //��ǰ����ָ�����������ṹ��

SERVELISTNODE *pn = NULL;

SERVELISTNODE **pn2 = NULL;

SERVELISTNODE **rn = &now;

RESPONSELISTHEADNODE *Head = (RESPONSELISTHEADNODE*)malloc(sizeof(ResponseListHeadNode));   //����ͷ������ݽṹ������

Summary s;

void start_1(int date[][3], int n)
{
    printf("*****************************���������Ϣ*****************************\n");
	printf("�������¥������32\n");
	printf("���η����û������ļ�������1\n");
	printf("����������ͣ��������\n");
	printf("*****************************���η�����Ϣ*****************************\n");
	printf("�����ţ�1\n");
	printf("*****************************�û�����ָ����Ϣ*****************************\n");
	
	int i = 0;
    USERCALL u[n];           //�û�������Ϣ�ṹ��
	for(i = 0; i < n; i++)       //������õ��û�ָ������ṹ�� 
	    {
	    	
			printf("%d,%d,%d\n", date[i][0], date[i][1], date[i][2]); 
			
			u[i].user_floor = date[i][0];
	    	u[i].user_target = date[i][1];
	    	u[i].call_time = date[i][2];
	    	if(u[i].user_floor <= u[i].user_target)
	    	    u[i].call_type = 'U';  //�� 
	    	else
	    	    u[i].call_type = 'D';  //�� 
		}
	
	printf("**********************************************************************\n");
	
	//����Ӧָ�����������ṹ��
	RESPONSELISTNODE *pl = NULL;
	PHead->next_node = NULL;
	
	Head->list_num = 0;
	Head->head = PHead;
	Head->tail = PHead;

	
	d.current_floor = 1;   //����״̬�ṹ�壬����˵��ݵĸ���״̬��Ϣ
	d.run_state = 'S';
	
	
    //��ǰ����ָ�����������ṹ��
	now->serve_state = 'P';
	now->next_node = NULL;
	
	printf("t��%d, ��������¥�㣺%d, ��������״̬��%c, ��Ӧָ�", t, d.current_floor, d.run_state);
	PutServeList();
	printf("\n");

	i = 0;
	char PrintJudge; 
	while( ! (i == n && now->next_node == NULL && PHead->next_node == NULL) ) {
	
	int j = 0;
	for( ; j < n; j++)
	    {
	    	if(i < n && date[j][2] == t)   //�жϵ�ǰʱ���Ƿ����µ�ָ��� 
	    		{
					if (u[j].user_floor == u[j].user_target) 
						{
							i++;
							continue;
						}
						
					pl = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));    //    ����һ���½ڵ�
	   		 		pl->user_call = &u[j];                                  
	   			 	pl->next_node = NULL;                                   
	    	
	    			ResponseAdd(&Head->head, pl);        //��ӵ�����Ӧָ����� 
	    	
        			i++;
				}
		}
	
	PrintJudge = d.run_state;
	
	doyouwork();  //���ݷ��溯�� 
	t++;
	
	if(PrintJudge != d.run_state)
		{
			printf("t��%d, ��������¥�㣺%d, ��������״̬��%c, ��Ӧָ�", t, d.current_floor, d.run_state);
			PutServeList();
			printf("\n");
		}
	}	
}


void start_2(int date[][3], int n)
{
    FILE *fp;
    if((fp = fopen("E:\\����\\��һ��\\���ߴ�ʵ��\\�����ļ�2.txt", "w")) == NULL)
    	{
    		printf("�ļ�����ʧ�ܣ�\n");
    		return ;
		}
	
	else
		{
			fprintf(fp, "*****************************���������Ϣ*****************************\n");
			fprintf(fp, "�������¥������20\n");
			fprintf(fp, "���η����û������ļ�������1\n");
			fprintf(fp, "����������ͣ��������\n");
			fprintf(fp, "*****************************���η�����Ϣ*****************************\n");
			fprintf(fp, "�����ţ�1\n");
			fprintf(fp, "*****************************�û�����ָ����Ϣ*****************************\n");
			fprintf(fp, "%d\n", n);
			int i = 0;
		    USERCALL u[n];           //�û�������Ϣ�ṹ��
			for(i = 0; i < n; i++)       //������õ��û�ָ������ṹ�� 
		    	{
	    	
					fprintf(fp, "%d,%d,%d\n", date[i][0], date[i][1], date[i][2]); 
			
					u[i].user_floor = date[i][0];
			    	u[i].user_target = date[i][1];
	    			u[i].call_time = date[i][2];
			    	if(u[i].user_floor <= u[i].user_target)
	    			    u[i].call_type = 'U';  //�� 
	    			else
	    			    u[i].call_type = 'D';  //�� 
				}
	
			fprintf(fp, "**********************************************************************\n");
	
			//����Ӧָ�����������ṹ��
			RESPONSELISTNODE *pl = NULL;
			PHead->next_node = NULL;
	
			Head->list_num = 0;
			Head->head = PHead;
			Head->tail = PHead;

	
			d.current_floor = 1;   //����״̬�ṹ�壬����˵��ݵĸ���״̬��Ϣ
			d.run_state = 'S';
	
	
  		  //��ǰ����ָ�����������ṹ��
			now->serve_state = 'P';
			now->next_node = NULL;
	
			fprintf(fp, "t��%d, ��������¥�㣺%d, ��������״̬��%c, ��Ӧָ�", t, d.current_floor, d.run_state);
			PutServeList_2(fp);
			fprintf(fp, "\n");

			i = 0;
			char PrintJudge; 
			while( ! (i == n && now->next_node == NULL && PHead->next_node == NULL) ) {
	
			int j = 0;
			for( ; j < n; j++)
	 		   {
	 			   	if(i < n && date[j][2] == t)   //�жϵ�ǰʱ���Ƿ����µ�ָ��� 
	    				{
							if (u[j].user_floor == u[j].user_target) 
								{
									i++;
									continue;
								}
						
							pl = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));    //    ����һ���½ڵ�
	   				 		pl->user_call = &u[j];                                  
	   					 	pl->next_node = NULL;                                   
	    	
	    					ResponseAdd(&Head->head, pl);        //��ӵ�����Ӧָ����� 
        					i++;
						}
				}
	
			PrintJudge = d.run_state;
	
			doyouwork();  //���ݷ��溯�� 
			t++;
	
			if(PrintJudge != d.run_state)
				{
					fprintf(fp, "t��%d, ��������¥�㣺%d, ��������״̬��%c, ��Ӧָ�", t, d.current_floor, d.run_state);
					PutServeList_2(fp);
					fprintf(fp, "\n");
				}
			}
			
			fclose(fp);
			printf("�ļ��������,�����E:\\����\\��һ��\\���ߴ�ʵ��\\�����ļ�2.txt\n");	
		}
}

void start_3(int date[][3], int n)
{
	    FILE *fp;
    if((fp = fopen("E:\\����\\��һ��\\���ߴ�ʵ��\\�����ļ�3.txt", "w")) == NULL)
    	{
    		printf("�ļ�����ʧ�ܣ�\n");
    		return ;
		}
	
	else
		{
			fprintf(fp, "*****************************���������Ϣ*****************************\n");
			fprintf(fp, "�������¥������20\n");
			fprintf(fp, "���η����û������ļ�������1\n");
			fprintf(fp, "����������ͣ��������\n");
			fprintf(fp, "*****************************���η�����Ϣ*****************************\n");
			fprintf(fp, "�����ţ�1\n");
			fprintf(fp, "*****************************�û�����ָ����Ϣ*****************************\n");
			fprintf(fp, "%d\n", n);
			int i = 0;
		    USERCALL u[n];           //�û�������Ϣ�ṹ��
			for(i = 0; i < n; i++)       //������õ��û�ָ������ṹ�� 
		    	{
	    	
					fprintf(fp, "%d,%d,%d\n", date[i][0], date[i][1], date[i][2]); 
			
					u[i].user_floor = date[i][0];
			    	u[i].user_target = date[i][1];
	    			u[i].call_time = date[i][2];
			    	if(u[i].user_floor <= u[i].user_target)
	    			    u[i].call_type = 'U';  //�� 
	    			else
	    			    u[i].call_type = 'D';  //�� 
				}
	
			fprintf(fp, "**********************************************************************\n");
	
			//����Ӧָ�����������ṹ��
			RESPONSELISTNODE *pl = NULL;
			PHead->next_node = NULL;
	
			Head->list_num = 0;
			Head->head = PHead;
			Head->tail = PHead;

	
			d.current_floor = 1;   //����״̬�ṹ�壬����˵��ݵĸ���״̬��Ϣ
			d.run_state = 'S';
	
	
  		  //��ǰ����ָ�����������ṹ��
			now->serve_state = 'P';
			now->next_node = NULL;
	

			s.All = 0;  //���ݸ�Ҫ��Ϣ
			s.Up = 0;
			s.Down = 0;
			s.Road = 0;
			
			i = 0;
			char PrintJudge; 
			while( ! (i == n && now->next_node == NULL && PHead->next_node == NULL) ) {
	
			int j = 0;
			for( ; j < n; j++)
	 		   {
	 			   	if(i < n && date[j][2] == t)   //�жϵ�ǰʱ���Ƿ����µ�ָ��� 
	    				{
							if (u[j].user_floor == u[j].user_target) 
								{
									i++;
									continue;
								}
						
							pl = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));    //    ����һ���½ڵ�
	   				 		pl->user_call = &u[j];                                  
	   					 	pl->next_node = NULL;                                   
	    	
	    					ResponseAdd(&Head->head, pl);        //��ӵ�����Ӧָ����� 
        					i++;
						}
				}
	
			PrintJudge = d.run_state;
	
			doyouwork();  //���ݷ��溯�� 
			t++;
			}
			
			fprintf(fp, "������ʱ����%d, ������Ӧָ�%d, ����ָ�%d, ����ָ�%d, �������г��ȣ�%d;\n", t, s.All, s.Up, s.Down, s.Road);			
			fclose(fp);		
			printf("�ļ��������,�����E:\\����\\��һ��\\���ߴ�ʵ��\\�����ļ�3.txt\n");			
		}
}
 

void start_4(int date[][3], int n, int m, int mi, FILE *fp)
{
			
				fprintf(fp, "*****************************���η�����Ϣ*****************************\n");
				fprintf(fp, "�����ţ�%d\n", mi);
				fprintf(fp, "*****************************�û�����ָ����Ϣ*****************************\n");
				fprintf(fp, "%d\n", n);
				int i = 0;
			    USERCALL u[n];           //�û�������Ϣ�ṹ��
				for(i = 0; i < n; i++)       //������õ��û�ָ������ṹ�� 
			    	{
		    	
						fprintf(fp, "%d,%d,%d\n", date[i][0], date[i][1], date[i][2]); 
				
						u[i].user_floor = date[i][0];
				    	u[i].user_target = date[i][1];
		    			u[i].call_time = date[i][2];
				    	if(u[i].user_floor <= u[i].user_target)
		    			    u[i].call_type = 'U';  //�� 
		    			else
		    			    u[i].call_type = 'D';  //�� 
					}
		
				fprintf(fp, "**********************************************************************\n");
		
				//����Ӧָ�����������ṹ��
				RESPONSELISTNODE *pl = NULL;
				PHead->next_node = NULL;
		
				Head->list_num = 0;
				Head->head = PHead;
				Head->tail = PHead;
        
		
				d.current_floor = 1;   //����״̬�ṹ�壬����˵��ݵĸ���״̬��Ϣ
				d.run_state = 'S';
		
		
  	  	 		  //��ǰ����ָ�����������ṹ��
				now->serve_state = 'P';
				now->next_node = NULL;
		
        
				s.All = 0;  //���ݸ�Ҫ��Ϣ
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
		 			   	if(i < n && date[j][2] == t)   //�жϵ�ǰʱ���Ƿ����µ�ָ��� 
		    				{
								if (u[j].user_floor == u[j].user_target) 
									{
										i++;
										continue;
									}
							
								pl = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));    //    ����һ���½ڵ�
		   				 		pl->user_call = &u[j];                                  
		   					 	pl->next_node = NULL;                                   
		    	
		    					ResponseAdd(&Head->head, pl);        //��ӵ�����Ӧָ����� 
               					i++;
							}
					}
		
		//		PrintJudge = d.run_state;
	
				doyouwork();  //���ݷ��溯�� 
				t++;
	
		/*		if(PrintJudge != d.run_state)
					{
						fprintf(fp, "t��%d, ��������¥�㣺%d, ��������״̬��%c, ��Ӧָ�", t, d.current_floor, d.run_state);
						PutServeList_2(fp);
						fprintf(fp, "\n");
					}
		*/			
				}
				
				fprintf(fp, "������ʱ����%d, ������Ӧָ�%d, ����ָ�%d, ����ָ�%d, �������г��ȣ�%d;\n", t, s.All, s.Up, s.Down, s.Road);			
			
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


