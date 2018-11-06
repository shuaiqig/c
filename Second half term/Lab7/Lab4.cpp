#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h> 
#define N 100
//·���� ����\��һ��\���ߴ�ʵ��\lab4.exe

typedef struct configinfo{
	char  filesavepath[N] ;      //���ڴ�����ݼ�¼�ļ���Ĭ�ϴ洢Ŀ¼ 
	char  filename[N] ;                    //���ڴ洢���ɵ�Ĭ���ļ�����Ϣ 
	int  maxvalue1 ;     //���ڴ��ʵ��1�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��Ԫ��ֵ������ 
	int  minvalue1;   //���ڴ��ʵ��1�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��Ԫ��ֵ������ 
	int  maxvalue2 ;     //���ڴ��ʵ��1�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��Ԫ��ֵ������ 
	int  minvalue2;   //���ڴ��ʵ��1�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��Ԫ��ֵ������ 
	int  recordcount1; //���ڴ�����ݼ�¼�ļ�����Ҫ���ɵļ�¼�������� 
	int  recordcount2; //���ڴ�����ݼ�¼�ļ�����Ҫ���ɵļ�¼�������� 
	int  recordcount;  //���ڴ�����ݼ�¼�ļ�����Ҫ���ɵļ�¼����
	}CONF;
	
void run(int a , char **c);
CONF Configuration(CONF s);
void write(CONF r);
int RandRanges(int a , int b);

 	
int main (int argc , char* argv[]) 
{ 
	run (argc , argv);      //���ó���������ʵ�ֺ��� 
	return  0 ; 
}

void run(int a , char **c)
{
	CONF s;
	
	s = Configuration(s);       //Ϊ���ñ�������������ʼ��Ĭ��ֵ
	
	switch(a)
	{
		case 3:{
			int b;
			sscanf(c[1] , "%d" , &b);              	         //���ַ���ת����int������
			if(b <= s.recordcount1 && b >= s.recordcount2)   //����������ޣ�С������ 
			{
			    s.recordcount = b;
			}
			else
			{
				printf("����ļ�¼�������Ϸ�������������\n");
				return ;
			}           	
			strcpy(s.filename , c[2]);              //�ļ�����Ϣд��������Ϣ����
			break;                                  //·���Ѿ߱����ļ���һ���Ϸ������Զ����ϡ�.txt���� 
		}
		
		case 2:{
			int b;
			sscanf(c[1] , "%d" , &b);              	        //���ַ���ת����int������
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
				char p[N];
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
	write(s);
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
	freopen("E:\\����\\��һ��\\���ߴ�ʵ��\\conf.ini","r",stdin);
	scanf("%s%s",s.filesavepath,s.filename);
    scanf("%d%d%d%d%d%d",&s.maxvalue1,&s.minvalue1,&s.maxvalue2,&s.minvalue2,&s.recordcount1,&s.recordcount2);
    fclose(stdin);
    
    return s;
}

/*
*	��������write
*	���ܣ��������ݼ�¼�ļ� 
*	������CONF r  ��¼�ļ���Ϣ�Ľṹ�����
*	����ֵ���� 
*/
void write(CONF r)
{
	char c[1024];
	strcat(r.filesavepath , r.filename);   //ƴ�� 	
	strcpy(c , r.filesavepath);
	
	FILE *fp;
	if((fp=fopen(c,"w")) == NULL)      /*ע��˫б��*/   //�������ղ��� 
	  {
		printf("\n�ļ���������write����������");
		return ;                             //���� write ���� 
	  }
	fclose(fp);
	  
	if(freopen(c,"w",stdout) == NULL)
	  {
	  	    printf("\n�ļ��򿪴���write����������");
		    return ;                             //���� write ���� 	  
	  }
	
	else{
		printf("%d\n",r.recordcount);
	
		srand((int)time(NULL));   //�趨���������
		int i,m,n,p;
		char q[N];
	
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
	return;
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
