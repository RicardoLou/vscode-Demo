#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class Solution {
public:
    int INI_MAX = 1e9 + 7;
    vector<int> duration = {1, 7, 30};
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), INI_MAX);
        return f(dp, days, costs, 0);
    }
    int f(vector<int>& dp, vector<int>& days, vector<int>& costs, int i) {
        if (i == days.size()) {
            return 0;
        }
        if (dp[i] != INI_MAX) {
            return dp[i];
        }
        int ans = INI_MAX;
        for (int j = i, k = 0; k < 3; k ++) {
            // 看最远可以走到哪一天
            while (j < days.size() && days[i] + duration[k] > days[j]) {
                j ++;
            }
            // 计算花费
            ans = min(ans, costs[k] + f(dp, days, costs, j));
        }
        // 记忆化
        dp[i] = ans;
        return ans;
    }
};