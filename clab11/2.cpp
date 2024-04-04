#include <stdio.h>
struct STUDENT
{
	char name[5],id[10];
	float c,m,e;
};
struct ADV
{
	float chi,mat,eng;
};
ADV cal(STUDENT g[])
{
	float ch=0.0,ma=0.0,en=0.0;
	int a;
	ADV ad;
	for(a=0;a<5;a++)
	{
		ch=g[a].c+ch;
		ma=g[a].m+ma;
		en=g[a].e+en;
	}
	ad.chi=ch/5.0;
	ad.mat=ma/5.0;
	ad.eng=en/5.0;
	return(ad);	
}
int main()
{
	 STUDENT five[5];
	 ADV ad;
	 int a,b,c;//输入name,id,chinese,math,english 
	 for(a=0;a<5;a++)
	 {
	 	printf("输入名字和学号:"); 
	 	gets(five[a].name);
	 	gets(five[a].id);
	 	printf("输入语文数学英语:"); 
	 	scanf("%f%f%f",&five[a].c,&five[a].m,&five[a].e);
	 	getchar();
	 }
	 ad=cal(five);
	 printf("%.2f %.2f %.2f\n",ad.chi,ad.mat,ad.eng);
}