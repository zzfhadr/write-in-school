#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const int maxnum = 100;//���һ�ٸ��� 
const int maxint = 999;

// �����鶼���±�1��ʼ
int dist[maxnum];     // ��ʾ��ǰ�㵽Դ������·������
int prev[maxnum];     // ��¼��ǰ���ǰһ�����
int c[maxnum][maxnum];   // ��¼ͼ�������·������
int n, line;             // ͼ�Ľ������·����
void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum])
{
    bool s[maxnum];    // �ж��Ƿ��Ѵ���õ㵽S������
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0;     // ��ʼ��δ�ù��õ�
        if(dist[i] == maxint)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;

    // ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
    // һ��S����������V�ж��㣬dist�ͼ�¼�˴�Դ�㵽������������֮������·������
         // ע���Ǵӵڶ����ڵ㿪ʼ����һ��ΪԴ��
    for(int i=2; i<=n; ++i)
    {
        int tmp = maxint;
        int u = v;
        // �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
                tmp = dist[j];
            }
        s[u] = 1;    // ��ʾu���Ѵ���S������

        // ����dist
        for(int j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<maxint)
            {
                int newdist = dist[u] + c[u][j];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}

// ���Ҵ�Դ��v���յ�u��·���������
void searchPath(int *prev,int v, int u)
{
    int que[maxnum];
    int tot = 1;
    que[tot] = u;
    tot++;   
    int tmp = prev[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=1; --i)
        if(i != 1)
            cout <<(char)((que[i])+64)  << ",";
        else
            cout << (char)((que[i])+64) ;
         /*
   for(int i=1;i<=n;i++)
            cout<<prev[i]<<" ";*/
}

int main()
{
    freopen("input.txt", "r", stdin);
    // �����鶼���±�1��ʼ

    // ��������
    cin >> n;
    // ����·����
    cin >> line;
    int p, q, len;          // ����p, q���㼰��·������
	int start,end;
    // ��ʼ��c[][]Ϊmaxint
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;

    for(int i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;
        if(len < c[p][q])       // ���ر�
        {
            c[p][q] = len;      // pָ��q
            c[q][p] = len;      // qָ��p��������ʾ����ͼ
        }
    }

    for(int i=1; i<=n; ++i)
        dist[i] = maxint;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            printf("%8d", c[i][j]);
        printf("\n");
    }
	cin>>start;
    Dijkstra(n, start, dist, prev, c);
    cout << "Դ�㵽������������·������: "<<endl; 
    for(int i=1;i<=n;i++)
    {
    	if(i!=start){
    	char c=(char)(i+64);
    	cout<<"��"<<c<<":  "; 
    	cout<< dist[i] << endl;	
	    }

    }
    
    cout << "Դ�㵽���������·��Ϊ: "<<""<<endl;
    for(int i=1;i<=n;i++)
    {
    	if(i!=start){
    	char c=(char)(i+64);
    	cout<<"��"<<c<<":  ("; 
		searchPath(prev, start, i);
		cout<<")"<<endl;	
	    }

    }
    
}
