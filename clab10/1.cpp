#include <stdio.h>
int turn(char f[])
{
    int b,d,e,i,c;
    for(i=0;f[i]!='\0';i++);
    for(b=0,i=i-1;b!=i&&((i-b)!=1);b++,i--)
    {
        c=f[b];
        f[b]=f[i];
        f[i]=c;
    }
    puts(f);
    return 0;
}
int main()
{
    char  a[242];
    gets(a);
    turn(a);
    return 0;

}
