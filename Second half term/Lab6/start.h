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


void start(int date[][3], int n);

void ResponseAdd(RESPONSELISTNODE **ph, RESPONSELISTNODE *pl);        //��ӵ�����Ӧָ�����

void ServeListAdd(SERVELISTNODE **p,  SERVELISTNODE *pn);             //��ӵ���ǰ����ָ�����

void doyouwork();

void ResponseCut(RESPONSELISTNODE **ph, RESPONSELISTNODE **pt);

void ResponseCut2(RESPONSELISTNODE **p);

void ServeListCut(SERVELISTNODE **p);

void ChangeToE(SERVELISTNODE **p);

void Process1_ride();

void Process2_judge();



#endif
