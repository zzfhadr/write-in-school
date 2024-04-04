#include <stdio.h>
int main()
{
	double o,wheat,i;
     wheat=1.0/2.0;
	for(i=1;i<65;i++)
	{
   	wheat=wheat*2.0;
    o=wheat+o;
	printf("%30lf%30lf\n",o,wheat);
	}
	wheat=o/140000000.0;
	printf("国王将给%f立方米小麦\n",wheat);
	return 0;
}
