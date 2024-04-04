#include <iostream.h>
using namespace std;
void out(int a[2]){
		cout<<a[0]<<",";
		cout<<a[1]<<endl;
};
int main(int argc, char *argv[])
{
	int x,y,lon,wit;
	cout<<"please copy\n";
	cin>>x>>y>>lon>>wit;
	int a[2],b[2],c[2],d[2];
	a[0]=x;
	a[1]=y;
	b[0]=x+lon;
	b[1]=y;
	d[0]=x;
	d[1]=y+wit;
	c[0]=x+lon;
	c[1]=y+wit;
	int textx,texty;
	textx=(2*x+lon)/2;
	texty=(2*y+wit)/2;
	out(a);
	out(b);
	out(c);
	out(d);
	cout<<"ÖÐµã"<<endl; 
	cout<<textx<<","<<texty<<endl;
//	system("pause");
	return 0;
}