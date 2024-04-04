#include <stdio.h>
#include  <stdlib.h>
#include <time.h>
typedef struct{  //�������� 
	int r,c;
}PosType;
typedef	 struct{  //�����Թ� 
	int m,n;
	char arr[50][50];
}MazeType;
typedef struct{  //����Ԫ�� 
	int step;
	PosType seat;  //diΪ0��1��2��3��4�ֱ��Ӧ�ޣ������ϣ������� 
	int di;
}ElemType;
typedef struct NodeType{ //������ 
	ElemType data;
	NodeType *next;
}*LinkType;
/*
typedef struct {   //������� 
    LinkType front, rear;
}LinkQueue;*/
struct SqStack{  //����ջ 
	ElemType * top;
	ElemType * base;
	int size;
};
void InitMaze (MazeType *maze ,int row,int col){
	maze->m=row;   //��ʼ���Թ� 
	maze->n=col;
	int i,j;
	srand(time(NULL));
	for(i=0;i<row;i++)
	for(j=0;j<col;j++){
		maze->arr[i][j]=(char)('0'+((rand())%2));
	}	
}
void PrintMaze(MazeType maze){ //��ӡ�Թ� 
	int i,j;
	for(i=0;i<maze.m;i++){
		printf("\n");
		for(j=0;j<maze.n;j++){
		if(maze.arr[i][j]=='4')
		printf("%c",'1');
		else
		printf("%c",maze.arr[i][j]);
		}	
	}
			
}
int InitStack(SqStack *s){ 
	s->base=(ElemType *)malloc(100*sizeof(ElemType));
	if(!s->base)
	exit(0);
	s->top=s->base;
	s->size=100;
	return 1;
}
int Push(SqStack *s,ElemType e){
	ElemType *p;
	if(s->top - s->base >= s->size){
		p=(ElemType *)realloc(s->base,(s->size+10)*sizeof(ElemType));
		if(!s->top)
		exit(0);
		s->base=p;
		s->top=s->base+s->size;
		s->size+=10;
	}
	*s->top++=e;
	return 1;
}
int Pop(SqStack *s,ElemType	 *e){
	if(s->top==s->base)
	return 0;
	*e=*--s->top;
	return 1;
}
int MazePath(MazeType *maze,PosType start,PosType end,SqStack *footpr)
{
	int found,j,i;
	ElemType temp;
	temp.step=0;
	temp.seat=start;
	temp.di=0;
	Push(footpr,temp);
	while(1){
		j=0;
		if(temp.di!=3)
		if(maze->arr[temp.seat.r][temp.seat.c+1]=='1'){
			temp.di=1;
			Push(footpr,temp);
			temp.seat.c++;
			temp.step++;
			j++;
		}
		if(temp.di!=4)
		if(maze->arr[temp.seat.r+1][temp.seat.c]=='1'){
			temp.di=2;
			Push(footpr,temp);
			temp.seat.r++;
			temp.step++;
			j++;  
		}
		if(start.c>0 && temp.di!=1)
		if(maze->arr[temp.seat.r][temp.seat.c-1]=='1'){
			temp.di=3;
			Push(footpr,temp);
			temp.seat.c--;
			temp.step++;
			j++;
		}
		if(start.r>0 && temp.di!=2)
		if(maze->arr[temp.seat.r-1][temp.seat.c]=='1'){
			temp.di=4;
			Push(footpr,temp);
			temp.seat.r--;
			temp.step++;
			j++;
		}
		if(j==0){
			maze->arr[temp.seat.r][temp.seat.c]='4';
			Pop(footpr,&temp);
		}	
		if(temp.seat.r==end.r && temp.seat.c==end.c){
			found=1;
			break;
		}	
		if(maze->arr[start.r][start.c]=='4'){
			found=0;
			break;
		}		
	}
	return found;
}
int main()
{
	int row,col,i,j;
	char input[50][50];
	PosType start,end;
	SqStack way,ref;
	InitStack(&way);
	InitStack(&ref);
	ElemType e;
	printf("���������Թ���������������");
	scanf("%d%d",&row,&col);	
	MazeType maze;
/*
	//getchar();
	//printf("�����Թ������ÿո�����һ�к󰴻س�����"); 
	for(i=0;i<row;i++){
		
	}
		//gets(input[i]);*/	
	printf("�ֱ������Թ���ʼλ�õĺ������꣺");
	scanf("%d%d",&start.r,&start.c);
	printf("�ֱ������Թ�����λ�õĺ������꣺");	
	scanf("%d%d",&end.r,&end.c);
	start.r--,start.c--;
	end.r--,end.c--;
	InitMaze(&maze,row,col);
	j=MazePath(&maze,start,end,&way);
	PrintMaze(maze);
	printf("\n");
	start.r++,start.c++;
	end.r++,end.c++;
	if(j==1)
	{
	printf("��(%d,%d)��(%d,%d)��ͨ·��һ��ͨ·Ϊ��\n",start.r,start.c,end.r,end.c);
	while(way.base!=way.top){
		Pop(&way,&e);
		Push(&ref,e);
	}
	while(ref.top!=ref.base){
		Pop(&ref,&e);
		printf("(%d,%d,%d) ",e.seat.r+1,e.seat.c+1,e.di);
	}
	}
	else
	printf("��(%d,%d)��(%d,%d)û��ͨ·��\n",start.r,start.c,end.r,end.c);
	return 0; 
}
