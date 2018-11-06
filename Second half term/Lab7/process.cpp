#include<stdio.h>
#include<malloc.h>
#include"start.h" 
#include"process.h" 


void doyouwork()
{
	if(now->next_node == NULL)  //当前不在服务
	    {
			if(PHead->next_node != NULL)  //队列不为空t 
	   	    {	    	    	 
				
				pn = (SERVELISTNODE*)malloc(sizeof(ServeListNode));
				pn->user_call = PHead->next_node->user_call;  //将该指令从待响应指令队列中取出，加入到电梯的服务指令队列
				pn->serve_state = 'P';
				pn->next_node = NULL;
				
				ServeListAdd(rn, pn);
									    	    		    	    	
	   	    	ResponseCut(&Head->head, &Head->tail);    //从待响应指令中去除
			  
				pn2 = &now->next_node;		
				if((*pn2)->user_call->user_floor == d.current_floor)  //用户所在楼层 = 电梯所在楼层 
				    {
				    	(*pn2)->serve_state = 'E';  // 设为 服务中 
					}
				else                                                //          != 
				    {
				    	(*pn2)->serve_state = 'P';  // 设为 服务前 
					}
				

				
				Process1_ride();  //流程 1 
			}	    	
	    	else
	    	    return ;
		}
	
	
	else if(now->next_node != NULL)  //正在服务
	    {
	    	Process1_ride();  //流程 1 
		} 
	
	Process2_judge();  //流程 2
}


void Process1_ride()
{
	if(d.run_state == 'U')  //上 
	    {
	    	RESPONSELISTNODE *Pl3 = PHead->next_node;    //  遍历 
	    	
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
	
	else if(d.run_state == 'D')  //下 
	    {
	    	RESPONSELISTNODE *Pl3 = PHead->next_node;    //  遍历 
	    	
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
	
	else if(d.run_state == 'S')  //停 
	    {
	    	if(((*pn2)->serve_state == 'P' && (*pn2)->user_call->user_floor > d.current_floor) || ((*pn2)->serve_state == 'E' && (*pn2)->user_call->user_target > d.current_floor)) 
	    	    {
	    	    	RESPONSELISTNODE *Pl3 = PHead->next_node;    //  遍历 
	    	
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
			    	RESPONSELISTNODE *Pl3 = PHead->next_node;    //  遍历 
	    	
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
	    	SERVELISTNODE *Pn3 = now->next_node;    //  遍历 
	    	
	        for( ; Pn3 != NULL; )
	    	    {
	    			if(Pn3->serve_state == 'P')  //服务前
						{
							if(Pn3->user_call->user_floor == d.current_floor + 1)  //用户所在楼层 等于（m+1)
							    {
							    	d.run_state = 'S';
							    	ChangeToE(&Pn3);  // 设为 服务中
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
					else if(Pn3->serve_state == 'E')  //服务中
					    {
					    	if(Pn3->user_call->user_target == d.current_floor + 1)  //用户目标楼层 等于（m+1)
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
				
			d.current_floor++;   //电梯楼层 +1 
			s.Road++;
		}
		
		
	else if(d.run_state == 'D')
	    {
	    	SERVELISTNODE *Pn3 = now->next_node;    //  遍历 
	    	
	    	        for( ; Pn3 != NULL; )
	    			    {
	    			    	if(Pn3->serve_state == 'P')  //服务前
							    {
							    	if(Pn3->user_call->user_floor == d.current_floor - 1)  //用户所在楼层 等于（m-1)
							    	    {
							    	    	d.run_state = 'S';
							    	    	ChangeToE(&Pn3);  // 设为 服务中
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
							else if(Pn3->serve_state == 'E')  //服务中
							    {
							    	if(Pn3->user_call->user_target == d.current_floor - 1)  //用户所在楼层 等于（m-1)
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
			d.current_floor--;   //电梯楼层 -1 
			s.Road++;
		}
	
		
	else if(d.run_state == 'S')
	    {
	    	if((*pn2)->serve_state == 'P')  //服务前 
	    	    {
	    	    	if((*pn2)->user_call->user_floor > d.current_floor)  //用户所在楼层 > m？
	    	    	    {
	    	    	    	d.run_state = 'U';
						}
					else
					    {
					    	d.run_state = 'D';
						}
				}
			else if((*pn2)->serve_state == 'E')  //服务中
			    {
			    	if((*pn2)->user_call->user_target > d.current_floor)  //用户目标楼层 > m？
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

void ServeListAdd(SERVELISTNODE **p, SERVELISTNODE *pn)          //添加到当前服务指令队列
{
	SERVELISTNODE *pp = *p;
	
	while(pp->next_node != NULL)
		{
			pp = pp->next_node;
		}
	
	SERVELISTNODE **ppp = &pp;
	(*ppp)->next_node = pn;		

}

void ResponseAdd(RESPONSELISTNODE **ph, RESPONSELISTNODE *pl)      //添加到待响应指令队列
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
	   		RESPONSELISTNODE *temp_next = (*ph)->next_node->next_node;   //取出第一条 
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
	   		RESPONSELISTNODE *temp_next = (*p)->next_node;   //取出
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
			SERVELISTNODE *temp_next = (*p)->next_node;  //删除当前服务节点 
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
	(*p)->serve_state = 'E';  // 设为 服务中
}

