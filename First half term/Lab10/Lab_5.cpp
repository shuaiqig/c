/*�ṹ��ͳ�Ʋ���������*/ 
#include<stdio.h>
#define n 3
typedef struct
	{
      char N[20];  //����
      double S[2]; //���ſεĳɼ�
    } STUD;        /*�� ��C�У��������������ṹ�����ķ��������֣�
��������               ��1��struct ������
��������               ��2��STUD ������             */
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
        	printf("�������%d��ѧ���ɼ� ���֣�",i);
        	scanf("%lf%lf%s",&s[i].S[0],&s[i].S[1],s[i].N);
	   }
	printf("\n����������Ϊ��%d\n",FailNum(s,m));
	
	return 0;
}
