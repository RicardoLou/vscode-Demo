#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1, -1);
        int cnt = 0;
        for(int i = 0 ; i < nums.size(); i ++) {
            cnt = i == 0 || nums[i] == nums[i - 1] + 1 ? cnt + 1 : 1;
            if(cnt >= k) {
                ans[i - k + 1] = nums[i];
            }
        }
        return ans;
    }
};