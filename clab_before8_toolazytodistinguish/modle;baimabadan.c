#include "stdio.h"
int main( void )
{
int m,n,k;
int sum=0;
printf("�����Է�����:\n");
for(m=1;m<=100/3;m++ )
for(n=1;n<100/2;n++)
{
k=100-m-n;
if((2*3*m+2*2*n+k)==2*100)
{
printf("����%3dƥ;����%3dƥ;С��%3dƥ.\n",m,n,k);
sum++;
}
}
printf("����%d���Է�.",sum);
return 0;
}
