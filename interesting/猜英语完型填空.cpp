#include <stdio.h>  //��Ӣ��������գ��������Σ��Ե��ⶼ�����⼰���ϡ���á� 
#include <stdlib.h>//ֱ�����С� 
#include <time.h>
int main()
{	
	int a[20],i,c;
	char b[20][1];
	srand(time(NULL));
	for(i=0;i<20;i++)
	a[i]=(rand())%4;
	for(i=0;i<20;i++)
	{
		for(c=0;c<4;c++)
		if(a[i]==c)
		b[i][1]='A'+c;		
	}
	for(i=0;i<20;i++)
	{
		printf("%c",b[i][1]);
		if((i+1)%5==0)
		printf("\n");
	}
}