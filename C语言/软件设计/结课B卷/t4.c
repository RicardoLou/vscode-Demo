#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int w[1010], v[1010];//重量和价值
int dp[1010];
int max(int a, int b) {
    if(a > b) return a;
    else return b;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d %d",&w[i], &v[i]);
    for(int i = 0; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf("%d", dp[m]);
    return 0;
}