#include<stdio.h>
int kkk(int a[])
{
	int b,c,*d,f;

	for(c=0;c<9;c++)
	{
	    d=&a[9];
	    for(b=9;b>(c-1);b--)
	    {
	        if(a[b]<*d)
            d=&a[b];
	    }
     f=a[c];
	 a[c]=*d;
	 *d=f;	
	 for(b=0;b<10;b++)
	 printf("%2d ",a[b]);
	 printf("\n");
	}
	return 0;	
}
int main()
{
	int a[10]={45,3,7,5,88,9,6,12,34,2};
	kkk(a);
	return 0;
}
