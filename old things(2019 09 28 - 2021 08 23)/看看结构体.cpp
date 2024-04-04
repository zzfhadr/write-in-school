#include <stdio.h>
struct EF
{
	int a;
	EF *next;
};
int abc(int a)
{
	a=+1;
	return 1;
}
int main(int argc, char *argv[])
{
	int c;
	EF a,*b,t,*f,e;
	a.next=&t;
	t.next=&e;
	for(int i=0;i<2;i++)
	{
		b=a.next;
		f=b->next;
	}	
	return 2;
}