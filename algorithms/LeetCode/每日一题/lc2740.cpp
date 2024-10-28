#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i = 0; i < nums.size() - 1; i ++) {
            ans = min(ans, abs(nums[i] - nums[i + 1]));
        }
        return ans;
    }
};