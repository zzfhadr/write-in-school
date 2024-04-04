#include <stdio.h>
#include <stdlib.h>
typedef struct{  //定义坐标 
	int r,c;
}PosType;
typedef struct{  //定义元素 
	int step;
	PosType seat;  //di为0，1，2，3，4分别对应无，东，南，西，北 
	int di;
}ElemType;
struct SqStack{  //定义栈 
	ElemType * top;
	ElemType * base;
	int size;
};
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
	e=--s->top;
	return 1;
}
int main(int argc, char *argv[])
{
	ElemType e;
	e.step=0;
	e.seat.r=1;
	e.seat.c=1;
	e.di=4;
	SqStack s;
	InitStack(&s);
	Push(&s,e);	
	return 0;
}
