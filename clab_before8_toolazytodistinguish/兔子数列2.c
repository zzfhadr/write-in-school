#include<stdio.h>
int fff(int a)
{
	if(a==1||2==a)
	return (1);
	else
	return (fff(a-1)+fff(a-2));
}
int main()
{
	int a[11],b;
	for(b=1;b<13;b++)
	printf("%4d",fff(b));
	return 0;
}