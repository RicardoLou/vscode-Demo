#include<iostream>
using namespace std;

const int N = 1010;
int a[N][N];
int s[N][N];
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int j = 1; j <= n; j ++) {
        for (int i = 1; i <= m; i++)
        {
            cin >> a[j][i];
            s[j][i] = s[j - 1][i] + s[j][i - 1] - s[j - 1][i - 1] + a[j][i];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int res = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
        cout << res << endl;
    }
    return 0;
}