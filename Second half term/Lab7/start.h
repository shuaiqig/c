#ifndef CODEFORSTART_H_  
#define CODEFORSTART_H_


//�û�������Ϣ�ṹ��
typedef  struct  UserCall{
    int  user_floor ;        //�û�����¥�� 
    int  user_target ;     //�û�Ŀ��¥�� 
    int  call_time ;         //�û�����ʱ�� 
    char  call_type ;       //�û��������ͣ���U���ʾ����ָ���D���ʾ����ָ��
  }USERCALL;

//����Ӧָ�����������ṹ��
typedef struct ResponseListNode{ 
    USERCALL  *user_call ;       //�û�ָ����ָ�������ж�Ӧ����� 
	struct ResponseListNode *next_node;//�洢��һ�����ĵ�ַ 
  }RESPONSELISTNODE;
  

//����ͷ������ݽṹ������
typedef  struct  ResponseListHeadNode{ 
    int  list_num ;       //����Ӧ�û�ָ�����������ݽ��ĸ��� 
	RESPONSELISTNODE  *head ;//�����е�һ�����ݽ���ָ�� 
	RESPONSELISTNODE  *tail ;//���������һ�����ݽ���ָ�� 
  }RESPONSELISTHEADNODE;


//��ǰ����ָ�����������ṹ��
typedef  struct  ServeListNode{
    char  serve_state ;       //���ݷ���״̬ 
    USERCALL  *user_call ;   //���ݵ�ǰ��Ӧ�û�ָ��ʱ��ָ��ָ�������ĳһ��Ԫ�� 
	struct ServeListNode  *next_node ;  //�洢��һ�����ĵ�ַ 
  }SERVELISTNODE;


//����״̬�ṹ�壬����˵��ݵĸ���״̬��Ϣ
typedef  struct  elevatorstate{ 
    int  current_floor ;      //���ݵ�ǰ����¥�� 
	char  run_state ;          //��������״̬ 
	SERVELISTNODE  *serve_list;  //���ݵ�ǰ����ָ�����ָ�� 
  }ELEVATORSTATE; 

struct Summary{
	int All;
	int Up;
	int Down;
	int Road;
};

extern int t;  //ʱ����ȫ�ֱ��� 

extern ELEVATORSTATE d;   //����״̬�ṹ�壬����˵��ݵĸ���״̬��Ϣ

extern RESPONSELISTNODE *PHead;   //����Ӧָ���������  ͷ���

extern SERVELISTNODE *now;     //��ǰ����ָ�����������ṹ��

extern SERVELISTNODE *pn;

extern SERVELISTNODE **pn2;

extern SERVELISTNODE **rn;

extern RESPONSELISTHEADNODE *Head;   //����ͷ������ݽṹ������

extern Summary s;             //�洢��Ҫ��Ϣ 

void start_1(int date[][3], int n);

void start_2(int date[][3], int n);

void start_3(int date[][3], int n);

void start_4(int date[][3], int n, int m, int mi, FILE *fp);

void PutServeList();

void PutServeList_2(FILE *fp);

#endif
