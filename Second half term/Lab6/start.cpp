#include<stdio.h>    
#include<malloc.h>
#include <windows.h>
#include"start.h" 

int t = 0;  //ʱ����ȫ�ֱ��� 

ELEVATORSTATE d;   //����״̬�ṹ�壬����˵��ݵĸ���״̬��Ϣ

RESPONSELISTNODE *PHead = (RESPONSELISTNODE*)malloc(sizeof(ResponseListNode));   //����Ӧָ���������  ͷ���

SERVELISTNODE *now = (SERVELISTNODE*)malloc(sizeof(ServeListNode));     //��ǰ����ָ�����������ṹ��

SERVELISTNODE *pn = NULL;

SERVELISTNODE **pn2 = NULL;

SERVELISTNODE **rn = &now;

RESPONSELISTHEADNODE *Head = (RESPONSELISTHEADNODE*)malloc(sizeof(ResponseListHeadNode));   //����ͷ������ݽṹ������


void start(int date[][3], int n)
{
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
	
	printf("t��%d, ��������¥�㣺%d, ��������״̬��%c, ����Ӧָ������%d\n", t, d.current_floor, d.run_state, Head->list_num);

	i = 0;
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
	
	doyouwork();  //���ݷ��溯�� 
	t++;
	printf("t��%d, ��������¥�㣺%d, ��������״̬��%c, ����Ӧָ������%d\n", t, d.current_floor, d.run_state, Head->list_num);
	}	
}

void doyouwork()
{
	if(now->next_node == NULL)  //��ǰ���ڷ���
	    {
			if(PHead->next_node != NULL)  //���в�Ϊ��t 
	   	    {	    	    	 
				
				pn = (SERVELISTNODE*)malloc(sizeof(ServeListNode));
				pn->user_call = PHead->next_node->user_call;  //����ָ��Ӵ���Ӧָ�������ȡ�������뵽���ݵķ���ָ�����
				pn->serve_state = 'P';
				pn->next_node = NULL;
				
				ServeListAdd(rn, pn);
									    	    		    	    	
	   	    	ResponseCut(&Head->head, &Head->tail);    //�Ӵ���Ӧָ����ȥ��
			  
				pn2 = &now->next_node;		
				if((*pn2)->user_call->user_floor == d.current_floor)  //�û�����¥�� = ��������¥�� 
				    {
				    	(*pn2)->serve_state = 'E';  // ��Ϊ ������ 
					}
				else                                                //          != 
				    {
				    	(*pn2)->serve_state = 'P';  // ��Ϊ ����ǰ 
					}
				

				
				Process1_ride();  //���� 1 
			}	    	
	    	else
	    	    return ;
		}
	
	
	else if(now->next_node != NULL)  //���ڷ���
	    {
	    	Process1_ride();  //���� 1 
		} 
	
	Process2_judge();  //���� 2
}


