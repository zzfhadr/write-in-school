#include<stdio.h>
int main ()
{
    char a[144];
    int  b,c,d,e;
    for(e=0;scanf("%c",&a[e])!=EOF;e++);
    a[e]='\0';
    for(b=0,c=0,d=0;a[b]!='\0';b++)
    {
        if(a[b]==' ')
        c++;
        if(a[b]=='\n')
        {
			d++;			
			c++;
        }	
    }
	b=b-d;
    printf("��%d�С�%d���ַ���%d������\n",d,b,c);
    puts(a);
    return 0;
}

