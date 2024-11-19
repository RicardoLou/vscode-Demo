#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>& g, int n) {
        int step = 0;
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        while(!q.empty()) {
            int size = q.size();
            for(int j = 0; j < size; j ++) {
                int x = q.front();
                q.pop();
                if(x == n - 1)
                    return step;
                for(int t : g[x]) {
                    if(!vis[t]) {
                        vis[t] = true;
                        q.push(t);
                    }
                }
            }
            step ++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n - 1);
        for(int i = 0; i < n - 1; i ++) {
            g[i].push_back(i + 1);
        }
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i ++) {
            g[queries[i][0]].push_back(queries[i][1]);
            ans[i] = bfs(g, n);
        }
        return ans;
    }
};