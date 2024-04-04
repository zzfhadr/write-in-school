#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
 
//���Ķ���
typedef struct CSNode
{
	char data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
 
//�������Ķ���
typedef struct BTNode
{
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;
//�洢·������
typedef struct
{
	char path[100];
}Str;
 
//�ļ�ָ��
FILE* fp;
 
//����һ����
CSTree CreateCSTree()
{
	char ch;
	fscanf(fp, "%c", &ch);
	CSTree CT = NULL;
	if (ch != '0')
	{
		CT = (CSNode*)malloc(sizeof(CSNode));
		CT->data = ch;
		CT->firstchild = CreateCSTree();
		CT->nextsibling = CreateCSTree();
	}
	return CT;
}
//����һ�ö�����
BTNode* CreateBTree()
{
	char ch;
	BTNode* bt;
	scanf("%c",&ch);
	if(ch==' ')
	bt=NULL;
	else
	{
		bt=(BTNode*)malloc(sizeof(BTNode));
		if(!bt)
		return NULL;
		bt->data=ch;
		bt->lchild=CreateBTree();
		bt->rchild=CreateBTree();		
	}
	return bt;	
} 
//��ת���ɶ�����
BTNode* ExchangeToBTree(CSTree ct)
{
	if (ct == NULL)
		return NULL;
	else
	{
		BTNode * bt = (BTNode*)malloc(sizeof(BTNode));
		bt->data = ct->data;
		bt->lchild = ExchangeToBTree(ct->firstchild);
		bt->rchild = ExchangeToBTree(ct->nextsibling);
		return bt;
	}
}
 
//������ת������
CSTree ExchangeToCSTree(BTNode *bt)
{
	if (bt == NULL)
		return NULL;
	else
	{
		CSTree ct = (CSNode*)malloc(sizeof(CSNode));
		ct->data = bt->data;
		ct->firstchild = ExchangeToCSTree(bt->lchild);
		ct->nextsibling = ExchangeToCSTree(bt->rchild);
		return ct;
	}
}

//�������������
void preorder(BTNode* bt)
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}
 
//�������������
void inorder(BTNode* bt)
{
	if (bt != NULL)
	{
		inorder(bt->lchild);
		printf("%c", bt->data);
		inorder(bt->rchild);
	}
}
//�������������
void postorder(BTNode* bt)
{
	if (bt !=NULL)
	{
		postorder(bt->lchild);
		postorder(bt->rchild);
		printf("%c", bt->data);
	}	
} 
//�����������
void preorder_cstree(CSTree ct)
{
	if (ct != NULL)
	{
		printf("%c", ct->data);
		preorder_cstree(ct->firstchild);
		preorder_cstree(ct->nextsibling);
	}
}
int main()
{
	//�����������Ĵ�������ת��������������ת�� 
	CSTree F[2],tree1,tree2;
	Str ps[2] = { "C:\\CodeBlocksProject\\cstree1.txt","C:\\CodeBlocksProject\\cstree2.txt" };
	int length = 2;
	for (int i = 0; i < length; i++)
	{
		fp = fopen(ps[i].path, "r");
		F[i] = CreateCSTree();
		fclose(fp);
	}
	BTNode *a,*b;
	printf("�����������a:\n");
	a=CreateBTree();
	b=ExchangeToBTree(F[1]);
	printf("�ȸ�(a��b)��\n");
	preorder(a);
	printf("\n");
	preorder(b);
	printf("\n"); 
	printf("�и�(a��b)��\n");
	inorder(a);
	printf("\n");
	inorder(b);
	printf("\n");
	printf("���(a��b)��\n");
	postorder(a);
	printf("\n");
	postorder(b);
	printf("\n");
	tree1=ExchangeToCSTree(a);
	tree2=ExchangeToCSTree(b);
	printf("�����ȸ�(tree1��tree2)��\n");
	preorder_cstree(tree1);
	printf("\n");
	preorder_cstree(tree2); 
	printf("\n");
	
	
	
	//ABD G   CE  FH   ��ǰ�涼Ҫ�ո�ҲҪ�� 
	
	
	//ɭ��ת������
	//BTNode* bt = ForestToBTree(F, 0, length - 1); 
	//������תɭ��
	//Forest* F2;
	//F2 = BTreeToForest(bt);
	//inorder_forest(F2); 
	//��ɭ�ֵĵ���������������ǰ����������Դ�����ȷ��
	//preorder_cstree(F2->ct[0]);
 
 
	//����ע�͵��������ǶԴ���������ת��������������ת���Ĵ������
 
	//fp = fopen("C:\\CodeBlocksProject\\cstree.txt", "r");
	//CSTree ct = CreateCSTree();
	//preorder_cstree(ct);
	//BTNode* bt = ExchangeToBTree(ct);
	//CSTree ct2 = ExchangeToCSTree(bt);
	//preorder_cstree(ct2);
	//preorder(bt);
	//inorder(bt);
 
 
 
	return 0;
}