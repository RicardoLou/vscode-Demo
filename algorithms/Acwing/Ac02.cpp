#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int dp[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int w, v;
        cin >> w >> v;
        for(int j = m; j >= w; j --) {
            // max(不选这个，选这个 当前容量减掉当前选的这个的重量，加上价值)
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[m] << endl;
}