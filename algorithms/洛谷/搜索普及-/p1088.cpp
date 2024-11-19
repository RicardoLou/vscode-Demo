#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10010];
int main()
{
    cin >> n >> m;
    int tot = 1;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[i] = x;
        tot *= i;
    }
    for (int i = 1; i <= m; ++i)
    {

        next_permutation(a + 1, a + n + 1);
    }
    for (int j = 1; j <= n; ++j)
        printf("%d ", a[j]); // 输出格式注意
    return 0;
}