#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> s(nums.size());
        for(int i = 1; i < nums.size(); i ++) {
            s[i] = s[i - 1] + ((nums[i] + nums[i - 1]) % 2 == 0);
        }
        vector<bool> ans(queries.size());
        for(int i = 0; i < ans.size(); i ++) {
            ans[i] = (s[queries[i][0]] == s[queries[i][1]]);
        }
        return ans;
    }
};