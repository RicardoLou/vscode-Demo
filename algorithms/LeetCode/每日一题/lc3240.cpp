#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;
        // 统计非中间行和中间列的最少变换次数
        for(int i = 0; i < n / 2; i ++) {
            for(int j = 0; j < m / 2; j ++) {
                int cnt1 = a[i][j] + a[i][m - 1 - j] + a[n - 1 - i][j] + a[n - 1 - i][m - 1 - j];
                ans += min(cnt1, 4 - cnt1);
            }
        }
        if(n % 2 && m % 2)
            ans += a[n / 2][m / 2];
        int dif = 0, cnt1 = 0;
        // 统计奇数行最中间这一行
        if(n % 2) {
            for(int i = 0; i < m / 2; i ++) {
                if(a[n / 2][i] != a[n / 2][m - 1 - i])
                    dif ++;
                else cnt1 += a[n / 2][i] * 2;
            }
        }
        // 统计奇数列最中间这一列
        if(m % 2) {
            for(int i = 0; i < n / 2; i ++) {
                if(a[i][m / 2] != a[n - 1 - i][m / 2])
                    dif ++;
                else cnt1 += a[i][m / 2] * 2;
            }
        }
        // 有不一样的肯定要修改，没有不一样的话要看1的个数，如果此时1无法被4整除，那么就要加上2，反之加0
        return ans + (dif ? dif : cnt1 % 4);
    }
};