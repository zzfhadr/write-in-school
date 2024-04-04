#include <stdio.h>
int main()
{
	printf("please enter three numbers ");
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)
	{
		if(c>a)
		printf("max%d,min%d",c,b);
		else
		{
			if(b>c)
			printf("max%d,min%d",a,c);
			else
			printf("max%d,min%d",a,b);
		}
	}
	else
	{
		if(c>b)
		printf("max%d,min%d",c,a);
		else
		{
			if(a>c)
			printf("max%d,min%d",b,c);
			else
			printf("max%d,min%d",b,a);
		}
	}
	return 0;
}
