// 20181.cpp : Defines the entry point for the console application.

#include<stdio.h>

int main()
{   
    int a[3][3] = {{1,2,3},{3,4,5},{5,6,7}};
    int i,j,temp;
    int (*p)[3] = a;          //  ���� *p = {1,2,3}
    int *q = a[0];            //       *q = 1
    for (i = 0; i < 3; i++)
	{   for(j = i+1; j < 3; j++)
	   {   temp = *(*(p+j)+i);
	        *(*(p+j)+i) = *(q+j); 
	        *(q+j) = temp;
	    }
	    q = q + (i + 1)*3;              //  i  �� i + 1
                               //   *p = {1,3,6}    *q = 6
    }
    

	  for (i = 0; i < 3; i++)              //������վ��� 
	  {   for (j = 0; j < 3; j++)
             printf("%d ", a[i][j]);
            printf("\n");
          }    

	return 0;
}


