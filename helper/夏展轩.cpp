/*
从长度为n的整数序列中删除指定位序的m个元素，按照原顺序输出剩余的元素。
其中，1≤m≤n≤1000，原整数序列为a；要删除的元素位序按照严格单调递增的方式存储在序列b中，
其中元素b[i]表示要从a中删除的元素的位序，输入数据保证0≤b[i]≤n-1， b[i]＜b[i+1]。

例如：n=10，m=5，a={46, 7, 27, 50, 71, 79, 21, 56, 18, 77}，b={0, 2, 3, 4, 5}，

则删除后得到序列为{7， 21， 56， 18， 77 }*/
#include <stdio.h>
int del(int a[],int n,int b)//删掉第b+1个元素，数组a的元素个数为n 
{
	int c[1000],i,j=0;
	for(i=0;i<n;i++)
	{
		if(i==b)
		j--;
		else
		c[j]=a[i];
		j++;
	}
	for(i=0;i<(j+1);i++)
	{
		a[i]=c[i];
	}
	return j;
}
int main()
{
	int m,n,i,j,k,g;
	printf("enter n and m:");
	scanf("%d%d",&n,&m);
	i=n-m;
	j=i;
	g=n;
	if(i==0)
	printf("son of bitch");
	else
	{
		int a[n],b[m];
		printf("enter a:");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("enter b:");
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
		}
		for(i=0;i<m;i++)
		{
			k=del(a,g,b[i]);
			b[i+1]--;
			g--;
		}
		for(i=0;i<j;i++)
		printf("%d ",a[i]);
	}
	printf("k=%d",k);//k没什么用，没弄好的东西。 
	return 4;	
}