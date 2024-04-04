#include <stdio.h>
float cal(float g[])
{
	float b=0.0;
	int a;
	for(a=0;a<5;a++)
	b=g[a]+b;	
	return(b/5.0);	
}
struct AI
{
	int a;
	float b;
};
AI  zhi(AI nan)
{
	nan.a=1;
	nan.b=1.0;	
	return nan;
}
int main(int argc, char *argv[])
{
/*	float a;
	scanf("%f",&a);
	printf("%f\n",a);*/
	AI play,hi;
	play.a=2;
	play.b=2.0;
	hi=zhi(play);
	printf("%d %f\n",play.a,play.b);
	printf("%d %f\n",hi.a,hi.b);	
	return 0;
}