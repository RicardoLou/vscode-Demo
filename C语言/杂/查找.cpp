#include "stdio.h"
int i,X;
void sc(int *a,int n)
{
	int x;
	printf("请输入数组：");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("请输入要查找的数字：");
	scanf("%d",&x);
	X=x;
}
void kp(int a[1000],int l,int r)
{
	int k,p;
	if(l>r)
		return;
	k=0;p=a[k];
	while(l<r)
	{
		while(a[r]>a[k]&&l<r)
			r--;
			a[k]=a[r];
			k=r;
		while(a[l]<a[k]&&l<r)
			l++;
			a[k]=a[l];
			k=l;
	}
	a[k]=p;
	kp(a,l,r-1);
	kp(a,l,r);
}
int cz(int a[1000],int n)
{
	int l,r,p;
	l=0;r=n-1;
	while(l<r)
	{
		p=(l+r)/2;
		if(a[l]==X)
			break;
		if(a[p]>=X)
			r=p;
		else
			l=p+1;
	}
	if(a[p]!=X)
		return 0;
	else
	return p;
}
void pr(int a[1000],int n,int y)
{
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	if(y==0)
		printf("未查找到此数！\n");
		else
		printf("%d在第%d个位置上\n",a[y],y+1);
}
int main()
{
	int a[1000], n;
	int y;
	printf("请输入数组个数：");
	scanf("%d",&n);
	sc(a,n);
	kp(a,0,n-1);
	y=cz(a,n);
	pr(a,n,y);
}