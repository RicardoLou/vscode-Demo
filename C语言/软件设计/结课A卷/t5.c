#include<stdio.h>
#include<stdlib.h>
int main() {
    int n, a = 0;
    scanf("%d",&n);
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= n / 5; j ++) {
            for(int k = 0; k <= n / 10; k ++) {
                for(int p = 0; p <= n / 20; p ++) {
                    if(p * 20 + k * 10 + j * 5 + i == n){
                        printf("1元：%d 5元：%d 10元：%d 20元：%d\n",i,j,k,p);
                        return 0;
                    }
                }
            }
        }
    }
}