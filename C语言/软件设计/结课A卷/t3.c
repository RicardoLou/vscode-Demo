#include<stdio.h>
#include<stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int res = 0;
    if(n == 1) res = 1;
    else res = n / 2 + 1;
    printf("%d\n", res);
}