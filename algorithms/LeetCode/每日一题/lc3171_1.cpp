#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i ++) {
            int x = nums[i];
            ans = min(ans, abs(x - k));
            for (int j = i - 1; j >= 0 && (nums[j] | x) != nums[j]; j --) {
                nums[j] |= x;
                ans = min(ans, abs(nums[j] - k));
            }
        }
        return ans;
    }
};