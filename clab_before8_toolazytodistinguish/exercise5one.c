#include <stdio.h>
int main()
{
	int i,a;
	for(i=1;i<4;i++)
	{
	printf("\n");	
	
	for(a=1;a<4;a++)
		if((i>(2-a))&&(i<(a+2))&&(i<(6-a))&&(i>(a-2)))
	printf(" *");
	else
	printf("  ");
	}
	printf("\n");
}
