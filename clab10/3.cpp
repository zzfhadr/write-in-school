#include"stdio.h"
 int main()//1、输。2、算每组字符串的长度。3、比较出大的，就是它了。 
{
	int x,y,len[20],aofstr,b;//len每组的长度,aofstr组数，x第几组 
	char a[20][100];
	for(x=0,y=0;scanf("%d",&y)!=EOF;x++)//输入ctrl+z（win）或f6在新的一行停止输入 
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
			if(a[x][y]!='\0')//其实y的值加上1就是对应的x组的字符数 
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
 	}//如果多组一样长x为最后一组 
 	printf("最长字符串的长度为:%d\n最长的字符串是：\n",len[x]);
 	for(b=x;len[x]==len[b]&&b>-1;b--) 	
 	puts(a[b]);
	//puts(a[aofstr]);			
}