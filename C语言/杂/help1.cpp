#include<stdio.h>
#define MAXSIZE 100
using namespace std;

typedef struct{
	int data[MAXSIZE];
}ElemType;

typedef struct{
	ElemType *elem;
	int length;
}sqList;

void insertElem(sqList &L,int p,int e)
{
	int i;
	if(p<0||p>L.length||L.length==MAXSIZE)
	{
		for(i=L.length-1;i>=p;i--)
			L.elem[i+1]=L.elem[i];
		L.length=L.length+1;
	}
}
int InitList(sqList &L)
{
	L.elem=new ElemType[MAXSIZE];

}
int main()
{
	int i,p,e;
	sqList L;
    InitList(L);
	scanf("%d%d%d",&L.length,&p,&e);
	for(i=0;i<L.length;i++)
	scanf("%d",&L.elem[i].data[i]);
	insertElem(L,p,e);
	for(i=0;i<L.length;i++)
		printf("%d  ",L.elem[i].data[i]);
	return 0;
}