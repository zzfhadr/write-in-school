#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char zifu[100];
char miwen[100];
int k;
int jiami(){
int i;
printf("请输入明文：");
scanf("%s",zifu);
printf("请输入密钥(即k的值):");
scanf("%d",&k);
printf("明文是：%s\n",zifu);
printf("密文是：");
for(i=0; i<strlen(zifu); i++)
{
if(zifu[i]>=97) //小字字母处理 
	{
		char temp=zifu[i];
		int te;
		te=(int)(temp-96);
		if((te+k)%26==0)
		temp='z';
		else
		temp=(char)((te+k)%26+96);
		printf("%c",temp);
	}
	else//大字字母 
	{
		char temp=zifu[i];
		int te;
		te=(int)(temp-64);
		if((te+k)%26==0)
		temp='Z';
		else
		temp=(char)((te+k)%26+64);
		printf("%c",temp);
	}
}
printf("\n");
return 0;
}
int jiemi()
{
int i;
int te;
printf("请输入密文：");
scanf("%s",miwen);
printf("请输入密钥（即k的值）：");
scanf("%d",&k);
printf("密文是：%s\n",miwen);
printf("明文是：");
for(i=0;i<strlen(miwen);i++){
char temp=miwen[i];
if(temp>=97)
{
	te=(int)(temp-96);
	if(((te-k)%26)<=0)
	temp=(char)((te-k)%26+96+26);
	else
	temp=(char)((te-k)%26+96);
	printf("%c",temp);
}
else
{
	te=(int)(temp-64);
	if((te-k)%26<=0)
	temp=(char)((te-k)%26+64+26);
	else
	temp=(char)((te-k)%26+64);
	printf("%c",temp);	
}
}
printf("\n");
return 0;
}
int main()
{
	int a;
	while(1)
	{
		printf("按1加密，按2解密，按3退出");
		scanf("%d",&a);
		if(a==1)
		jiami();
		if(a==2)
		jiemi();
		if(a==3)
		exit(0);
	}
}