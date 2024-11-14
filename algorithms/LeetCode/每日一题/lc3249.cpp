#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    int dfs(vector<vector<int>>& g, int x, int p) {
        int size = 1;
        int first = 0;
        bool flag = true;
        for(auto a : g[x]) {
            // 不能往回走
            if(a == p)
                continue;
            
            int son = dfs(g, a, x);
            if(first == 0) {
                first = son;
            } else if(son != first) {
                // 说明有子树大小不一样了。
                flag = false;
            }
            size += son;
        }
        ans += flag;
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // n条边就有n + 1 个节点
        vector<vector<int>> g(n);
        for(int i = 0; i < n - 1; i ++) {
            int a = edges[i][0], b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(g, 0, -1);
        return ans;
    }
};