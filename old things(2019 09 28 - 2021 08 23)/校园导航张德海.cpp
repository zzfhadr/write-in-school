#include "string.h"
#include "stdio.h"
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#define Max 20000
#define NUM 10
typedef struct ArcCell{
 int adj;  /* ���ڽӵľ���֮���·�� */
}ArcCell;   /* ����ߵ����� */
typedef struct VertexType{
 int number;  /* ������ */
 char* sight;  /* �������� */
 char* info; /* �������� */
}VertexType;   /* ���嶥������� */
typedef struct{
 VertexType vex[NUM]; /* ͼ�еĶ��㣬��Ϊ���� */
 ArcCell arcs[NUM][NUM]; /* ͼ�еıߣ���Ϊ�����ľ��� */
 int vexnum,arcnum; /* ������������ */
}MGraph;   /* ����ͼ������ */
MGraph G;   /* ��ͼ����Ϊȫ�ֱ��� */
int P[NUM][NUM];  /*  */
long int D[NUM];  /* ���������洢���·������ */
int   x[9]={0};
void CreateUDN(int v,int a); /* ��ͼ���� */
void narrate();   /*˵������*/
void ShortestPath(int num); /*���·������*/
void output(int sight1,int sight2); /*�������*/
char Menu();   /* ���˵� */
void search();   /* ��ѯ������Ϣ */
char SearchMenu();  /* ��ѯ�Ӳ˵� */
void   HaMiTonian(int);   /* ���ܶ���ͼ�ı��� */
void   NextValue(int);  
void   display(); /* ��ʾ������� */
int main() /* ������ */
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
   printf("\n\n\t\t\t��ѡ����㾰�㣨0��9����");
   scanf("%d",&v0);
   printf("\t\t\t��ѡ���յ㾰�㣨0��9����");
   scanf("%d",&v1);
   ShortestPath(v0);  /* ������������֮������·�� */
   output(v0,v1);     /* ������ */
   printf("\n\n\t\t\t\t�밴���������...\n");
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
   printf("\n\n\t\t\t\t�밴���������...\n");
   getchar();
   getchar();
   break;
  };
 }while(ck!='e');
