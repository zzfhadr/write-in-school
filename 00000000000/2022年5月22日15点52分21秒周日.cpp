#include <iostream>
using namespace std;
int main()
{
	int n;
	int r[100];
	int s[100];
	cin>>n;
	int j=0;
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
		if(r[i]==1)
		{
			s[j]=i;
			j++;	
		}
	}
	float p;
	p=(float)j/(float)n;
	for(int i=0;i<j;i++)
	cout<<(s[i]+1)<<" ";
	cout<<endl;
	printf("%.3lf",p);
}