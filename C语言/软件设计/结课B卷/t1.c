#include<stdio.h>
#include<stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    //斐波那契
    int a[n];
    a[0] = 1;
    a[1] = 2;
    for(int i = 2; i < n; i++)
        a[i] = a[i-1] + a[i-2];
    
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;

}