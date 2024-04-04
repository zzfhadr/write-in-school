#include <stdio.h> 
int main()
{
	int n,a[50000],zw[50000],m=0,x,j,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		if(a[i]==a[j])
		zw[i]++;
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",zw[i]);
	}
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			if(zw[i]>=zw[j])
			{
				m=zw[i];
				x=i;
				//printf("%d ",m);
			}
			else 
			{
				m=zw[i];
				zw[i]=zw[j];
				zw[j]=zw[i];
				x=j;
				//printf("%d ",m);
			}						
		} 
	printf("%d %d\n",a[x],zw[i]);
}
