#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char zifu[100];
char miwen[100];
int k;
int jiami(){
int i;
printf("���������ģ�");
scanf("%s",zifu);
printf("��������Կ(��k��ֵ):");
scanf("%d",&k);
printf("�����ǣ�%s\n",zifu);
printf("�����ǣ�");
for(i=0; i<strlen(zifu); i++)
{
if(zifu[i]>=97) //С����ĸ���� 
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
	else//������ĸ 
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
printf("���������ģ�");
scanf("%s",miwen);
printf("��������Կ����k��ֵ����");
scanf("%d",&k);
printf("�����ǣ�%s\n",miwen);
printf("�����ǣ�");
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
		printf("��1���ܣ���2���ܣ���3�˳�");
		scanf("%d",&a);
		if(a==1)
		jiami();
		if(a==2)
		jiemi();
		if(a==3)
		exit(0);
	}
}