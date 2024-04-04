#include <stdio.h>
#include  <stdlib.h>
typedef struct{ 
	int r,c;
}PosType;
typedef	 struct{
	int m,n;
	char arr[50][50];
}MazeType;
typedef struct{
	int step;
	PosType seat;
	int di;
}ElemType;
typedef struct NodeType{  //������ 
	ElemType data;
	NodeType *next;
}*LinkType;
struct SqStack{   //����ջ 
	LinkType top;
	LinkType base;
	int size;
};
void InitMaze (MazeType *maze,char a[50][50],int row,int col){
	maze->m=row;   //��ʼ���Թ� 
	maze->n=col;
	int i,j;
	for(i=0;i<row;i++)
	for(j=0;j<col;j++){
		maze->arr[i][j]=a[i][j];
	}	
}
void PrintMaze(MazeType maze){
	int i,j;
	for(i=0;i<maze.m;i++){
		printf("\n");
		for(j=0;j<maze.n;j++){
		printf("%c",maze.arr[i][j]);
		}	
	}
			
}
int InitStack(SqStack *s){ 
	s->base=(NodeType *)malloc(sizeof(NodeType)*100);
	if(!s->base)
	exit(0);
	s->top=s->base;
	s->size=100;
	return 1;
}
int Push(SqStack *s,NodeType e){
	if(s->top - s->base >= s->size){
		s->base=(NodeType *)realloc(s->base,(s->size+10)*sizeof(NodeType));
		if(!s->top)
		exit(0);
		s->top=s->base+s->size;
		s->size+=10;
	}
	*s->top++=e;
	return 1;
}
int Pop(SqStack *s,NodeType *e){
	if(s->top==s->base)
	return 0;
	e=--s->top;
	return 1;
}
/*
int MazePath(MazeType *maze,PosType start,PosType end)
{
	int found;
		
}*/
int main()
{
	int row,col,i,j;
	char input[50][50];
	printf("���������Թ���������������");
	scanf("%d%d",&row,&col);	
	MazeType maze;
	getchar();
	for(i=0;i<row;i++)
		gets(input[i]);		
	InitMaze(&maze,input,row,col);
	PrintMaze(maze);
	return 0; 
}
