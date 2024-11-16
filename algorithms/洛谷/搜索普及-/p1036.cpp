#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int g[N];
int n, k;
bool st[N];
long long ans = 0;
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void dfs(int u, int start, int sum) {
    if (u == k) {
        // 满足后判断是否为素数
        if (isPrime(sum)) {
            ans++;
        }
        return;
    }
    for (int i = start; i < n; i++) {
        dfs(u + 1, i + 1, sum + g[i]);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}