#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	float size,MB=6.0;
	cout<<"�����С(GB)��"<<endl;
	cin>>size;
	float a;
	a=(size*1024/MB/3600);
	int i;
	i=(int)a;
	float b;
	b=a-(float)i;
	a=b*60; 
	cout<<"Ԥ����Ҫ��"<<i<<"Сʱ"<<a<<"����"<<endl;
	system("pause"); 
	return 0;
}