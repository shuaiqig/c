#include<stdio.h>
#include<malloc.h>
#include"start.h" 
#include"process.h" 


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
			s.Road++;
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
			s.Road++;
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
	
	s.All++;
	if(pl->user_call->call_type == 'U')
		s.Up++;
	else if(pl->user_call->call_type == 'D')
		s.Down++;
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

