#include <stdio.h>  //猜英语完型填空，试了两次，对的题都在五题及以上。真好。 
#include <stdlib.h>//直接运行。 
#include <time.h>
int main()
{	
	int a[20],i,c;
	char b[20][1];
	srand(time(NULL));
	for(i=0;i<20;i++)
	a[i]=(rand())%4;
	for(i=0;i<20;i++)
	{
		for(c=0;c<4;c++)
		if(a[i]==c)
		b[i][1]='A'+c;		
	}
	for(i=0;i<20;i++)
	{
		printf("%c",b[i][1]);
		if((i+1)%5==0)
		printf("\n");
	}
}