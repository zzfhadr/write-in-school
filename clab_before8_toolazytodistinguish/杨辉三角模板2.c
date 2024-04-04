#include<stdio.h>
int main()
{
	int a[20];
	int i,j;
	int n;
	scanf("%d",&n);
	if(n==1) 
		printf("1\n");
	else
	{
		a[0]=a[1]=a[2]=1;
		printf("1\n1    1\n"); 
		for(i=3;i<=n;i++)
		{
			a[i-1]=1;/*他的每一行都是从零开始，所以要把行数减一*/ 
			for(j=i-2;j>0;j--)
				a[j]=a[j]+a[j-1];
			//a[0]=1;  /*这是原作者有的一步好像没用*/ 
		for(j=0;j<i;j++) 
			printf("%-5d",a[j]);
		printf("\n");
		}
	}
	return 0;
 } 
		