#include <stdio.h>
struct STUDENT
{
	char name[5],id[10];
	float c,m,e;
};
int main()
{/*

	FILE *fw;
	fw=fopen("abc.txt","w");
	int a=3,b=2,c=1;
	fprintf(fw,"%d,%d,%d",a,b,c);*/
	STUDENT ex[3];
	printf("%x\n",ex[0].name);
}