#include <iostream.h>
class level
{
public:
level()
{
maxl=1;
nowl=1;
upgrademoney=100;	
a=0;
b=0;	
}
void change()
{
	cout<<"nowl,maxl:";	
	cin>>nowl;
	getchar();
	cin>>maxl;
}
void howmuchtomax()
{
	upgrademoney=(nowl-0)*50+100;
	b=maxl-nowl;
	a=upgrademoney*b+b*(b-1)*50/2;		
}
void outter()
{
	cout<<"max level:"
	<<maxl<<" now level:"<<nowl<<" upgraderequests:"<<upgrademoney<<endl;	
}
void final()
{
	cout<<"remain "<<b<<" to max level"<<endl
	<<"need "<<a<<" to max level"	<<endl;
}
private:
int b,a;
int maxl;
int nowl;
int upgrademoney;
};
int main(int argc, char *argv[])
{
	level A;
	A.change();
	A.howmuchtomax();
	A.outter();//
	A.final();
	system("pause"); 
	return 0;
}