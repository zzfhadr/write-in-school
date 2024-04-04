#include<stdio.h>
int jiecheng(int a)
{
	if(a==0)
	return 1;
	else 
	return (a*jiecheng(a-1));
}
int main()
{
	int line,a,b,c,n;
    scanf("%d",&line);
    for(n=0;n<line;n++)
    {
      printf("\n");
      for(b=0;b<=n;b++)
       {
	      a=jiecheng(n)/jiecheng(n-b)/jiecheng(b);
	      printf("%6d",a);	
       }	
    }	
} 