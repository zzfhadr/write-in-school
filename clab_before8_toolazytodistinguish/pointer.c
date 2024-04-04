#include<stdio.h>
int main()
{
	int *ptDd,d,*ptBb;
	scanf("%d",&d);
	
	ptBb= &*ptDd;
	ptDd= &d;
	*ptDd=d;
	printf("%x  %x %d\n",ptDd,ptBb,*ptDd);
}