#include<stdio.h>
#include<math.h>
int main()
{
	int result1,result3;
	float result2;
	result1 = 5*(0x10+12/3)-012+0x2F;
    printf("result1 = %d\n",result1);
    
    result2 = sin(30*3.14159/180)-(int)cos(60*3.14159/180);
    printf("result2 = %f\n",result2);

	result3 = log(pow('z'-'a'+1,2))+log10(pow(10,3));
	printf("result3 = %d\n",result3);
}
