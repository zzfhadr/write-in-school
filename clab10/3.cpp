#include"stdio.h"
 int main()//1���䡣2����ÿ���ַ����ĳ��ȡ�3���Ƚϳ���ģ��������ˡ� 
{
	int x,y,len[20],aofstr,b;//lenÿ��ĳ���,aofstr������x�ڼ��� 
	char a[20][100];
	for(x=0,y=0;scanf("%d",&y)!=EOF;x++)//����ctrl+z��win����f6���µ�һ��ֹͣ���� 
	{
		gets(a[x]);
	}
	aofstr=x;
	//printf("%d",x);	
	for(;x>-1;x--)
	{				
		len[x]=0;
		for(y=0;;y++)
		{
			if(a[x][y]!='\0')//��ʵy��ֵ����1���Ƕ�Ӧ��x����ַ��� 
			len[x]++;
			else
			break;
		}							
	}
 	for(x=0,b=1;b<aofstr;b++)
 	{
 		if(len[x]>len[b]);
		else
		x=b;	
 	}//�������һ����xΪ���һ�� 
 	printf("��ַ����ĳ���Ϊ:%d\n����ַ����ǣ�\n",len[x]);
 	for(b=x;len[x]==len[b]&&b>-1;b--) 	
 	puts(a[b]);
	//puts(a[aofstr]);			
}