return 0; 
 
}
char Menu()  /* ���˵� */
{
 char c;
 int flag;
 do{
  flag=1;
  system("cls");
  narrate();
  printf("\n\t\t\t����������������������������������\n");
  printf("\t\t\t��                              ��\n");
  printf("\t\t\t��      1����ѯ����·��         ��\n");
  printf("\t\t\t��      2����ѯ������Ϣ         ��\n");
  printf("\t\t\t��      3���Ƽ��ι�·��         ��\n");
  printf("\t\t\t��      e���˳�                 ��\n");
  printf("\t\t\t��                              ��\n");
  printf("\t\t\t����������������������������������\n");
  printf("\t\t\t\t����������ѡ��");
  scanf("%c",&c);
  if(c=='1'||c=='2'||c=='3'||c=='e')
   flag=0;
 }while(flag);
 return c;
}
char SearchMenu()  /* ��ѯ�Ӳ˵� */
{
 char c;
 int flag;
 do{
  flag=1;
  system("cls");
  narrate();
  printf("\n\t\t\t����������������������������������\n");
  printf("\t\t\t��                              ��\n");
  printf("\t\t\t��      1�����վ����Ų�ѯ     ��\n");
  printf("\t\t\t��      2�����վ������Ʋ�ѯ     ��\n");
  printf("\t\t\t��      e������                 ��\n");
  printf("\t\t\t��                              ��\n");
  printf("\t\t\t����������������������������������\n");
  printf("\t\t\t\t����������ѡ��");
  scanf("%c",&c);
  if(c=='1'||c=='2'||c=='e')
   flag=0;
 }while(flag);
 return c;
}
void search()  /* ��ѯ������Ϣ */
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
   printf("\n\n\t\t��������Ҫ���ҵľ����ţ�");
   scanf("%d",&num);
   for(i=0;i<NUM;i++)
   {
    if(num==G.vex[i].number)
    {
     printf("\n\n\t\t\t��Ҫ���Ҿ�����Ϣ����:");
     printf("\n\n\t\t\t%-25s\n\n",G.vex[i].info);
     printf("\n\t\t\t�����������...");
     getchar();
     getchar();
     break;
    }
   }
   if(i==NUM)
   {
    printf("\n\n\t\t\tû���ҵ���");
    printf("\n\n\t\t\t�����������...");
    getchar();
    getchar();
   }
  
   break;
  case '2':
   system("cls");
   narrate();
   printf("\n\n\t\t��������Ҫ���ҵľ������ƣ�");
   scanf("%s",name);
   for(i=0;i<NUM;i++)
   {
    if(!strcmp(name,G.vex[i].sight))
    {
     printf("\n\n\t\t\t��Ҫ���Ҿ�����Ϣ����:");
     printf("\n\n\t\t\t%-25s\n\n",G.vex[i].info);
     printf("\n\t\t\t�����������...");
     getchar();
     getchar();
     break;
    }
   }
   if(i==NUM)
   {
    printf("\n\n\t\t\tû���ҵ���");
    printf("\n\n\t\t\t�����������...");
    getchar();
    getchar();
   }
   break;
  }
 }while(c!='e');
}
void CreateUDN(int v,int a) /* ��ͼ���� */
{
 int i,j;
 G.vexnum=v;  /* ��ʼ���ṹ�еľ������ͱ��� */
 G.arcnum=a;
 for(i=0;i<G.vexnum;++i) G.vex[i].number=i; /* ��ʼ��ÿһ������ı�� */
 
 /* ��ʼ��ûһ�����������侰������ */
 
 G.vex[0].sight="ʵ��¥";
 G.vex[0].info="��ʦ�칫��ѧ����ʵ��";
 G.vex[1].sight="������";
 G.vex[1].info="ҵ�����ٰ������ᡣ";
 G.vex[2].sight="18��¥";
 G.vex[2].info="��ѧ¥";
 G.vex[3].sight="10��¥";
 G.vex[3].info="���ѧ������";
 G.vex[4].sight="��԰";
 G.vex[4].info="��԰";
 G.vex[5].sight="��԰";
 G.vex[5].info="��԰";
 G.vex[6].sight="����";
 G.vex[6].info="����";
 G.vex[7].sight="ͼ���";
 G.vex[7].info="�軹��";
 G.vex[8].sight="��¥";
 G.vex[8].info="����¥";
 G.vex[9].sight="ѧ������";
 G.vex[9].info="ѧ���Է��ĵط�";
 
 /* ��������еı߼ٶ�Ϊ20000������������������֮���ǲ��ɵ��� */
 for(i=0;i<G.vexnum;++i)
  for(j=0;j<G.vexnum;++j)
   G.arcs[i][j].adj=Max;
 
   /*
  
     �±��ǿ�ֱ�ӵ���ľ����ľ��룬�����������������ǻ���ģ�
     ����Ҫ��ͼ�жԳƵı�ͬʱ��ֵ��
    
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
void narrate() /* ˵������ */
{
 int i,k=0;
 printf("\n\t\t*****************��ӭʹ��У԰���γ���***************\n");
 printf("\t__________________________________________________________________\n");
 printf("\t\t��������\t\t|\t��������\n");
 printf("\t________________________________|_________________________________\n");
 for(i=0;i<NUM;i++)
 {
  printf("\t%c (%2d)%-10s\t\t|\t%-25s%c\n",3,i,G.vex[i].sight,G.vex[i].info,3); /* ��������б� */
  k=k+1;
 }
 printf("\t________________________________|_________________________________\n");
}
void ShortestPath(int num) /* �Ͻ�˹�����㷨���·������ numΪ��ڵ�ı�� */
{
 int v,w,i,t;  /* i��w��vΪ�������� */
 int final[NUM]; /*  */
 int min;
 for(v=0;v<NUM;v++)
 {
  final[v]=0;  /* ����Ӷ���num������vû�����·�� */
  D[v]=G.arcs[num][v].adj;/* ����֮��ص�Ȩֵ����D�д�� */
  for(w=0;w<NUM;w++) /* ����Ϊ��·�� */
   P[v][w]=0;
  if(D[v]<20000)  /* ����·�� */
  {
   P[v][num]=1; /* ���ڱ�־��Ϊһ */
   P[v][v]=1; /* �������� */
  }
 }
 
 D[num]=0;
 final[num]=1;      /* ��ʼ��num��������S���� */
        /* ��ʼ��ѭ����ÿһ�����num��ĳ����������·������������뵽S���� */
 for(i=0;i<NUM;++i)     /* ����G.vexnum-1������ */
 {
  min=Max;     /* ��ǰ��֪�붥��num��������� */
  for(w=0;w<NUM;++w)
   if(!final[w])    /* w������v-s�� */
    if(D[w]<min)   /* w������num������� */
    {
     v=w;
     min=D[w];
    }
    final[v]=1;   /* ��num���������v���뵽s���� */
    for(w=0;w<NUM;++w)  /* ���µ�ǰ���·��������� */
     if(!final[w]&&((min+G.arcs[v][w].adj)<D[w]))/* ����s���ϣ����ұ���ǰ���ҵ���·�����̾͸��µ�ǰ·�� */
     {
      D[w]=min+G.arcs[v][w].adj;
      for(t=0;t<NUM;t++)
       P[w][t]=P[v][t];
      P[w][w]=1;
     }
 }
}
void output(int sight1,int sight2)    /* ������� */
{
 int a,b,c,d,q=0;
 a=sight2;    /* ���������ֵ��a */
 if(a!=sight1)    /* �����������;���һ�����غϣ������... */
 {
  printf("\n\t��%s��%s�����·����",G.vex[sight1].sight,G.vex[sight2].sight);/* �����ʾ��Ϣ */
  printf("\t(��̾���Ϊ %dm.)/n/n/t",D[a]);  /* ���sight1��sight2�����·�����ȣ������D[]������ */
  printf("\t%s",G.vex[sight1].sight);   /* �������һ������ */
  d=sight1;      /* ������һ�ı�Ÿ�ֵ��d */
  for(c=0;c<NUM;++c)
  {
gate:;        /* ��ţ�������Ϊgoto�����ת��λ�� */
     P[a][sight1]=0;
     for(b=0;b<NUM;b++)
     {
      if(G.arcs[d][b].adj<20000&&P[a][b])  /* �������һ������һ���ٽ��֮�����·�������·�� */
      {
       printf("-->%s",G.vex[b].sight);  /* ����˽ڵ������ */
       q=q+1;     /* ����������һ����8�������ʱ�Ļ��� */
       P[a][b]=0;
       d=b;     /* ��b��Ϊ�����������һ��ѭ���������˷��� */
       if(q%9==0) printf("/n");
       goto gate;
      }
     }
  }
 }
 
}
void HaMiTonian(int m)   /* ���ܶ���ͼ�ı��� */
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
 printf("����");
 printf("\n");
}  
