/*¶Á³ÌĞòĞ´½á¹û*/ 
#include<stdio.h>
int f1(int );
int f2(int );

int main()
{ 
	int i;
	for(i = 2 ; i < 5 ; i++)    
		printf ("f1(%d) = %d \t ", i , f1(i));
	printf("\n");
	for(i = 2 ; i < 5 ; i++)    
		printf ("f2(%d) = %d \t ", i , f2(i));
	printf("\n");
	return 0;
}

int  f1(int x)
{ 
	int f = 1;
	f *= x;                  /*¼´ f = f*x */
	return  f;
}

int  f2(int x)
{ 
	static int f = 1;
	f *= x;
	return  f;
}

