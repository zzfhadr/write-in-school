#include <stdio.h>
#include <stdlib.h>
struct ADV
{
	float chi,mat,eng;
};
struct LIST
{
	char id[11],name[12];
	float c,m,e;
	LIST 	*next;	
};
ADV cal(LIST *p)
{
	float ch=0.0,ma=0.0,en=0.0;
	ADV ad;
	for(;p!=NULL;)
	{
		ch=p->c+ch;
		ma=p->m+ma;
		en=p->e+en;
		p=p->next;
	}
	ad.chi=ch/5.0;
	ad.mat=ma/5.0;
	ad.eng=en/5.0;
	return(ad);	
}
int main()
{
	int i;
	LIST *first,*pt,*p;
	ADV ad;
	first=(LIST *)malloc(sizeof(LIST));
	pt=first;
	for(i=0;i<5;i++)
	{
		printf("请按顺序输入名字和学号："); 
		gets(pt->name);
		gets(pt->id);
		printf("请按顺序输入语数英成绩:");
		scanf("%f%f%f",&pt->c,&pt->m,&pt->e);
		getchar();	
		pt->next=(LIST *)malloc(sizeof(LIST));
		p=pt;
		pt=pt->next;			 	
	}
	free(p->next);
	p->next=NULL;
	ad=cal(first);
 	printf("%.2f %.2f %.2f\n",ad.chi,ad.mat,ad.eng);
 	for(;first!=NULL;)
 	{
		free(first);
		first=first->next;	
 	}
	return 0;		
}