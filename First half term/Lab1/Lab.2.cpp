#include<stdio.h>
int add(int x,int y)
{
  int z;
  z=x+y;
  return z;
}
  int main()
{
  int i1,i2,sum;
  printf("��������������");
  scanf("%d,%d",&i1,&i2); 
  sum=add(i1,i2);
  printf("sum=%d\n",sum);
}
