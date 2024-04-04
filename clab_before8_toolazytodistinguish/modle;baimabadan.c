#include "stdio.h"
int main( void )
{
int m,n,k;
int sum=0;
printf("各种驮法如下:\n");
for(m=1;m<=100/3;m++ )
for(n=1;n<100/2;n++)
{
k=100-m-n;
if((2*3*m+2*2*n+k)==2*100)
{
printf("大马%3d匹;中马%3d匹;小马%3d匹.\n",m,n,k);
sum++;
}
}
printf("共有%d种驮法.",sum);
return 0;
}
