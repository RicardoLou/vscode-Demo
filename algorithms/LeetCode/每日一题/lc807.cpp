#include<bits/stdc++.h>
using namespace std;
//https://leetcode.cn/problems/max-increase-to-keep-city-skyline/
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rmin(n), cmin(m);
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                rmin[i] = max(rmin[i], grid[i][j]);
                cmin[j] = max(cmin[j], grid[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                ans += min(rmin[i], cmin[j]) - grid[i][j];
            }
        }
        return ans;
    }
};