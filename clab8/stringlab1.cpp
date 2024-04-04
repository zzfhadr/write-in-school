#include"stdio.h"
int dtob(int a)
{
    int b,c,d;
    char w[54],n[54];
     for(b=0;a!=0;b++) 
    {
        if(a%2==0)
        w[b]='0';
        else
        w[b]='1';
        a/=2;
    }
    w[b]='\0';
    puts(w);//ÎÞ¹Ø½ôÒª 
    for(c=0;b!=0;c++,b--)
    n[c]=w[b-1];
    n[c]='\0';
    puts(n);
    return 5;
}
int main()
{
    int a;
    scanf("%d",&a);
    dtob(a);
    return 0;
}
