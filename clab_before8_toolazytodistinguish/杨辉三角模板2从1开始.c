#include<stdio.h>
int main()
{
	int a[20],i,j,n;
	scanf("%d",&n);
	if(n==1) 
		printf("1\n");
	else
	{
        a[1]=a[2]=1;//不想写了bye！ 
		printf("1\n1    1\n"); 
		for(i=3;i<=n;i++)
		{
			a[i]=1;//最后一个数为1 
			for(j=i-1;j>1;j--)//j>1:第一个数直接为1，j=i-1: 
				a[j]=a[j]+a[j-1];
		for(j=1;j<=i;j++)//j<=i: 
			printf("%-5d",a[j]);
		printf("\n");
		}
	}
	return 0;
 } 
		