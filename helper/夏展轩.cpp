/*
�ӳ���Ϊn������������ɾ��ָ��λ���m��Ԫ�أ�����ԭ˳�����ʣ���Ԫ�ء�
���У�1��m��n��1000��ԭ��������Ϊa��Ҫɾ����Ԫ��λ�����ϸ񵥵������ķ�ʽ�洢������b�У�
����Ԫ��b[i]��ʾҪ��a��ɾ����Ԫ�ص�λ���������ݱ�֤0��b[i]��n-1�� b[i]��b[i+1]��

���磺n=10��m=5��a={46, 7, 27, 50, 71, 79, 21, 56, 18, 77}��b={0, 2, 3, 4, 5}��

��ɾ����õ�����Ϊ{7�� 21�� 56�� 18�� 77 }*/
#include <stdio.h>
int del(int a[],int n,int b)//ɾ����b+1��Ԫ�أ�����a��Ԫ�ظ���Ϊn 
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
	printf("k=%d",k);//kûʲô�ã�ûŪ�õĶ����� 
	return 4;	
}