#include<stdio.h>
int digui(int a)
{
    if(1==a)
    	return 1;
   	else
   		return digui(a-1)*a;
}
int main()
{
	int a,b;
	scanf("%d",&a);
	b=digui(a);
	printf("%d\n",b);
	return 0;
}
