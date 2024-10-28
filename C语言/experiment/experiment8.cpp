#include<stdlib.h>
#include<stdio.h>
struct TREE
{
	int data;
	TREE *L,*R;
};
void NewNode(int value);
void Insert(TREE *&Root,TREE *Node);
void preorder(TREE *Node);
void inorder(TREE *Node);
void postorder(TREE *Node);
void floororder(TREE *Node);
TREE *pRoot;//定义根结点
int main()
{
	int n, t;
	pRoot=NULL;
	printf("输入节点个数:");
	scanf("%d", &n);
	if(n) {
		printf("输入各个节点值:");
		while(n--)
		{
			scanf("%d", &t); 
			NewNode(t);
		}
	}
	if(!pRoot)
		printf("Empty tree\n");
	else						//如果树非空,输出各种遍历
	{
		printf("先序遍历: ");
		preorder(pRoot);
		printf("\n");	
		printf("中序遍历: ");
		inorder(pRoot);
		printf("\n");
		printf("后序遍历: ");
		postorder(pRoot);
		printf("\n");
		printf("层序遍历: ");
		floororder(pRoot);
	}
	return 0;
}
void NewNode(int value)				//向树中加入一个新结点
{
	TREE *pNode=(struct TREE *)malloc(sizeof(TREE));//为待插入结点分配内存单元
	pNode->data=value;
	pNode->L=NULL;
	pNode->R=NULL;
	Insert(pRoot,pNode);//将该结点插入到二叉树中
}
void Insert(TREE *&Root,TREE *Node)			//结点插入过程
{
	if(Root==NULL)//如果根结点为空
	{
		Root = Node;//将结点插入到根结点
		return;//返回
	}
	else
	{
		if(Root->data>=Node->data)//如果Node结点数据小于等于根结点数据
			Insert(Root->L,Node);//插入左子树
		else
			Insert(Root->R,Node);//否则插入右子树
	}
}
void preorder(TREE *Node)		//输出前序遍历
{
	if(Node!=NULL)
	{
		printf("%d ",Node->data);
		preorder(Node->L);
		preorder(Node->R);
	}
}
void inorder(TREE *Node)		//输出中序遍历
{
	if(Node!=NULL)
	{
		inorder(Node->L);
		printf("%d ",Node->data);
		inorder(Node->R);
	}
}
void postorder(TREE *Node)		//输出后序遍历
{
	if(Node!=NULL)
	{
		postorder(Node->L);
		postorder(Node->R);
		printf("%d ", Node->data);
	}
}
void floororder(TREE *Node)		//宽度优先搜索输出层序遍历
{
	if(Node == NULL) return;		//如果树为空,返回
	TREE *p[100];
	int q1, q2, q3, i;
	p[0] = Node;
	q1 = q2 = 0;
	while(q1 <= q2)
	{
		q3 = q2 + 1; 
		for(i = q1; i < q3; i++)
		{
			printf("%d ", p[i]->data);
			if(p[i]->L != NULL) p[++q2] = p[i]->L;
			if(p[i]->R != NULL) p[++q2] = p[i]->R;
		}
		q1 = q3;
	}
	printf("\n");
 
}
