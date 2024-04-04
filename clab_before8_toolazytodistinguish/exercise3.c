#include "stdio.h"
int main()
{
	int a,b,c;
		printf("大马 中马 小马\n");
	for(a=0;a<101.0;a++)
	for(b=0;b<101.0;b++)
{
	c=100.0-a-b;	
	if(3.0*a+2.0*b+1.0/2.0*c==100.0)
	printf("%2d   %2d   %2d \n",a,b,c);
}
	return 0;
}
