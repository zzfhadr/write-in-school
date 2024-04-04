#include<stdio.h>
int main()
{
	int a[11],b;
	a[0]=a[1]=1;
	for(b=2;b<12;b++)
	a[b]=a[b-2]+a[b-1];
	for(b=0;b<12;b++)
	printf("%d  ",a[b]);
	printf("\n");
	return 0;
}