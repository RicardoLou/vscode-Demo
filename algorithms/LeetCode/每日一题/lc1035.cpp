#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& vis) {
        if(i < 0 || j < 0)
            return 0;
        if(vis[i][j] != -1)
            return vis[i][j];
        if(nums1[i] == nums2[j]) {
            return vis[i][j] = dfs(i - 1, j - 1, nums1, nums2, vis) + 1;
        }
        return vis[i][j] = max(dfs(i - 1, j, nums1, nums2, vis), dfs(i, j - 1, nums1, nums2, vis));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        //初始化全部为-1
        vector<vector<int>> vis(n, vector<int>(m, -1));
        return dfs(n - 1, m - 1, nums1, nums2, vis);
    }
};