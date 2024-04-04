#include <stdio.h>
#include <malloc.h>
typedef struct MULTI{//�������ʽ�Ĵ洢�ṹ 
	float _coef;
	int _expn;
	struct MULTI *next;
}Node,*Polynomial;
Polynomial p,q,r;
void sortpoly(Polynomial *l){//���ж���ʽ 
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
void createPolynomial(Polynomial *L){//��������ʽ 
	(*L) = (Polynomial)malloc(sizeof(Node));
	(*L)->next = NULL;
	r=(*L);
	float _coef; //����ʽ��ϵ��
	int _expn,i=1;//����ʽ��ָ��
	printf("�����1�\n"); 
	scanf("%f %d",&_coef,&_expn);
//�����½ڵ㣻	
	while(_coef!=0){       
		i++; 
 		p = (Polynomial)malloc(sizeof(Node));
		p->next = NULL;
		p->_coef = _coef;
		p->_expn = _expn; 
		//���½ڵ���β�ӷ���ʽ��������
		r->next=p; r=p;
		printf("�����%d��:\n",i);
		scanf("%f %d",&_coef,&_expn);
	}
}

void addPoly(Polynomial la,Polynomial lb,Polynomial *lc){//����ʽ�ӷ� 
	Polynomial pa,pb,pc;
	
	(*lc) = (Polynomial)malloc(sizeof(Node));//��������һ������ 
	(*lc)->next = NULL; r=(*lc);
	
	pa=la->next; pb=lb->next;
	while((pa!=NULL)&&(pb!=NULL)){
		
		if(pa->_expn < pb->_expn){
			//����lb�ĵ�ǰԪ�ؽڵ�
			    pc=(Polynomial)malloc(sizeof(Node));
				pc->next=NULL;
				 pc->_expn=pb->_expn;
				 pc->_coef=pb->_coef; 
			//���½ڵ����lc 
				r->next=pc; r=pc;
				pb=pb->next;
			
		}else if(pa->_expn == pb->_expn){
			//������ϵ����Ӻ͸�ֵ������sum
			float sum=0;
			sum=pa->_coef+pb->_coef;
 
			if(sum!=0){
				//�����½ڵ㲢�ʵ���ֵ��
				pc=(Polynomial)malloc(sizeof(Node));
				pc->next=NULL;
				pc->_coef=sum; pc->_expn=pa->_expn;
				//���½ڵ����lc
				r->next=pc; r=pc;
			}
			pa=pa->next;pb=pb->next;
		}else if(pa->_expn > pb->_expn){
			//����la�ĵ�ǰԪ�ؽڵ�
			
			   pc=(Polynomial)malloc(sizeof(Node));
				pc->next=NULL;
				 pc->_expn=pa->_expn;
				 pc->_coef=pa->_coef;
			//���½ڵ����lc 
			
				r->next=pc; r=pc;
				pa=pa->next;
		}
	}
	if(pa)
	pc->next=pa; 
	else if(pb)
	pc->next=pb;	
}
void printList(Polynomial l){//��ӡ����ʽ 
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
void oppositePolynomial(Polynomial *l){//����ʽ��ϵ��ȡ�෴�� 
	Polynomial p1=(*l)->next;
	while(p1){
		p1->_coef=-p1->_coef;
		p1=p1->next;
	}
}
void subPoly(Polynomial la,Polynomial lb,Polynomial *lc){//����ʽ���� 
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
float power(float a,int b){//��ɢָ������ 
	float c;
if(b<=0)
return 1;
else	
return power(a,b-1)*a;
}
float Polycalcu(Polynomial *l,float x){//�������ʽ 
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
	createPolynomial(&la);//������������ʽ la,lb
 	createPolynomial(&lb);
	sortpoly(&la);//���ж���ʽ 
	sortpoly(&lb);
	printf("la:");//�����������ʽla,lb 
	printList(la);
	printf("\nlb:");
	printList(lb);
	addPoly(la,lb,&lc);	//la+lb������lc�� 
	printf("\nla+lb:");
	printList(lc);
	subPoly(la,lb,&ld);//la-lb������ld�� 
	printf("\nla-lb:");
	printList(ld);
	d(la,&lf);//��la�ĵ���������lf�� 
	printf("\nla�ĵ�����");
	printList(lf);
	printf("\n����x��ֵ:");//�������x������lc(la+lb)��ֵ 
	scanf("%f",&x);
	value=Polycalcu(&lc,x);
	printf("��x=%.1fʱ��la+lb��ֵ��%.1f\n",x,value);
	return 0;
}
 