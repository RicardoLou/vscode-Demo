#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> from(n);
        vector<int> f(n);
        for(int i = 0; i < n; i ++) {
            f[i] = i;
        }
        vector<int> ans(queries.size());
        for(int q = 0; q < queries.size(); q++) {
            int a = queries[q][0], b = queries[q][1];
            from[b].push_back(a);
            // 更短
            if (f[a] + 1 < f[b]) {
                f[b] = f[a] + 1;
                // 更新后面的
                for(int i = b + 1; i < n; i ++) {
                    f[i] = min(f[i], f[i - 1] + 1);
                    // 检查是否有其他的路径
                    for(int x : from[i]) {
                        f[i] = min(f[i], f[x] + 1);
                    }
                }
            }
            ans[q] = f[n - 1];
        }
        return ans;
    }
};