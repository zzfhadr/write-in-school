#include <stdio.h>
#include <stdlib.h>
struct SF
{
	int a,b,c;
};
int main(int argc, char *argv[])
{
	SF *pt,d[4];
	pt=(SF * ) malloc(2 * sizeof( SF));//���飿���൱�ڶ�������� 
	printf("%d,%d\n",sizeof(SF),sizeof(d[4]));
	return 0;
}