void Process1_ride()
{
	if(d.run_state == 'U')  //�� 
	    {
	    	RESPONSELISTNODE *Pl3 = PHead->next_node;    //  ���� 
	    	
	    	for( ; Pl3 != NULL; )
	    	    {
	    	    	if(Pl3->user_call->user_floor > d.current_floor && Pl3->user_call->user_target > Pl3->user_call->user_floor)
	    	    	    {							
							pn = (SERVELISTNODE*)malloc(sizeof(ServeListNode));														
							pn->user_call = Pl3->user_call;
	    	    	    	pn->serve_state = 'P';
	    	    	    	pn->next_node = NULL;
	    	    	    	
							ServeListAdd(rn, pn);
	    	    	    	
	    	    	    	
	    	    	    	ResponseCut2(&Pl3);	
						}
					
					if(Pl3 != NULL)
					    {
					    	Pl3 = Pl3->next_node;
						}
					else if(Pl3 == NULL)
					    {
					    	break;
						}
				}
	    	
	    	return ;
		} 
	
	else if(d.run_state == 'D')  //�� 
	    {
	    	RESPONSELISTNODE *Pl3 = PHead->next_node;    //  ���� 
	    	
	    	for( ; Pl3 != NULL; )
	    	    {
	    	    	if(Pl3->user_call->user_floor < d.current_floor && Pl3->user_call->user_target < Pl3->user_call->user_floor)
	    	    	    {
	    	    	    	pn = (SERVELISTNODE*)malloc(sizeof(ServeListNode));				
							pn->user_call = Pl3->user_call;
	    	    	    	pn->serve_state = 'P';
	    	    	    	pn->next_node = NULL;
	    	    	    	
							ServeListAdd(rn, pn);
	    	    	    	
	    	    	    	ResponseCut2(&Pl3);
						}
					
					if(Pl3 != NULL)
					    {
					    	Pl3 = Pl3->next_node;
						}
					else if(Pl3 == NULL)
					    {
					    	break;
						}
				}
	    	
	    	return ;
		}
	
	else if(d.run_state == 'S')  //ͣ 
	    {
	    	if(((*pn2)->serve_state == 'P' && (*pn2)->user_call->user_floor > d.current_floor) || ((*pn2)->serve_state == 'E' && (*pn2)->user_call->user_target > d.current_floor)) 
	    	    {
	    	    	RESPONSELISTNODE *Pl3 = PHead->next_node;    //  ���� 
	    	
	    	        for( ; Pl3 != NULL; )
	    			    {
	    			    	if(Pl3->user_call->user_floor >= d.current_floor && Pl3->user_call->user_target > Pl3->user_call->user_floor)
	    			    	    {
	    			    	    	pn = (SERVELISTNODE*)malloc(sizeof(ServeListNode));									
									pn->user_call = Pl3->user_call;
									pn->next_node = NULL;
									
										    			    	    	
	    			    	    	
	    			    	    	if(Pl3->user_call->user_floor == d.current_floor)
	    			    	    	    pn->serve_state = 'E';
	    			    	    	else if(Pl3->user_call->user_floor != d.current_floor)
	    			    	    	    pn->serve_state = 'P';
	    			    	    	
									ServeListAdd(rn, pn);
	    			    	    	
	    			    	    	ResponseCut2(&Pl3);
								}
							
							if(Pl3 != NULL)
					    		{
					    			Pl3 = Pl3->next_node;
								}
							else if(Pl3 == NULL)
							    {
					  			  	break;
								}
						}	
						
								        
				}
			
			else if(((*pn2)->serve_state == 'P' && (*pn2)->user_call->user_floor < d.current_floor) || ((*pn2)->serve_state == 'E' && (*pn2)->user_call->user_target < d.current_floor)) 
			    {
			    	RESPONSELISTNODE *Pl3 = PHead->next_node;    //  ���� 
	    	
	    	        for( ; Pl3 != NULL; )
	    			    {
	    			    	if(Pl3->user_call->user_floor <= d.current_floor && Pl3->user_call->user_target < Pl3->user_call->user_floor)
	    			    	    {
	    			    	    	pn = (SERVELISTNODE*)malloc(sizeof(ServeListNode));									
									pn->user_call = Pl3->user_call;
									pn->next_node = NULL;	    			    	    	
	    			    	    	
	    			    	    	if(Pl3->user_call->user_floor == d.current_floor)
	    			    	    	    pn->serve_state = 'E';
	    			    	    	else if(Pl3->user_call->user_floor != d.current_floor)
	    			    	    	    pn->serve_state = 'P';
	    			    	    	
									ServeListAdd(rn, pn);
									    
	    			    	    	ResponseCut2(&Pl3);
								}
							
							if(Pl3 != NULL)
					    		{
					    			Pl3 = Pl3->next_node;
								}
							else if(Pl3 == NULL)
							    {
					    			break;
								}
				        }
				}
			
			return ;
		}
}

