#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int N = 110;
char g[N][N];
bool marked[N][N]; // 用于标记已匹配的字符
int n;
char target[] = {'y', 'i', 'z', 'h', 'o', 'n', 'g'};
vector<pair<int, int> > start;

int offset[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, 1}, {1, -1}, {0, -1}};

bool checkAndMark(int x, int y, int dir) {
    int dx = x, dy = y;
    // 判断是否可以连续成target串
    for (int j = 0; j < 7; j++) {
        if (dx < 0 || dx >= n || dy < 0 || dy >= n || g[dx][dy] != target[j]) {
            return false;
        }
        dx += offset[dir][0];
        dy += offset[dir][1];
    }
    // 如果匹配成功，标记路径
    dx = x;
    dy = y;
    for (int j = 0; j < 7; j++) {
        marked[dx][dy] = true;
        dx += offset[dir][0];
        dy += offset[dir][1];
    }
    return true;
}

void dfs(int x, int y) {
    // 走八个方向
    for (int i = 0; i < 8; i++) {
        if (checkAndMark(x, y, i)) {
            return; // 找到一个方向匹配后直接返回
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            g[i][j] = c;
            if (c == 'y') {
                start.push_back(make_pair(i, j));
            }
        }
    }
    // 对于每个起点y开始寻找正确路径
    for (int i = 0; i < start.size(); i++) {
        dfs(start[i].x, start[i].y);
    }
    // 输出结果，未标记的字符替换为 '*'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!marked[i][j]) {
                cout << '*';
            } else {
                cout << g[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
