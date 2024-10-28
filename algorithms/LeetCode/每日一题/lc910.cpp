#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        for(int i = 1; i < n; i ++) {
            // 必须变化一次，所以最大值最小值并非一定是排序后的头或尾
            int mx = max(nums[i - 1] + k, nums[n - 1] - k);
            int mn = min(nums[0] + k, nums[i] - k);
            ans = min(ans, mx - mn);
        }
        return ans;
    }
};