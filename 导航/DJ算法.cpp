#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const int maxnum = 11; //ʮ���ص� 
const int maxint = 9999;//���ڱ�ʾ����ͨ 
struct namedes{
 	char* data; //�ص����� 
 	char* des; //�ص����� 
};
namedes attach[11];

// �����鶼���±�1��ʼ
int dist[maxnum];     // ��ʾ��ǰ�㵽Դ������·������
int prev[maxnum];     // ��¼��ǰ���ǰһ�����
int c[maxnum][maxnum];   // ��¼ͼ�������·������
int n, line;             // ͼ�Ľ������·����
void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum])
{
    bool s[maxnum];    // �жϵ��Ƿ��Ѵ���õ㵽S������
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];//��ʼ��dist[] 
        s[i] = 0;     // ��ʼ��δ�ù��õ�
        if(dist[i] == maxint)//��ʼ��prev[] 
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;

    // ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
    // һ��S����������V�ж��㣬dist�ͼ�¼�˴�Դ�㵽�յ�֮������·������
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
            if((!s[j]) && c[u][j]<maxint)//��δ��ʹ�ã��ҿɴ� 
            {
                int newdist = dist[u] + c[u][j]; 
                if(newdist < dist[j])//�ӵ�u�ߣ�������·����֮ǰҪ�� 
                {
                    dist[j] = newdist;//����dist[j]�����v��j�ľ��룩Ϊ��u�ߵĶ�·�� 
                    prev[j] = u;//����u 
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
    int tmp = prev[u];//��v��u,���·���ϣ�u��ǰһ���� 
    while(tmp != v)//ǰһ�㲻Ϊv 
    {
        que[tot] = tmp;  
        tot++;
        tmp = prev[tmp];//����ѭ��ֱ����que[]�д�������u��v���·��������v) 
    }
    que[tot] = v;//����v������que[]�д�������u��v���·�� 
    for(int i=tot; i>=1; --i)//��que[]���Ŵ���� 
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
    // �����鶼���±�1��ʼ

    // ��������
    cin >> n;
    // ����·����
    cin >> line;
    int p, q, len;  
	int start,end;       
    // ��ʼ��c[][]Ϊmaxint
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;

    for(int i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;	 // ����p, q���㼰��·������
        if(len < c[p][q])       // ���ر�
        {
            c[p][q] = len;     
            c[q][p] = len;      // q��p��ͨ��������ʾ����ͼ
        }
    }
    for(int i=1; i<=n; ++i)
        dist[i] = maxint;
    attach[1].data="���ѧԺ";
    attach[1].des="���ϴ�ѧ����ʾ�������ѧԺ"; 
    attach[2].data="����¥";
    attach[2].des="��ѧ¥�����ݲ��ں���"; 
    attach[3].data="�Է";
    attach[3].des="���ᣬ�����ۺ�λ����õ�����"; 
    attach[4].data="����¥";
    attach[4].des="��ѧ¥��ֻ��һ������"; 
    attach[5].data="�Է";
    attach[5].des="���ᣬ��ʳ�ý�";
	attach[6].data="ͼ���";
    attach[6].des="ѧϰʥ��";
	attach[7].data="��ɽ�¥";
    attach[7].des="���ڽ�ѧ��������";
	attach[8].data="��Է";
    attach[8].des="����";
	attach[9].data="�Ļ�¥";
    attach[9].des="��ѧ¥";
	attach[10].data="��Է";
    attach[10].des="����";        
    printf("\t\t��������\t\t|\t��������\n");
    for(int i=1;i<11;i++) 
   	printf("\t%c (%2d)%-10s\t\t|\t%-30s%c\n",3,i,attach[i].data,attach[i].des,3);
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            printf("%8d", c[i][j]);
        printf("\n");
    }
	cin>>start>>end;//���������յ� 
    Dijkstra(n, start, dist, prev, c);
    // ���·������
    cout << attach[start].data<<"��"
	<<attach[end].data<<"�����·������: " << dist[end] << endl;

    // ·��
    cout << "Դ�㵽���һ�������·��Ϊ: ";
    searchPath(prev, start, end);
   	
}
