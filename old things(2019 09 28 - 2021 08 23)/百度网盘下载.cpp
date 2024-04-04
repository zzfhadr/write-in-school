#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	float size,KB;
	cout<<"输入大小(MB)："<<endl;
	cin>>size;
	cout<<"输入速度(KB/s：)"<<endl;
	cin>>KB;
	float a;
	a=(size*1024/KB/3600);
	int i;
	i=(int)a;
	float b;
	b=a-(float)i;
	a=b*60; 
	cout<<"预计需要："<<i<<"小时"<<a<<"分钟"<<endl;
	system("pause"); 
	return 0;
}