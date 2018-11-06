#ifndef CODEFORSTART_H_  
#define CODEFORSTART_H_


//用户请求信息结构体
typedef  struct  UserCall{
    int  user_floor ;        //用户所在楼层 
    int  user_target ;     //用户目标楼层 
    int  call_time ;         //用户请求时刻 
    char  call_type ;       //用户请求类型，′U′表示上行指令，′D′表示下行指令
  }USERCALL;

//待响应指令队列链表结点结构体
typedef struct ResponseListNode{ 
    USERCALL  *user_call ;       //用户指令在指令数组中对应的序号 
	struct ResponseListNode *next_node;//存储下一个结点的地址 
  }RESPONSELISTNODE;
  

//链表头结点数据结构体声明
typedef  struct  ResponseListHeadNode{ 
    int  list_num ;       //待响应用户指令链表中数据结点的个数 
	RESPONSELISTNODE  *head ;//链表中第一个数据结点的指针 
	RESPONSELISTNODE  *tail ;//链表中最后一个数据结点的指针 
  }RESPONSELISTHEADNODE;


//当前服务指令队列链表结点结构体
typedef  struct  ServeListNode{
    char  serve_state ;       //电梯服务状态 
    USERCALL  *user_call ;   //电梯当前响应用户指令时，指向指令数组的某一个元素 
	struct ServeListNode  *next_node ;  //存储下一个结点的地址 
  }SERVELISTNODE;


//电梯状态结构体，保存此电梯的各项状态信息
typedef  struct  elevatorstate{ 
    int  current_floor ;      //电梯当前所处楼层 
	char  run_state ;          //电梯运行状态 
	SERVELISTNODE  *serve_list;  //电梯当前服务指令队列指针 
  }ELEVATORSTATE; 


void start(int date[][3], int n);

void ResponseAdd(RESPONSELISTNODE **ph, RESPONSELISTNODE *pl);        //添加到待相应指令队列

void ServeListAdd(SERVELISTNODE **p,  SERVELISTNODE *pn);             //添加到当前服务指令队列

void doyouwork();

void ResponseCut(RESPONSELISTNODE **ph, RESPONSELISTNODE **pt);

void ResponseCut2(RESPONSELISTNODE **p);

void ServeListCut(SERVELISTNODE **p);

void ChangeToE(SERVELISTNODE **p);

void Process1_ride();

void Process2_judge();



#endif
