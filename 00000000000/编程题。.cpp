#include <iostream>
using namespace std;
struct snack
{
	int v;
	int t;		
};
int main()
{
	int N,M,V;
	cin>>N>>M>>V;
	snack s[300];
	int i;
	for(i=0;i<N;i++)
	{
		cin>>s[i].v;
		cin>>s[i].t;
	}
	
	int c,d;
	snack f;
	for(d=0;d<N;d++)
	{
	for(c=d+1;c<N;c++) //t
	if(s[d].t>s[c].t)
	{
		f=s[c];
		s[c]=s[d];
		s[d]=f;
	}
	}
	return 0;
}
/*
int main()
{
	int N,M,V;
	cin>>N>>M>>V;
	int i;
	int s[300],v[300],t[300];
	for(i=0;i<N;i++)
	{
		cin>>v[i];	
		cin>>t[i];
	}
	
	int c,d,f;
	for(d=0;d<N;d++)
	{
	for(c=d+1;c<N;c++) //t
	if(t[d]>t[c])
	{
		f=t[c];
		t[c]=t[d];
		t[d]=f;
	}
	//for(c=0;c<N;c++)
	//printf("%2d ",a[c]);
	}
	c=0;
	
	for(i=M-1;i>=0;i--)
	{
		c=t[i]+c;
	}
	
	return 0;
}*/
/*
题目背景
In ACM-ICPC contests, we are allowed to bring any non-electronic products. So we can bring books and templates to the competition area, and of course, we can bring snacks.

LBHLBH's AC rate increases when he eats tasty snacks. He specially bought a bag to put the snacks in.

题目描述
Knowing that LBHLBH has a bag whose volume is VV. He took a look at the snacks at home and decided to put some into the bag.

There are NN snacks in the LBHLBH's home. The volume of the iith snack is v_iv 
i
?
 , and the taste of the iith snack is t_it 
i
?
 . LBHLBH decides to select some snacks. On the premise of their total volume doesn't exceed VV, he wants to maximize the total taste.

But there is another problem to consider: ACM contests have limited time and LBHLBH can't spend all the time on eating snacks. So he can only bring at most MM snacks.

So the problem is, help LBHLBH select at most MM snacks with the total volume not exceeding VV, and maximize the total taste. Please tell LBHLBH the maximum total taste he can get.

输入格式
The first line contains 33 integers N,M,VN,M,V, denoting the number of snacks, maximum number of snacks and bag volume.

The following NN lines each contains 22 integers v_i,t_iv 
i
?
 ,t 
i
?
 , denoting the volume and taste of each snack.

输出格式
An integer denoting the maximum total taste.

输入输出样例
输入 #1
3 2 100
80 200
6 6
2 33
输出 #1
233
输入 #2
15 14 150
6 47
14 40
85 21
124 16
7 15
84 28
63 18
125 24
59 22
84 44
33 35
46 6
39 29
120 3
101 50
输出 #2
181
说明/提示
1≤N,M,V≤200

M≤N

11≤v_i,t_i ≤200
*/