#include <stdio.h>
#include <malloc.h>
typedef struct MULTI{//定义多项式的存储结构 
	float _coef;
	int _expn;
	struct MULTI *next;
}Node,*Polynomial;
Polynomial p,q,r;
void sortpoly(Polynomial *l){//排列多项式 
	Polynomial pw,qw,rw;
	int c,i=0;
	float d;
	while(1){
	i=0;
	rw=*l;
	pw=rw->next;
	while(1){
	if(pw!=NULL)
	qw=pw->next;
	if(qw==NULL)
	break;
	if((pw->_expn)<(qw->_expn))
	{
	c=pw->_expn;
	pw->_expn=qw->_expn;	
	qw->_expn=c;
	d=pw->_coef;
	pw->_coef=qw->_coef;
	qw->_coef=d;
	i=1;
	}
	pw=qw;
	if(pw==NULL)
	break;
	}
	if(i==0)
	break;
	}
	}
void createPolynomial(Polynomial *L){//创建多项式 
	(*L) = (Polynomial)malloc(sizeof(Node));
	(*L)->next = NULL;
	r=(*L);
	float _coef; //多项式的系数
	int _expn,i=1;//多项式的指数
	printf("输入第1项：\n"); 
	scanf("%f %d",&_coef,&_expn);
//生成新节点；	
	while(_coef!=0){       
		i++; 
 		p = (Polynomial)malloc(sizeof(Node));
		p->next = NULL;
		p->_coef = _coef;
		p->_expn = _expn; 
		//把新节点已尾接法方式插入链表；
		r->next=p; r=p;
		printf("输入第%d项:\n",i);
		scanf("%f %d",&_coef,&_expn);
	}
}

void addPoly(Polynomial la,Polynomial lb,Polynomial *lc){//多项式加法 
	Polynomial pa,pb,pc;
	
	(*lc) = (Polynomial)malloc(sizeof(Node));//新生成了一个多结点 
	(*lc)->next = NULL; r=(*lc);
	
	pa=la->next; pb=lb->next;
	while((pa!=NULL)&&(pb!=NULL)){
		
		if(pa->_expn < pb->_expn){
			//复制lb的当前元素节点
			    pc=(Polynomial)malloc(sizeof(Node));
				pc->next=NULL;
				 pc->_expn=pb->_expn;
				 pc->_coef=pb->_coef; 
			//把新节点加入lc 
				r->next=pc; r=pc;
				pb=pb->next;
			
		}else if(pa->_expn == pb->_expn){
			//将两个系数相加和赋值给变量sum
			float sum=0;
			sum=pa->_coef+pb->_coef;
 
			if(sum!=0){
				//生成新节点并适当赋值；
				pc=(Polynomial)malloc(sizeof(Node));
				pc->next=NULL;
				pc->_coef=sum; pc->_expn=pa->_expn;
				//把新节点加入lc
				r->next=pc; r=pc;
			}
			pa=pa->next;pb=pb->next;
		}else if(pa->_expn > pb->_expn){
			//复制la的当前元素节点
			
			   pc=(Polynomial)malloc(sizeof(Node));
				pc->next=NULL;
				 pc->_expn=pa->_expn;
				 pc->_coef=pa->_coef;
			//把新节点加入lc 
			
				r->next=pc; r=pc;
				pa=pa->next;
		}
	}
	if(pa)
	pc->next=pa; 
	else if(pb)
	pc->next=pb;	
}
void printList(Polynomial l){//打印多项式 
	p=l->next;
	int i=0;
	while(p){
		i++;
		if(i==1)
		printf("%.1fx^%d",p->_coef,p->_expn);
		if(p->_coef>0&&i>1)
		printf("+%.1fx^%d",p->_coef,p->_expn);
		else if(p->_coef<0&&i>1)
		printf("%.1fx^%d",p->_coef,p->_expn);
		p=p->next;
	}
}
void oppositePolynomial(Polynomial *l){//多项式的系数取相反数 
	Polynomial p1=(*l)->next;
	while(p1){
		p1->_coef=-p1->_coef;
		p1=p1->next;
	}
}
void subPoly(Polynomial la,Polynomial lb,Polynomial *lc){//多项式减法 
	oppositePolynomial(&lb);
	addPoly(la,lb,lc);
/*
	Polynomial a;
	a=(*lc);
	for(;;)
	{
		if(a->next==NULL)
		{
		a->_coef=-a->_coef;
		break;
		}
		a=a->next;
	}*/
	oppositePolynomial(&lb);
}
float power(float a,int b){//离散指数函数 
	float c;
if(b<=0)
return 1;
else	
return power(a,b-1)*a;
}
float Polycalcu(Polynomial *l,float x){//计算多项式 
	Polynomial p1,q1,r1;
	int i;
	float sum=0;
	p1=(*l)->next;
	while(p1){
		sum=p1->_coef*power(x,p1->_expn)+sum;
		p1=p1->next; 
	}
	return sum;
} 
void d(Polynomial a,Polynomial *l)
{
	Polynomial m,n,o;
	(*l)=(Polynomial)malloc(sizeof(Node));
	(*l)->next=NULL;
	n=*l;
	m=a->next;
	while(m)
	{		
		o=(Polynomial)malloc(sizeof(Node));
		o->next=NULL;
		o->_expn=m->_expn-1;
		o->_coef=m->_coef*((float)m->_expn);
		m=m->next;
		n->next=o;n=o;		
	}
}
int main(){
	Polynomial la,lb,lc,ld,lf;
	float x,value;
	createPolynomial(&la);//输入两个多项式 la,lb
 	createPolynomial(&lb);
	sortpoly(&la);//排列多项式 
	sortpoly(&lb);
	printf("la:");//输出两个多项式la,lb 
	printList(la);
	printf("\nlb:");
	printList(lb);
	addPoly(la,lb,&lc);	//la+lb并存在lc中 
	printf("\nla+lb:");
	printList(lc);
	subPoly(la,lb,&ld);//la-lb并存在ld中 
	printf("\nla-lb:");
	printList(ld);
	d(la,&lf);//求la的导数并存在lf中 
	printf("\nla的导数：");
	printList(lf);
	printf("\n输入x的值:");//由输入的x来计算lc(la+lb)的值 
	scanf("%f",&x);
	value=Polycalcu(&lc,x);
	printf("当x=%.1f时，la+lb的值：%.1f\n",x,value);
	return 0;
}
 