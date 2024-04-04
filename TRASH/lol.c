#include<stdio.h>
int main()
{
	float x;
	scanf("%f",&x);
	int i=0;
	for(;;i++)
	{
		x=x+(125.0+x*0.06)*0.1;
		if(x>2104552192.0)
			break;
	}
	

printf("%f\n",x );
printf("iiiii:%d\n",i);
}