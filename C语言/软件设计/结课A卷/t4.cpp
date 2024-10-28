#include<stdio.h>
#include<stdlib.h>
int dg[20], udg[20], c[20];
char g[20][20];
int n;
void dfs(int u, int n){
    if(u == n) {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                printf("%c",g[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    for(int i = 0; i < n; i ++) {
        if(c[i] == 0 && dg[n - u + i] == 0 && udg[u + i] == 0) {
            g[u][i] = 'Q';
            c[i] = dg[n - u + i] = udg[u + i] = 1;
            dfs(u + 1, n);
            c[i] = dg[n - u + i] = udg[u + i] = 0;
            g[u][i] = '.';
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = '.';
            }
        }
    dfs(0, n);
}