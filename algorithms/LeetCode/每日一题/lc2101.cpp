#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<bool> st, vector<vector<int>> g, int u) {
        st[u] = true;
        int cnt = 1;
        for(int x : g[u]) {
            if(!st[x]) {
                cnt += dfs(st, g, x);
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i ++) {
            long x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
            for(int j = 0; j < n; j ++) {
                long long dx = x - bombs[j][0];
                long long dy = y - bombs[j][1];
                //计算圆心之间绝对值距离
                if(i != j && dx * dx + dy * dy <= r * r) {
                    g[i].push_back(j);
                }
            }
        }
        int ans = 0;
        vector<bool> st(n);

        auto dfs2 = [&](auto&& dfs, int x) -> int {
            st[x] = true;
            int cnt = 1;
            for (int y : g[x]) {
                if (!st[y]) {
                    cnt += dfs(dfs, y);
                }
            }
            return cnt;
        };


        for(int i = 0; i < n; i ++) {
            //恢复状态
            ranges::fill(st, false);
            ans = max(ans, dfs2(dfs2, i));
        }
        return ans;
    }
};