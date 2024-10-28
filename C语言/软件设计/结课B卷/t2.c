#include<stdio.h>
#include<stdlib.h>
int gcd(int a, int b) {
    return  b == 0 ? a : gcd(b, a % b);
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int lcm = a / gcd(a, b) * b;
    printf("最大公约数:%d\n最小公倍数:%d", gcd(a, b), lcm);
}