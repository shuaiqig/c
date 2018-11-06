#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h> 
#include"Lab4.h"


char file[100];  //ȫ�ֱ���  	

void Lab4(char c[3][100])
{
	int a = 3;
	
	CONF s;
	s = Configuration(s);       //Ϊ���ñ�������������ʼ��Ĭ��ֵ 
	
	switch(a)
	{
		case 3:{
			int b;
			sscanf(c[0] , "%d" , &b);              	         //���ַ���ת����int������
			
			if(b <= s.recordcount1 && b >= s.recordcount2)   //����������ޣ�С������ 
			{
			    s.recordcount = b;
			}
			else
			{
				printf("����ļ�¼�������Ϸ�������������\n");
				return ;
			}           	
			strcpy(s.filename , c[1]);              //�ļ�����Ϣд��������Ϣ����
			break;                                  //·���Ѿ߱����ļ���һ���Ϸ������Զ����ϡ�.txt���� 
		}
		
		case 2:{
			int b;
			sscanf(c[0] , "%d" , &b);              	        //���ַ���ת����int������
			if(b <= s.recordcount1 && b >= s.recordcount2)  //����������ޣ�С������ 
			{
			    s.recordcount = b;
			}
			else
			{
				printf("����ļ�¼�������Ϸ�������������\n");
				return ;                                   //���� run ���� 
			}   
			strcpy(s.filename , "Lab4.txt");               //���ļ���һ���Ϸ� 
			break;
		}
		
		default: {
			printf("����ȱ�ٲ������Ƿ�����������(y & n)\n");
			char a;
			scanf("%c",&a);

			if(a == 'y')
			{
				int n;
				char p[100];
				printf("�����¼����:");
				if(scanf("%d",&n) != 1)
				  {
				  	  printf("\n�������ݴ���run��������");
				  	  return ;                             //���� run ���� 
				  }
				else if(n <= s.recordcount1 && n >= s.recordcount2)   //����������ޣ�С������ 
					{
					    s.recordcount = n;
					}
				else
					{
						printf("����ļ�¼�������Ϸ�������������\n");
						return ;                           //���� run ���� 
					}
				
				printf("\n�����ļ���:");
				if(scanf("%s",p) != 1)
				  {
				  	  printf("\n�������ݴ���run��������");
				  	  return ;                            //���� run ���� 
				  }
				else
				      strcpy(s.filename , p);             //·���Ѿ߱����ļ���һ���Ϸ������Զ����ϡ�.txt����
			}
			else        //�� y ʱ 
			{
				return ;                                  //���� run ���� 
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
*	��������Configuration
*	���ܣ�Ϊ���ñ�������������ʼ��Ĭ��ֵ
*	������CONF s  ��¼�ļ���Ϣ�Ľṹ�����
*	����ֵ��CONF s  ��¼�ļ���Ϣ�Ľṹ�����
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
*	��������write
*	���ܣ��������ݼ�¼�ļ� 
*	������CONF r  ��¼�ļ���Ϣ�Ľṹ�����
*	����ֵ���� 
*/
void write(CONF r , char w[10])
{
	strcpy(file , r.filename);         //���ļ�������ȫ�ֱ��� 
	
	FILE *fp;

	if((fp=fopen(r.filename , w )) == NULL)      /*ע��˫б��*/   //�������ղ��� 
	  {
		printf("\n�ļ���������write����������");
		return ;                             //���� write ���� 
	  }
	fclose(fp);
	  
	if(freopen(r.filename, w ,stdout) == NULL)
	  {
	  	printf("\n�ļ��򿪴���write����������");
		return ;                             //���� write ���� 	  
	  }
	
	else{
		printf("%d\n",r.recordcount);
	
		srand((int)time(NULL));   //�趨���������
		int i,m,n,p;
		char q[100];
	
		for(i = 0;i < r.recordcount;i++)
		  {
	  		m = RandRanges(r.maxvalue1 , r.minvalue1);
	  		n = RandRanges(r.maxvalue1 , r.minvalue1);
	  		p = RandRanges(r.maxvalue2 , r.minvalue2);
	  	
	  		sprintf(q,"%d,%d,%d",m,n,p);          //ƴ�� 
	  	    printf("%s\n",q);
	      }
    	fclose(stdout);
		}
		
	FILE *fq=freopen("a.out","w",stdout);
    fflush(fq);//��������������
    freopen( "CON", "r", stdin );
	freopen( "CON", "w", stdout ); //�������������̨
    
	return ;
}

/*
*	��������RandRanges
*	���ܣ�����һ��ָ����Χ�ڵ���������ĺ��� 
*	������int a , int b     2��int������ 
*	����ֵ��һ��int������� 
*/
RandRanges(int a , int b)
{
	return rand()%(a - b + 1) + b;
}
