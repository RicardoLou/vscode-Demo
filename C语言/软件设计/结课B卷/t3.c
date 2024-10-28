#include<stdio.h>
int n, x;
int q[1000];

void quick_sort(int q[],int l,int r)
{
    if(l>=r)return;

    int x=q[(l+r)/2];
    int i=l-1;
    int j=r+1;

    while(i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);

        if(i<j)
        {
            int temp=q[i];
            q[i]=q[j];
            q[j]=temp;
        }
    }

    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}
int serch(int a[], int n, int x) {
    int l=0;
    int r=n-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[mid]==x)return mid;
        else if(a[mid]>x)r=mid;
        else l=mid+1;
    }
    if(a[l] != x) return -1;
    return l;
}
int main()
{
    scanf("%d %d",&n, &x);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",q[i]);
    }
    int res = serch(q, n, x);
    printf("\n%d", res + 1);
    return 0;
}