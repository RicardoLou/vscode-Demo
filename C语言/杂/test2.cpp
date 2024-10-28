#include <stdio.h>
#include<iostream>
using namespace std;
int m , num = 1;
void sort(int *a,int n)
{
	int i , j , t;
	
	for(i = 0 ; i < n ; i++)
	for(j = i ; j < n ; j++)
	if(a[i] > a[j])
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;	
	}
	printf("排序后：");
	for(i = 0 ; i < n ; i++)
	printf("%d " , a[i]);
}

void serch(int *a,int n, int m)
{
	int l = 0, r = n-1, mid;
	
	while(l < r)//此处是问题，这个循环
	{   mid = l + r >> 1;
        if(a[mid] == m) {
            printf("成功找出，是第%d位学生，共查找%d次\n" , mid + 1, num);
            return;
        }
		printf("折半查找法，第%d次排序未找出,中间值为%d\n" , num++ , a[mid]);
		if(a[mid] >= m) r = mid;
		else  l = mid + 1;
	}
        printf("输入成绩不在学生之列，共查找%d次" , num);
}

int main()
{
	int a[5];
	int i;
	
	for(i = 0 ; i < 5 ; i++)
	scanf("%d" , &a[i]);
	
	sort(a , 5);
	
	printf("\n请输入要查找的学生：");
	scanf("%d" , &m);//全局变量"m" 
	serch(a, 5, m);
}