#include "stdio.h"
struct STUDENT
{
    char name[5][12];
    char id[5][12];
    float c[5],m[5],e[5];
};
float cal(float g[])
{
	float b=0.0;
	int a;
	for(a=0;a<5;a++)
	b=g[a]+b;	
	return(b/5.0);	
}
int main()
{
    STUDENT a;
    int i,b;
	float adv[3];    
    printf("please enter evey student's info in turn:name,id,chinese,math,english\n");
    for(i=0;i<5;i++)
    {
    	printf("name and id:");
        gets(a.name[i]);
        gets(a.id[i]);
        printf("please enter three number\n");
        scanf("%f%f%f",&a.c[i],&a.m[i],&a.e[i]);
        getchar();
    }
	adv[0]=cal(a.c);
	adv[1]=cal(a.m);
	adv[2]=cal(a.e);
    printf("%f %f %f",adv[0],adv[1],adv[2]);
	return 0;

}
