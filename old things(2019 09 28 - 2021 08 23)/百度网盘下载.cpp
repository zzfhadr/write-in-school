#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	float size,KB;
	cout<<"�����С(MB)��"<<endl;
	cin>>size;
	cout<<"�����ٶ�(KB/s��)"<<endl;
	cin>>KB;
	float a;
	a=(size*1024/KB/3600);
	int i;
	i=(int)a;
	float b;
	b=a-(float)i;
	a=b*60; 
	cout<<"Ԥ����Ҫ��"<<i<<"Сʱ"<<a<<"����"<<endl;
	system("pause"); 
	return 0;
}