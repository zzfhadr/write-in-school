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
int Match (char *str);  // 判断括号是否匹配或者无括号 
void Medal (SqStack *S, SqStack *S1); // 最后处理 


int main ()
{
    int i;
    char ch, ch1, middle, str[1000] = {0};
    SqStack Devil, S1; 
    LinkQueue temp;
    InitStack (&Devil);
    InitStack (&S1);
    InitQueue (&temp);
    scanf("%s", str);

    if ( Match(str) )
    {
        for (i = ( strlen(str) - 1 ); i >= 0; -- i)
            Push(&Devil, str[i]);

        while(Devil.base != Devil.top)
        {
            Pop(&Devil, &ch);
            if (ch != ')')
               Push(&S1, ch);
            else if(ch == ')')
            {
                while (S1.base != S1.top )
                {
                   Pop(&S1, &ch1);
                   if (ch1 != '(')
                   {
                      EnQueue (&temp, ch1);
                      middle = ch1;
                   }
                   else   break;
                }

                while (temp.front->next != temp.rear)
                {
                    DeQueue (&temp, &ch1);
                    Push (&S1, middle);
                    Push (&S1, ch1);
                }

                DeQueue (&temp, &ch1);
                Push (&S1, ch1);
            }
        }
        Medal (&Devil, &S1);
        while ( Pop(&Devil,&ch) )
            printf ("%c", ch);

        free(Devil.base);
        free(S1.base);
        DestroyQueue(&temp);
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
    if (S->top-S->base>= S->stacksize)
    {
       p = (char *)realloc(S->base,(S->stacksize + STACKINCEREMENT) * sizeof (char)) ;
       if (!p) exit(0);
       S->base = p;
       S->top = S->base + S->stacksize;
       S->stacksize += STACKINCEREMENT;
    }
    * S->top++=c;
    return 1; 
}

int Pop (SqStack *S,char *c)
{   //出栈 
    if (S->base==S->top)  return 0;
    *c=*--S->top;
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
    int judge = 0;                         
    char *p1, c;
    SqStack Q;
    InitStack(&Q);
    for (p1 = str; *p1; p1 ++)
    {
       switch(*p1)
       {
           case '(':
                    Push(&Q,*p1);   
                    judge ++;  break;
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
   
    if (Q.base == Q.top && judge)
    {
       free(Q.base );
       return 1;
    }
    else if (judge == 0)
        return 1; 
    else 
    {
       free(Q.base );
       return 0; 
    }
} //函数结束 

// 最后处理 
void Medal (SqStack *S, SqStack *S1)
{
    char ch, B[9] = "tsaedsae", A[4] = "sae";
    int i = 0;
    while(S1->base != S1->top)
    {
        Pop (S1, &ch);
        switch (ch)
        { 
            case 'A': 
                 for (i = ( strlen(A) - 1 ); i >= 0; -- i)
                     Push(S, A[i]);
                 break;
            case 'B': 
                 for (i = ( strlen(B) - 1 ); i >= 0; -- i)
                     Push(S, B[i]);
                 break;
            default : Push(S, ch);  break;
       }
    }  
}
