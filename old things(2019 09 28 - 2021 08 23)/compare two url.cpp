#include <stdio.h>
int main()
{
	int i,q=0;
	char a[1000],b[1000];
	printf("please enter two urls:");
	gets(a);
	gets(b);
	for(i=0;a[i]!=NULL&b[i]!=NULL;i++)
	{
		if(a[i]==b[i])
		q=1;
		else
		{
			q=0;
			break;
		}
		
	}
	if(!q)
	printf("there are not the same\n");
	else
	printf("there are the same\n");
	return 0;
}
