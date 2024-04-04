#include <stdio.h>
int main ()
{
    char a[321],*b=&a[0],*c,f;
    int d,e;
    gets(a);
    for(d=0;a[d]!='\0';d++);
    c=&a[d-1];
    for(;b!=c&&(c-b)!=1;b++,c--)
    {
         f=*b;
         *b=*c;
         *c=f;
    }
    puts(a);
    return 0;
}
