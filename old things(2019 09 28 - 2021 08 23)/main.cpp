/*输出最长字符串*/
#include<stdio.h>
#include<stdlib.h>//用于system("pause")，写报告的时候记得删掉
#include<string.h>
int main()
{
	char str[100][101];
	int i=0,j=0,len=0,index[100],size=0;//len用来存储最长字符串的长度，index[100]用来存储所有最长字符串的位置，j表示最长字符串的个数-1，size表示字符串的个数
	do//防止用户输入100以上字符
	{
		scanf("%d",&size);//由用户决定字符串个数
		if(size>100)
			puts("\ntoo long,please enter a smaller size");//如果用户想输入100个以上字符串，令其重新输入
	}while(size>100);
	for(i=0;i<=size;i++)
	{
		gets(str[i]);
		if((int)strlen(str[i])>len)//如果有更大的字符串
		{
			len=strlen(str[i]);//把最大长度保存在len中
			j=0;//并且把j归零
			index[j]=i;//把当前字符串的编号i存进index[j]
		}
		else if((int)strlen(str[i])==len)//如果找到了其它的最长字符串
		{
			j++;
			index[j]=i;	//则将当前字符串的编号i存进index的下一个位置
		}
	}
	printf("The largest length is %d\nThe longest string(s) are:\n",len);
	for(i=0;i<=j;i++)
		puts(str[index[i]]);//输出所有最长字符串
	system("pause");//此行写报告的时候记得删掉
	return 0;
}
