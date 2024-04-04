#include<stdio.h>
int main()
{
	int a=1,b=2,c[10],d[10],e=1,f=1;
	for(a=1;a<11;a+=2,b+=2)
	{
		for(e=1;e<=a;e++)
        {
        	if(e==a||e==1)
        	{
        		c[e]=1;
            }
            else
            c[e]=d[e]+d[e-1];
            printf("%6d",c[e]);
        }
		printf("\n");		
		if(b-a==1)
		{
			for(f=1;f<=b;f++)
			{
				if(f==b||f==1)
				{
					d[f]=1;
				}
				else
				d[f]=c[f]+c[f-1];
				printf("%6d",d[f]);
			}
			printf("\n");		    
		}
	}
	return 0;
}
