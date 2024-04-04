#include <stdio.h>
int main(int argc, char *argv[])
{
	char a[10];
	while(scanf("%s",a)!=EOF)
	printf("ÄúµÄ£º%s£¬ÄÃºÃ\n",a);
	printf("end of file\n");
	return 0;
}