#include<stdio.h>
int max (int a,int  b)
{
  int x;
  if (a >b )
      x = a;
  else 
      x = b;
  return x;
}


int main()
{
  int max(int x,int y);
  int a,b,c;
  scanf("%d,%d",&a,&b);
  c = max(a,b);
  printf("max=%d\n",c);
}
 
