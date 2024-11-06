#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1, -1);
        for(int i = 0; i < nums.size() - k + 1; i ++) {
            bool flag = true;
            for(int j = i; j < i + k - 1; j ++) {
                if (nums[j + 1] - nums[j] != 1) {
                    flag = false;
                }
            }
            if (flag)
                ans[i] = nums[i + k - 1];
            else ans[i] = -1;
        }
        return ans;
    }
};