void Process2_judge()
{
	if(d.run_state == 'U')
	    {
	    	SERVELISTNODE *Pn3 = now->next_node;    //  ���� 
	    	
	        for( ; Pn3 != NULL; )
	    	    {
	    			if(Pn3->serve_state == 'P')  //����ǰ
						{
							if(Pn3->user_call->user_floor == d.current_floor + 1)  //�û�����¥�� ���ڣ�m+1)
							    {
							    	d.run_state = 'S';
							    	ChangeToE(&Pn3);  // ��Ϊ ������
								}	
						
							if(Pn3 != NULL)
					    		{
					    			Pn3 = Pn3->next_node;
								}
							else if(Pn3 == NULL)
							   {
							    	break;
								}								
						}
					else if(Pn3->serve_state == 'E')  //������
					    {
					    	if(Pn3->user_call->user_target == d.current_floor + 1)  //�û�Ŀ��¥�� ���ڣ�m+1)
					    	    {
					    	    	d.run_state = 'S';
							    	    	
									ServeListCut(&Pn3);								
								}
							else
								{
									if(Pn3 != NULL)
					    				{
					    					Pn3 = Pn3->next_node;
										}
									else if(Pn3 == NULL)
									    {
									    	break;
										}
								}
						}					
				}
				
			d.current_floor++;   //����¥�� +1 
		}
		
		
	else if(d.run_state == 'D')
	    {
	    	SERVELISTNODE *Pn3 = now->next_node;    //  ���� 
	    	
	    	        for( ; Pn3 != NULL; )
	    			    {
	    			    	if(Pn3->serve_state == 'P')  //����ǰ
							    {
							    	if(Pn3->user_call->user_floor == d.current_floor - 1)  //�û�����¥�� ���ڣ�m-1)
							    	    {
							    	    	d.run_state = 'S';
							    	    	ChangeToE(&Pn3);  // ��Ϊ ������
							    	    }
											
							    	if(Pn3 != NULL)
					    				{
					    					Pn3 = Pn3->next_node;
										}
									else if(Pn3 == NULL)
									    {
									   		break;
										}
										
								}
							else if(Pn3->serve_state == 'E')  //������
							    {
							    	if(Pn3->user_call->user_target == d.current_floor - 1)  //�û�����¥�� ���ڣ�m-1)
							    	    {
							    	    	d.run_state = 'S';
							    	    	
											ServeListCut(&Pn3);
										}
									else
										{
											if(Pn3 != NULL)
					    						{
					    							Pn3 = Pn3->next_node;
												}
											else if(Pn3 == NULL)
											    {
											    	break;
												}
										}
							    }						
				        }
		d.current_floor--;   //����¥�� -1 
		}
	
		
	else if(d.run_state == 'S')
	    {
	    	if((*pn2)->serve_state == 'P')  //����ǰ 
	    	    {
	    	    	if((*pn2)->user_call->user_floor > d.current_floor)  //�û�����¥�� > m��
	    	    	    {
	    	    	    	d.run_state = 'U';
						}
					else
					    {
					    	d.run_state = 'D';
						}
				}
			else if((*pn2)->serve_state == 'E')  //������
			    {
			    	if((*pn2)->user_call->user_target > d.current_floor)  //�û�Ŀ��¥�� > m��
	    	    	    {
	    	    	    	d.run_state = 'U';
						}
					else
					    {
					    	d.run_state = 'D';
						}
				} 
		}
}

void ServeListAdd(SERVELISTNODE **p, SERVELISTNODE *pn)          //��ӵ���ǰ����ָ�����
{
	SERVELISTNODE *pp = *p;
	
	while(pp->next_node != NULL)
		{
			pp = pp->next_node;
		}
	
	SERVELISTNODE **ppp = &pp;
	(*ppp)->next_node = pn;		

}

void ResponseAdd(RESPONSELISTNODE **ph, RESPONSELISTNODE *pl)      //��ӵ�����Ӧָ�����
{
	RESPONSELISTNODE *pp = *ph;
	
	while(pp->next_node != NULL)
		{
			pp = pp->next_node;
		}
	
	RESPONSELISTNODE **ppp = &pp;
	(*ppp)->next_node = pl;	
	
	Head->tail = pl;

	Head->list_num++;
}

void ResponseCut(RESPONSELISTNODE **ph, RESPONSELISTNODE **pt)
{
	if((*ph)->next_node->next_node != NULL)
	   	{
	   		RESPONSELISTNODE *temp_next = (*ph)->next_node->next_node;   //ȡ����һ�� 
			(*ph)->next_node->user_call =  temp_next->user_call;
			(*ph)->next_node->next_node = temp_next->next_node;
		}
	else if((*ph)->next_node->next_node == NULL)
		{
			(*pt) = NULL;
			(*ph)->next_node = *pt;		
	    }
	Head->list_num--;
}

void ResponseCut2(RESPONSELISTNODE **p)
{
	if((*p)->next_node != NULL)
	   	{
	   		RESPONSELISTNODE *temp_next = (*p)->next_node;   //ȡ��
			(*p)->user_call =  temp_next->user_call;
			(*p)->next_node = temp_next->next_node;
		}
	else if((*p)->next_node == NULL)
		{
			RESPONSELISTNODE *pp = PHead;
	
			while(pp->next_node->next_node != NULL)
				{
					pp = pp->next_node;
				}
	
			RESPONSELISTNODE **ppp = &pp;
			(*ppp)->next_node = NULL;	
	
			Head->tail = pp;		
	    }
	Head->list_num--;
}

void ServeListCut(SERVELISTNODE **p)     
{
	if((*p)->next_node != NULL)
	    {
			SERVELISTNODE *temp_next = (*p)->next_node;  //ɾ����ǰ����ڵ� 
			(*p)->serve_state = temp_next->serve_state;
			(*p)->user_call = temp_next->user_call;
			(*p)->next_node = temp_next->next_node;
		} 
	else if((*p)->next_node == NULL)
		{
			SERVELISTNODE *pp = now;
			while(pp->next_node->next_node != NULL)
				{
					pp = pp->next_node;
				}
			SERVELISTNODE **ppp = &pp;
			(*ppp)->next_node = NULL;
			
			*p = (*p)->next_node;
		}
}

void ChangeToE(SERVELISTNODE **p)
{
	(*p)->serve_state = 'E';  // ��Ϊ ������
}

