#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX));
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                int mn = min(f[i + 1][j], f[i][j + 1]);
                ans = max(ans, grid[i][j] - mn);
                f[i + 1][j + 1] = min(mn, grid[i][j]);
            }
        }
        return ans;
    }
};