#include<stdio.h>
int main()
{
	int a[10]={1,3,5,7,8,10,22,33,43,45};
	int b=0,c=9,d,e,f;
	printf("������Ҫ���ҵ�ֵ:\n");
	scanf("%d",&d);
	for(;b<c;)
	{
		e=(b+c)/2;
		if(a[e]<d)
		b=e+1;
		if(a[e]>d)
		c=e-1;
		f=(b+c)/2;//��֤b��c�ı��Ҳ�Ƚ���a[f]�Ƿ����d 
		if(a[f]==d||a[e]==d)
		{
			if(a[f]==d)
           printf("��ֵ�ǵ�%d��\n",f+1);
           if(a[e]==d)
           printf("��ֵ�ǵ�%d��\n",e+1);
           break;
		}
	}
	if(c<d&&a[f]!=d&&a[e]!=d)
	printf("��ֵ������\n");
	return 0;
} 
