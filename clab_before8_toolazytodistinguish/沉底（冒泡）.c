#include<stdio.h>
int uuu(int a[10])
{
	int c,d,f;
	for(d=0;d<10;d++)
	{
	for(c=d+1;c<10;c++)
	if(a[d]>a[c])
	{
		f=a[c];
		a[c]=a[d];
		a[d]=f;
	}
	for(c=0;c<10;c++)
	printf("%2d ",a[c]);
	printf("\n");
	}
	return 0;
	
}
int main()
{
	int a[10]={45,3,7,5,88,9,6,12,34,2};
	uuu(a);
	return 0;

}
