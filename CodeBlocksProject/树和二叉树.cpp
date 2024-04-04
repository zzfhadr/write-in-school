#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
 
//树的定义
typedef struct CSNode
{
	char data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
 
//二叉树的定义
typedef struct BTNode
{
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;
//存储路径定义
typedef struct
{
	char path[100];
}Str;
 
//文件指针
FILE* fp;
 
//创建一棵树
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
//创建一棵二叉树
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
//树转换成二叉树
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
 
//二叉树转换成树
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

//二叉树先序遍历
void preorder(BTNode* bt)
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}
 
//二叉树中序遍历
void inorder(BTNode* bt)
{
	if (bt != NULL)
	{
		inorder(bt->lchild);
		printf("%c", bt->data);
		inorder(bt->rchild);
	}
}
//二叉树后序遍历
void postorder(BTNode* bt)
{
	if (bt !=NULL)
	{
		postorder(bt->lchild);
		postorder(bt->rchild);
		printf("%c", bt->data);
	}	
} 
//树的先序遍历
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
	//用来测试树的创建、树转二叉树、二叉树转树 
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
	printf("请输入二叉树a:\n");
	a=CreateBTree();
	b=ExchangeToBTree(F[1]);
	printf("先根(a和b)：\n");
	preorder(a);
	printf("\n");
	preorder(b);
	printf("\n"); 
	printf("中根(a和b)：\n");
	inorder(a);
	printf("\n");
	inorder(b);
	printf("\n");
	printf("后根(a和b)：\n");
	postorder(a);
	printf("\n");
	postorder(b);
	printf("\n");
	tree1=ExchangeToCSTree(a);
	tree2=ExchangeToCSTree(b);
	printf("树的先根(tree1和tree2)：\n");
	preorder_cstree(tree1);
	printf("\n");
	preorder_cstree(tree2); 
	printf("\n");
	
	
	
	//ABD G   CE  FH   好前面都要空格也要。 
	
	
	//森林转二叉树
	//BTNode* bt = ForestToBTree(F, 0, length - 1); 
	//二叉树转森林
	//Forest* F2;
	//F2 = BTreeToForest(bt);
	//inorder_forest(F2); 
	//对森林的第三棵树进行树的前序遍历，测试代码正确性
	//preorder_cstree(F2->ct[0]);
 
 
	//下面注释掉的内容是对创建树、树转二叉树、二叉树转树的代码测试
 
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