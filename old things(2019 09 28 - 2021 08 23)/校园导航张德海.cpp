#include "string.h"
#include "stdio.h"
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#define Max 20000
#define NUM 10
typedef struct ArcCell{
 int adj;  /* 相邻接的景点之间的路程 */
}ArcCell;   /* 定义边的类型 */
typedef struct VertexType{
 int number;  /* 景点编号 */
 char* sight;  /* 景点名称 */
 char* info; /* 景点描述 */
}VertexType;   /* 定义顶点的类型 */
typedef struct{
 VertexType vex[NUM]; /* 图中的顶点，即为景点 */
 ArcCell arcs[NUM][NUM]; /* 图中的边，即为景点间的距离 */
 int vexnum,arcnum; /* 顶点数，边数 */
}MGraph;   /* 定义图的类型 */
MGraph G;   /* 把图定义为全局变量 */
int P[NUM][NUM];  /*  */
long int D[NUM];  /* 辅助变量存储最短路径长度 */
int   x[9]={0};
void CreateUDN(int v,int a); /* 造图函数 */
void narrate();   /*说明函数*/
void ShortestPath(int num); /*最短路径函数*/
void output(int sight1,int sight2); /*输出函数*/
char Menu();   /* 主菜单 */
void search();   /* 查询景点信息 */
char SearchMenu();  /* 查询子菜单 */
void   HaMiTonian(int);   /* 哈密尔顿图的遍历 */
void   NextValue(int);  
void   display(); /* 显示遍历结果 */
int main() /* 主函数 */
{
 
 int v0,v1;
 char ck;
 CreateUDN(NUM,11);
 do
 { 
  ck=Menu();
  switch(ck)
  {
  case '1':
   system("cls");
   narrate();
   printf("\n\n\t\t\t请选择起点景点（0～9）：");
   scanf("%d",&v0);
   printf("\t\t\t请选择终点景点（0～9）：");
   scanf("%d",&v1);
   ShortestPath(v0);  /* 计算两个景点之间的最短路径 */
   output(v0,v1);     /* 输出结果 */
   printf("\n\n\t\t\t\t请按任意键继续...\n");
   getchar();
   getchar();
   break;
  case '2':search();
   break;
  case '3':
   system("cls");
   narrate();
   x[0]=1;  
   HaMiTonian(1);
   printf("\n\n\t\t\t\t请按任意键继续...\n");
   getchar();
   getchar();
   break;
  };
 }while(ck!='e');
return 0; 
 
}
char Menu()  /* 主菜单 */
{
 char c;
 int flag;
 do{
  flag=1;
  system("cls");
  narrate();
  printf("\n\t\t\t┏━━━━━━━━━━━━━━━┑\n");
  printf("\t\t\t┃                              ┃\n");
  printf("\t\t\t┃      1、查询景点路径         ┃\n");
  printf("\t\t\t┃      2、查询景点信息         ┃\n");
  printf("\t\t\t┃      3、推荐参观路线         ┃\n");
  printf("\t\t\t┃      e、退出                 ┃\n");
  printf("\t\t\t┃                              ┃\n");
  printf("\t\t\t┗━━━━━━━━━━━━━━━┛\n");
  printf("\t\t\t\t请输入您的选择：");
  scanf("%c",&c);
  if(c=='1'||c=='2'||c=='3'||c=='e')
   flag=0;
 }while(flag);
 return c;
}
char SearchMenu()  /* 查询子菜单 */
{
 char c;
 int flag;
 do{
  flag=1;
  system("cls");
  narrate();
  printf("\n\t\t\t┏━━━━━━━━━━━━━━━┑\n");
  printf("\t\t\t┃                              ┃\n");
  printf("\t\t\t┃      1、按照景点编号查询     ┃\n");
  printf("\t\t\t┃      2、按照景点名称查询     ┃\n");
  printf("\t\t\t┃      e、返回                 ┃\n");
  printf("\t\t\t┃                              ┃\n");
  printf("\t\t\t┗━━━━━━━━━━━━━━━┛\n");
  printf("\t\t\t\t请输入您的选择：");
  scanf("%c",&c);
  if(c=='1'||c=='2'||c=='e')
   flag=0;
 }while(flag);
 return c;
}
void search()  /* 查询景点信息 */
{
 int num;
 int i;
 char c;
 char name[20];
 
 do
 {
  system("cls");
  c=SearchMenu();
  switch (c)
  {
  case '1': 
   system("cls");
   narrate();
   printf("\n\n\t\t请输入您要查找的景点编号：");
   scanf("%d",&num);
   for(i=0;i<NUM;i++)
   {
    if(num==G.vex[i].number)
    {
     printf("\n\n\t\t\t您要查找景点信息如下:");
     printf("\n\n\t\t\t%-25s\n\n",G.vex[i].info);
     printf("\n\t\t\t按任意键返回...");
     getchar();
     getchar();
     break;
    }
   }
   if(i==NUM)
   {
    printf("\n\n\t\t\t没有找到！");
    printf("\n\n\t\t\t按任意键返回...");
    getchar();
    getchar();
   }
  
   break;
  case '2':
   system("cls");
   narrate();
   printf("\n\n\t\t请输入您要查找的景点名称：");
   scanf("%s",name);
   for(i=0;i<NUM;i++)
   {
    if(!strcmp(name,G.vex[i].sight))
    {
     printf("\n\n\t\t\t您要查找景点信息如下:");
     printf("\n\n\t\t\t%-25s\n\n",G.vex[i].info);
     printf("\n\t\t\t按任意键返回...");
     getchar();
     getchar();
     break;
    }
   }
   if(i==NUM)
   {
    printf("\n\n\t\t\t没有找到！");
    printf("\n\n\t\t\t按任意键返回...");
    getchar();
    getchar();
   }
   break;
  }
 }while(c!='e');
}
void CreateUDN(int v,int a) /* 造图函数 */
{
 int i,j;
 G.vexnum=v;  /* 初始化结构中的景点数和边数 */
 G.arcnum=a;
 for(i=0;i<G.vexnum;++i) G.vex[i].number=i; /* 初始化每一个景点的编号 */
 
 /* 初始化没一个景点名及其景点描述 */
 
 G.vex[0].sight="实验楼";
 G.vex[0].info="老师办公和学生做实验";
 G.vex[1].sight="大礼堂";
 G.vex[1].info="业余活动，举办各种晚会。";
 G.vex[2].sight="18号楼";
 G.vex[2].info="教学楼";
 G.vex[3].sight="10号楼";
 G.vex[3].info="大二学生宿舍";
 G.vex[4].sight="沁园";
 G.vex[4].info="花园";
 G.vex[5].sight="翠园";
 G.vex[5].info="花园";
 G.vex[6].sight="北教";
 G.vex[6].info="教室";
 G.vex[7].sight="图书馆";
 G.vex[7].info="借还书";
 G.vex[8].sight="主楼";
 G.vex[8].info="行政楼";
 G.vex[9].sight="学生餐厅";
 G.vex[9].info="学生吃饭的地方";
 
 /* 这里把所有的边假定为20000，含义是这两个景点之间是不可到达 */
 for(i=0;i<G.vexnum;++i)
  for(j=0;j<G.vexnum;++j)
   G.arcs[i][j].adj=Max;
 
   /*
  
     下边是可直接到达的景点间的距离，由于两个景点间距离是互相的，
     所以要对图中对称的边同时赋值。
    
  */
  G.arcs[0][1].adj=G.arcs[1][0].adj=6;
  G.arcs[0][2].adj=G.arcs[2][0].adj=4;
  G.arcs[0][3].adj=G.arcs[3][0].adj=5;
  G.arcs[1][4].adj=G.arcs[4][1].adj=1;
  G.arcs[2][4].adj=G.arcs[4][2].adj=1;
  G.arcs[3][5].adj=G.arcs[5][3].adj=2;
  G.arcs[5][7].adj=G.arcs[7][5].adj=4;
  G.arcs[4][6].adj=G.arcs[6][4].adj=9;
  G.arcs[4][7].adj=G.arcs[7][4].adj=7;
  G.arcs[6][8].adj=G.arcs[8][6].adj=2;
  G.arcs[7][8].adj=G.arcs[8][7].adj=4;
  G.arcs[8][9].adj=G.arcs[9][8].adj=4;
}
void narrate() /* 说明函数 */
{
 int i,k=0;
 printf("\n\t\t*****************欢迎使用校园导游程序***************\n");
 printf("\t__________________________________________________________________\n");
 printf("\t\t景点名称\t\t|\t景点描述\n");
 printf("\t________________________________|_________________________________\n");
 for(i=0;i<NUM;i++)
 {
  printf("\t%c (%2d)%-10s\t\t|\t%-25s%c\n",3,i,G.vex[i].sight,G.vex[i].info,3); /* 输出景点列表 */
  k=k+1;
 }
 printf("\t________________________________|_________________________________\n");
}
void ShortestPath(int num) /* 迪杰斯特拉算法最短路径函数 num为入口点的编号 */
{
 int v,w,i,t;  /* i、w和v为计数变量 */
 int final[NUM]; /*  */
 int min;
 for(v=0;v<NUM;v++)
 {
  final[v]=0;  /* 假设从顶点num到顶点v没有最短路径 */
  D[v]=G.arcs[num][v].adj;/* 将与之相关的权值放入D中存放 */
  for(w=0;w<NUM;w++) /* 设置为空路径 */
   P[v][w]=0;
  if(D[v]<20000)  /* 存在路径 */
  {
   P[v][num]=1; /* 存在标志置为一 */
   P[v][v]=1; /* 自身到自身 */
  }
 }
 
 D[num]=0;
 final[num]=1;      /* 初始化num顶点属于S集合 */
        /* 开始主循环，每一次求得num到某个顶点的最短路径，并将其加入到S集合 */
 for(i=0;i<NUM;++i)     /* 其余G.vexnum-1个顶点 */
 {
  min=Max;     /* 当前所知离顶点num的最近距离 */
  for(w=0;w<NUM;++w)
   if(!final[w])    /* w顶点在v-s中 */
    if(D[w]<min)   /* w顶点离num顶点更近 */
    {
     v=w;
     min=D[w];
    }
    final[v]=1;   /* 离num顶点更近的v加入到s集合 */
    for(w=0;w<NUM;++w)  /* 更新当前最短路径极其距离 */
     if(!final[w]&&((min+G.arcs[v][w].adj)<D[w]))/* 不在s集合，并且比以前所找到的路径都短就更新当前路径 */
     {
      D[w]=min+G.arcs[v][w].adj;
      for(t=0;t<NUM;t++)
       P[w][t]=P[v][t];
      P[w][w]=1;
     }
 }
}
void output(int sight1,int sight2)    /* 输出函数 */
{
 int a,b,c,d,q=0;
 a=sight2;    /* 将景点二赋值给a */
 if(a!=sight1)    /* 如果景点二不和景点一输入重合，则进行... */
 {
  printf("\n\t从%s到%s的最短路径是",G.vex[sight1].sight,G.vex[sight2].sight);/* 输出提示信息 */
  printf("\t(最短距离为 %dm.)/n/n/t",D[a]);  /* 输出sight1到sight2的最短路径长度，存放在D[]数组中 */
  printf("\t%s",G.vex[sight1].sight);   /* 输出景点一的名称 */
  d=sight1;      /* 将景点一的编号赋值给d */
  for(c=0;c<NUM;++c)
  {
gate:;        /* 标号，可以作为goto语句跳转的位置 */
     P[a][sight1]=0;
     for(b=0;b<NUM;b++)
     {
      if(G.arcs[d][b].adj<20000&&P[a][b])  /* 如果景点一和它的一个临界点之间存在路径且最短路径 */
      {
       printf("-->%s",G.vex[b].sight);  /* 输出此节点的名称 */
       q=q+1;     /* 计数变量加一，满8控制输出时的换行 */
       P[a][b]=0;
       d=b;     /* 将b作为出发点进行下一次循环输出，如此反复 */
       if(q%9==0) printf("/n");
       goto gate;
      }
     }
  }
 }
 
}
void HaMiTonian(int m)   /* 哈密尔顿图的遍历 */
{
 if(m>9)   return;  
L: NextValue(m);  
   if(x[m]==0)  
    return;  
   if(m==7&&G.arcs[0][x[9]-1].adj!=20000)  
    display();  
   else  
    HaMiTonian(m+1);  
   goto   L;  
}  
void NextValue(int k)  
{  
 int j;  
l:x[k]=(x[k]+1)%10;  
  if(x[k]==0)  
   return;  
  if(G.arcs[x[k-1]-1][x[k]-1].adj!=20000)  
  {  
   for(j=0;j<k;j++)  
    if(x[j]==x[k])  
     goto l;  
    return;      
  }  
  else  
   goto l;      
}  
void display()  
{  
 int i=0;
 printf("\n\n\t");
 for(i=0;i<8;i++)  
  printf("%s->",G.vex[x[i]-1].sight);  
 printf("出口");
 printf("\n");
}  
