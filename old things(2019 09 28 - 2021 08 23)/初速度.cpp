#include <stdio.h>
#include <math.h>
int main()
{
	double v,s,c,pi=3.1415926535;
	printf("������Ƕ����������:"); 
	scanf("%lf%lf",&c,&s);
	v=sqrt((s*9.8)/sin((4*pi/360)*c));
	printf("%lf\n",v);
	return 0;
}
