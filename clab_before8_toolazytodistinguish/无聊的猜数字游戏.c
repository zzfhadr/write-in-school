#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int game()
{
	int a,b,c,d;
	srand(time(NULL));
		a=rand()%101+50;
	for(c=1;c<11;c++)
	{

	printf("wftcqqc！\n"); 
	scanf("%d",&b);
	d=a-b;
	if(d==0)
	return (c);
	else
	{
		if(d>0)
		printf("smaller\n");
		else
		printf("bigger\n");
	}
	if(c==10)
	return 11;		
	}	
}
int score(int x);
int main()
{
   int a,b;
   printf("dagainezhixing\n");
   a=game();
   b=score(a);
   printf("您的分数是%d\n",b);
   return 0;	
}
int score(int x)
{ 
	switch(x)
	{
	case 1:
	return 100;
	break;
	case 2:
	return 90;
	break;
	case 3:
	return 80;
	break;
	case 4:
	return 70;
	break;
	case 5:
	return 60;
	break;
	case 6:
	return 50;
	break;
	case 7:
	return 40;
	break;
	case 8:
	return 30;
	break;
	case 9:
	return 20;
	break;
	case 10:
	return 10;
	break;
	case 11:
	return 0;
	}
}