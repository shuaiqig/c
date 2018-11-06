/*结构体统计不及格人数*/ 
#include<stdio.h>
#define n 3
typedef struct
	{
      char N[20];  //姓名
      double S[2]; //两门课的成绩
    } STUD;        /*　 在C中，这个申明后申请结构变量的方法有两种：
　　　　               （1）struct 变量名
　　　　               （2）STUD 变量名             */
STUD s[n];

int FailNum(STUD *p,int m)
{
	int k = 0;
	for(p = s;p < (s+m);p++)
	   if((*p).S[0] < 60 || (*p).S[1] < 60)      k++;
	return k;
}

int main()
{
	int i,j,m = n;
    for(i = 1;i <= n;i++)
       {
        	printf("请输入第%d个学生成绩 名字：",i);
        	scanf("%lf%lf%s",&s[i].S[0],&s[i].S[1],s[i].N);
	   }
	printf("\n不及格人数为：%d\n",FailNum(s,m));
	
	return 0;
}
