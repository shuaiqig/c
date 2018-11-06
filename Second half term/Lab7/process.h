#ifndef CODEFORPROCESS_H_  
#define CODEFORPROCESS_H_

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
