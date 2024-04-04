#include <stdio.h>
#include<string.h>
char key[6]="cipher";//选择密钥
int* shun()
{
	int i,k,te;
	static int temp[6];
	int t[6]={};
	for(i=0;i<6;i++)
	{
		temp[i]=(int)(key[i]-97);
		t[i]=temp[i];
	}
	for(i=0;i<6;i++)
	{	
		for(k=0;k<5;k++)
		{
			if(t[k]>=t[k+1])
			{
				te=t[k];
				t[k]=t[k+1];
				t[k+1]=te;	
			}
		}
	}
	for(i=0;i<6;i++)
	{
		for(k=0;k<6;k++)
		{
			if(temp[i]==t[k])
			temp[i]=k;
		}
	}

return temp;
}
int jiami()
{
	char zifu[100]="\0";
	char te[6];
	char juz[18][6];
	int i,k,l,temp;
	int * p;
	printf("输入明文："); 
	scanf("%s",zifu);
	p=shun();	
	for(i=0;i<strlen(zifu);i++)
	{
		temp=(int)i/6;
		juz[temp][i%6]=zifu[i];
	}
	temp=strlen(zifu)/6;
	for(i=0;i<temp;i++)
	{
		for(l=0;l<6;l++)
		{
			te[l]=juz[i][l];
		}
		for(k=0;k<6;k++)
		{
			juz[i][p[k]]=te[k];
			
		}	
	}
	printf("密文：");
	for(i=0;i<6;i++)
	{
		for(k=0;k<temp;k++) 
		printf("%c",juz[k][i]);
	}
	printf("\n");
	return 0;	
}
int jiemi()
{
	char zifu[100];
	char te[6];
	char juz[18][6];
	int i,k,l,temp;
	int * p;
	printf("输入密文："); 
	scanf("%s",zifu);
	p=shun();	
	temp=(int)strlen(zifu)/6;//得到行数temp的值
	for(i=0;i<6;i++)
	{
		for(k=0;k<temp;k++)
		{
			juz[k][i]=zifu[temp*i+k];
		}
	}
	for(i=0;i<temp;i++)
	{
		for(l=0;l<6;l++)
		{
			te[l]=juz[i][l];
		}
		for(k=0;k<6;k++)
		{
			juz[i][k]=te[p[k]];			
		}	
	}
	printf("明文：");
	for(i=0;i<temp;i++)
	{
		for(k=0;k<6;k++) 
		printf("%c",juz[i][k]);
	}
	printf("\n");
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
	return 0;
}
