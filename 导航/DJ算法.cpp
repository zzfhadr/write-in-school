#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const int maxnum = 11; //十个地点 
const int maxint = 9999;//用于表示不可通 
struct namedes{
 	char* data; //地点名称 
 	char* des; //地点描述 
};
namedes attach[11];

// 各数组都从下标1开始
int dist[maxnum];     // 表示当前点到源点的最短路径长度
int prev[maxnum];     // 记录当前点的前一个结点
int c[maxnum][maxnum];   // 记录图的两点间路径长度
int n, line;             // 图的结点数和路径数
void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum])
{
    bool s[maxnum];    // 判断点是否已存入该点到S集合中
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];//初始化dist[] 
        s[i] = 0;     // 初始都未用过该点
        if(dist[i] == maxint)//初始化prev[] 
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;

    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到终点之间的最短路径长度
         // 注意是从第二个节点开始，第一个为源点
    for(int i=2; i<=n; ++i)
    {
        int tmp = maxint;
        int u = v;
        // 找出当前未使用的点j的dist[j]最小值
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              // u保存当前邻接点中距离最小的点的号码
                tmp = dist[j];
            }
        s[u] = 1;    // 表示u点已存入S集合中

        // 更新dist
        for(int j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<maxint)//点未被使用，且可达 
            {
                int newdist = dist[u] + c[u][j]; 
                if(newdist < dist[j])//从点u走，经过的路径比之前要短 
                {
                    dist[j] = newdist;//更新dist[j]（起点v到j的距离）为从u走的短路径 
                    prev[j] = u;//经过u 
                }
            }
    }
}

// 查找从源点v到终点u的路径，并输出
void searchPath(int *prev,int v, int u)
{
    int que[maxnum];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];//由v到u,最短路径上，u的前一个点 
    while(tmp != v)//前一点不为v 
    {
        que[tot] = tmp;  
        tot++;
        tmp = prev[tmp];//不断循环直到，que[]中储存了由u到v最短路径（不含v) 
    }
    que[tot] = v;//加上v，到此que[]中储存了由u到v最短路径 
    for(int i=tot; i>=1; --i)//将que[]倒着打出来 
        if(i != 1)
            cout << attach[que[i]].data << " -> ";
        else
            cout << attach[que[i]].data << endl;
            for(int i=1;i<11;i++){
            	cout<<prev[i]<<"  ";
            }
            cout<<endl;
             for(int i=1;i<11;i++){
            	cout<<dist[i]<<"  ";
            }
}

int main()
{
	//FILE* input;	
    freopen("input.txt", "r",stdin);
    // 各数组都从下标1开始

    // 输入结点数
    cin >> n;
    // 输入路径数
    cin >> line;
    int p, q, len;  
	int start,end;       
    // 初始化c[][]为maxint
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;

    for(int i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;	 // 输入p, q两点及其路径长度
        if(len < c[p][q])       // 有重边
        {
            c[p][q] = len;     
            c[q][p] = len;      // q，p互通，这样表示无向图
        }
    }
    for(int i=1; i<=n; ++i)
        dist[i] = maxint;
    attach[1].data="软件学院";
    attach[1].des="云南大学国家示范性软件学院"; 
    attach[2].data="格物楼";
    attach[2].des="教学楼，电梯藏在后面"; 
    attach[3].data="楠苑";
    attach[3].des="宿舍，算是综合位置最好的宿舍"; 
    attach[4].data="力行楼";
    attach[4].des="教学楼，只有一部电梯"; 
    attach[5].data="楸苑";
    attach[5].des="宿舍，离食堂近";
	attach[6].data="图书馆";
    attach[6].des="学习圣地";
	attach[7].data="中山邦翰楼";
    attach[7].des="用于教学和事务处理";
	attach[8].data="桦苑";
    attach[8].des="宿舍";
	attach[9].data="文汇楼";
    attach[9].des="教学楼";
	attach[10].data="梓苑";
    attach[10].des="宿舍";        
    printf("\t\t景点名称\t\t|\t景点描述\n");
    for(int i=1;i<11;i++) 
   	printf("\t%c (%2d)%-10s\t\t|\t%-30s%c\n",3,i,attach[i].data,attach[i].des,3);
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            printf("%8d", c[i][j]);
        printf("\n");
    }
	cin>>start>>end;//输入起点和终点 
    Dijkstra(n, start, dist, prev, c);
    // 最短路径长度
    cout << attach[start].data<<"到"
	<<attach[end].data<<"的最短路径长度: " << dist[end] << endl;

    // 路径
    cout << "源点到最后一个顶点的路径为: ";
    searchPath(prev, start, end);
   	
}
