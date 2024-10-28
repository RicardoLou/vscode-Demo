#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ans = nums[n - 1] - nums[0] - 2 * k;
        return ans >= 0 ? ans : 0;
    }
};