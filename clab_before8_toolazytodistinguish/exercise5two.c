#include <stdio.h>
int main()
{
	int a,i,l;
	printf("the number of '*' in the longest line!(一定要为奇数)");
	scanf("%d",&l);
	for(a=1;a<(l+1);a++)
	{
		printf("\n            ");
		for(i=1;i<(l+1);i++)
		if((a<i+(l+1)/2)&&(a<-i+(3*l+3)/2)&&(a>i-(l+1)/2)&&(a>-i+(l+1)/2))
		printf(" *");
		else
		printf("  ");
	}
	printf("\n\n\n");
	return 0;
}
