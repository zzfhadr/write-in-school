int cube(int a)
{
	return(a*a*a);
};
#include <stdio.h>
int main()
{
	int a,b,c,d,m,n,f;
	printf("enter m and n:");
	scanf("%d%d",&m,&n);
	int i[n-m+1];
	for(a=m,f=0;a<=n;a++)
	{
		d=(a%100)%10;
		c=(a%100-d)/10;
		b=(a-c*10-d)/100;
		if(a==(cube(b)+cube(c)+cube(d)))
	{
		i[f]=a;		
		f++;
	}
	}
	printf("f:%d\n",f);
	if(f==0)
	printf("no\n");
	else
	for(a=0;a<f;a++)
	printf("%d\n",i[a]);
	return 0;
	}
