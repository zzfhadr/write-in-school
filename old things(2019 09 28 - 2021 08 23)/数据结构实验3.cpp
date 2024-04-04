#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define STACK_INIT_SIZE 100
#define STACKINCEREMENT 10

//栈的顺序存储表示 
typedef struct {
    char *base, *top;
    int stacksize;
}SqStack;         

//单链队列--队列的链式存储表示 
typedef struct QNode{
    char data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front, rear;
}LinkQueue;

// 栈的操作 
int InitStack (SqStack *S);
int Push (SqStack *S, char c);
int Pop (SqStack *S,char *c);

// 队列的操作 
int InitQueue (LinkQueue *Q);
int DestroyQueue (LinkQueue *Q);
int EnQueue (LinkQueue *Q, char c);
int DeQueue (LinkQueue *Q, char *c);

// 其它操作 
int Match (char *str);  


int main ()
{
    int i,j;
    char ch, ch1,st[1000]={0},ReverseFirstElem, str[1000] = "B(ehnxgz)B";
    SqStack Devil,human,temp; 
    InitStack (&Devil);
    InitStack (&human);
    InitStack (&temp);
    if ( Match(str) )
    {
        for (i=(strlen(str)-1);i>=0;--i)//从右至左入栈 
            Push(&Devil, str[i]);
        while(Devil.base != Devil.top)
        {
            Pop(&Devil, &ch);
            switch (ch){           	
            case 'B':{
      	   	 char	str[1000]="tsaedsae";
				for(i=0;i<strlen(str);++i)
            	Push(&human,str[i]);//可用队列，最后For+printf输出 
            }
            break;
            case 'A':{
             char	str[1000]="sae";
            	for(i=0;i<strlen(str);++i)
            	Push(&human,str[i]);
            }
            break;
            case '(':{
            	Pop(&Devil,&ch1);
            	Push(&temp,ch1);
            	ReverseFirstElem=ch1;  
            	while(1){
	            	Pop(&Devil,&ch1);
	            	if(ch1!=')')
	            	Push(&temp,ch1);
					else
					break;					      			
	            }
				for(i=1;temp.base!=temp.top;i=i+2){
            		Pop(&temp,&ch1);
            		str[0]=ReverseFirstElem;
            		str[i]=ch1;
            		str[i+1]=ReverseFirstElem;
            	}	   
            	for(i=0;i<strlen(str);i++){
	            	Push(&human,str[i]);
	            }
            }
            break;
            }                   	
        }
        for(i=0;human.base!=human.top;i++){
        	Pop(&human,&ch);
        	str[i]=ch;
        }
        for(i=strlen(str)-1,j=0 ; i!=-1 ; j++,i--){
        	st[j]=str[i];
        }
		puts(st);	
    }
    
    return 0;
} 


// 对栈的操作 
int InitStack (SqStack *S) 
{   //初始化栈 
    S->base = (char *)malloc(STACK_INIT_SIZE * sizeof (char));
    if (! S->base) exit(0);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return 1;
}

int Push (SqStack *S, char c)
{  //入栈 
    char *p;
    if (S->top - S->base >= S->stacksize)
    {
       p = (char *)realloc(S->base, (S->stacksize + STACKINCEREMENT) * sizeof (char)) ;
       if (!p) exit(0);
       S->base = p;
       S->top = S->base + S->stacksize;
       S->stacksize += STACKINCEREMENT;
    }
    * S->top ++ = c;
    return 1; 
}

int Pop (SqStack *S,char *c)
{   //出栈 
    if (S->base == S->top)  return 0;
    *c = * --S->top;
    return 1;
}

// 对队列的操作 
int InitQueue (LinkQueue *Q)
{   //初始化队列 
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front) exit(0);
    Q->front->next = NULL;
    return 1;
}

int EnQueue (LinkQueue *Q, char c)
{   //入队列 
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) exit(0);
    p->data = c; p->next = NULL; 
    Q->rear->next = p; Q->rear = p;
    return 1;  
}

int DeQueue (LinkQueue *Q, char *c)
{   //出队列 
    QueuePtr p;
    if (Q->front == Q->rear)   return 0;
    p = Q->front->next;
    *c = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)   Q->rear = Q->front;
    free(p);
    return 1;
}

int DestroyQueue (LinkQueue *Q)
{   //销毁队列 
    while (Q->front)
    {
     Q->rear = Q->front->next;
     free(Q->front);
     Q->front = Q->rear;
    }
    return 1;
} 

//检查括号是否匹配的函数实现 
int Match (char *str)       //函数开始 
{    
    int j = 0;                         
    char *p1, c;
    SqStack Q;
    InitStack(&Q);
    for (p1 = str; *p1; p1 ++)
    {
       switch(*p1)
       {
           case '(':
                    Push(&Q,*p1);   
                    j ++;  break;
           case ')': 
                    if (Q.base  == Q.top) 
                       return 0;
                    Pop(&Q,&c); 
                    if (c != '(')
                       return 0;      
                    break;
           default :                  break;
       }
    }
   
    if (Q.base == Q.top && j)
    {
       free(Q.base );
       return 1;
    }
    else if (j == 0)
        return 1; 
    else 
    {
       free(Q.base );
       return 0; 
    }
} 