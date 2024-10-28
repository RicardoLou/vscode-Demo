#include <iostream>
using namespace std;

int i, X;

void sc(int *a, int n) {
    int x;
    printf("请输入数组：");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("请输入要查找的数字：");
    scanf("%d", &x);
    X = x;
}

void kp(int a[1000], int l, int r) {
    if (l >= r)
        return;
    int k = l;
    int p = a[l];//这样基准元素就会随着递归进行变
    while (l < r) {
        
        while (a[r] >= p && l < r)
            r--;
        // a[l] = a[r];
        swap(a[l], a[r]);
        while (a[l] <= p && l < r)
            l++;
        // a[r] = a[l];
        swap(a[r], a[l]);
    }
    a[l] = p;
    kp(a, l, k - 1);
    kp(a, k + 1, r);
}

int cz(int a[1000], int n) {
    int p;
    int l = 0;
    int r = n - 1;
    while (l <= r) {//如果l和r重合了说明也就找到了
        p = (l + r) / 2;
        if (a[p] == X)
            return p;//这里遇到等于其实可以直接return的，不需要break出去再return
        else if (a[p] >= X)
            r = p;
        else
            l = p + 1;
    }
    //在while里就可以处理完了，下面的if是可有可无的
    //if(a[p]!=X)
		// return 0;
	// else
	// return p;
    return -1; // 返回-1表示未找到
}

void pr(int a[1000], int n, int y) {
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
    if (y == -1)
        printf("未查找到此数！\n");
    else
        printf("%d在第%d个位置上\n", a[y], y + 1);
}

int main() {
    int a[1000], n, y;
    printf("请输入数组个数：");
    scanf("%d", &n);
    sc(a, n);
    kp(a, 0, n - 1);
    y = cz(a, n);
    pr(a, n, y);
    return 0;
}
