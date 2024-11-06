#include<bits/stdc++.h>
using namespace std;

const int N = 11;
int n, k;
string path;
bool st[N][N], edge[N][N][N][N];
int g[N][N];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool dfs(int a, int b) {
    // 走到头的时候要看是否全部走到了，因为从起点出发，所以少走一步
    if (a == n - 1 && b == n - 1) return path.length() == n * n - 1;
    st[a][b] = true;
    for(int i = 0; i < 8; i ++) {
        int x = a + dx[i], y = b + dy[i];
        if(x < 0 || x >= n || y < 0 || y >= n) continue;
        if(st[x][y]) continue;
        // edge[a][y][x][b]:右上到左下
        // edge[x][b][a][y]:左下到右上
        if(i % 2 != 0 && (edge[a][y][x][b] || edge[x][b][a][y])) continue;
        // 是连续的
        if(g[x][y] != (g[a][b] + 1) % k) continue;
        edge[a][b][x][y] = true;
        path += i + '0';

        if(dfs(x, y)) return true;

        // 恢复现场
        path.pop_back();
        edge[a][b][x][y] = false;
    }
    st[a][b] = false; // 恢复现场
    return false;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> g[i][j];
        }
    }
    if(!dfs(0, 0)) cout << -1;
    else cout << path;
    return 0;
}