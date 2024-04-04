#include<stdio.h>
int main()
{
	int a[10]={1,3,5,7,8,10,22,33,43,45};
	int b=0,c=9,d,e,f;
	printf("请输入要查找的值:\n");
	scanf("%d",&d);
	for(;b<c;)
	{
		e=(b+c)/2;
		if(a[e]<d)
		b=e+1;
		if(a[e]>d)
		c=e-1;
		f=(b+c)/2;//保证b，c改变后也比较了a[f]是否等于d 
		if(a[f]==d||a[e]==d)
		{
			if(a[f]==d)
           printf("该值是第%d个\n",f+1);
           if(a[e]==d)
           printf("该值是第%d个\n",e+1);
           break;
		}
	}
	if(c<d&&a[f]!=d&&a[e]!=d)
	printf("该值不存在\n");
	return 0;
} 
