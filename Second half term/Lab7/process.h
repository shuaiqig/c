#ifndef CODEFORPROCESS_H_  
#define CODEFORPROCESS_H_

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
